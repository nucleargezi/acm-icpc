#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/01/vec_sp.hpp"

void Yorisou() {
  INT(N);
  vec_sp<ll, 55> g;
  FOR(N) {
    LL(x);
    g.add(x);
  }

  INT(Q);
  FOR(Q) {
    LL(k);
    k -= g.sz < N;
    print(g.kth(k));
  }
}

int main() {
  Yorisou();
  return 0;
}