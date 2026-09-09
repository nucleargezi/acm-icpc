#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"

using T = M11;
binom<T> C;

void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  if (K == 1) return print(0);
  sort(a);
  vc<T> f(N + 1 - K);
  FOR(i, K, N + 1) f[i - K] = C(i - 2, K - 2);
  T s;
  vc<T> c(all(a));
  c = pre_sum(c);
  FOR(n, K, N + 1) s += f[n - K] * (c[N] - c[n - 1] - c[N - n + 1]);
  print(s);
}

int main() { Yorisou(); }