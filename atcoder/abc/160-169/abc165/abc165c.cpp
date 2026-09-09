#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M, Q);
  ll s = 0;
  VEC(T4<int>, q, Q);
  for (Z &[a, b, c, d] : q) --a, --b;
  vc<int> a(N);
  Z f = [&](Z &f, int i, int ls) -> void {
    if (i == N) {
      ll ss = 0;
      for (var [i, k, c, d] : q) if (a[k] - a[i] == c) ss += d;
      chmax(s, ss);
      return;
    }
    FOR(k, ls, M + 1) a[i] = k, f(f, i + 1, k);
  };
  f(f, 0, 1);
  print(s);
}

int main() { Yorisou(); }