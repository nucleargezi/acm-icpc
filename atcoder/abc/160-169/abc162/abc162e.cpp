#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/pr/conv_gcd.hpp"

using T = M11;

void Yorisou() {
  INT(N, K);
  vc<T> f(K + 1, 1);
  f[0] = 0;
  vc<T> g(f);
  multi_mobius(g);
  for (; N; N >>= 1, f = conv_gcd(f, f)) if (N & 1) g = conv_gcd(g, f);
  T s;
  FOR(i, 1, K + 1) s += g[i] * i;
  print(s);
}

int main() { Yorisou(); }