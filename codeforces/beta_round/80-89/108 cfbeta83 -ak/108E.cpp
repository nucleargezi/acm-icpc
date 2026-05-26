#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/seq/kth_permutation.hpp"

void Yorisou() {
  INT(N);
  LL(K);
  INT(M);
  kth_permutation g(N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    g.ae(a, b);
  }

  Z s = g.kth(K - 2001);
  if (s) {
    vc<int> v = *s;
    for (int &x : v) ++x;
    print(v);
  } else {
    print("The times have changed");
  }
}

int main() {
  Yorisou();
  return 0;
}