#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"
#include "YRS/po/f/stiling_2.hpp"
#include "YRS/po/prod_of_one_minus_xn.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void s1(int N, int M) { print(mint(M).pow(N)); }
void s2(int N, int M) { print(CC(M, N) * fac(N)); }
void s3(int N, int M) { print(stiling_2_n<mint>(N, M)[M] * fac(M)); }
void s4(int N, int M) {
  mint s = 0;
  vc<mint> f = stiling_2_n<mint>(N, M);
  FOR(i, 1, min(N, M) + 1) s += f[i];
  print(s);
}
void s5(int N, int M) { print(M >= N ? 1 : 0); }
void s6(int N, int M) { print(stiling_2_n<mint>(N, M)[M]); }
void s7(int N, int M) { print(CC(N + M - 1, M - 1)); }
void s8(int N, int M) { print(CC(M, N)); }
void s9(int N, int M) { print(CC(N - 1, M - 1)); }
void s10(int N, int M) {
  vc<int> f(M);
  iota(all(f), 1);
  print(prod_of_inv_one_minus_xn<mint>(f, N)[N]);
}
void s11(int N, int M) { print(M >= N); }
void s12(int N, int M) {
  vc<int> f(M);
  iota(all(f), 1);
  print(N < M ? 0 : prod_of_inv_one_minus_xn<mint>(f, N - M)[N - M]);
}
void Yorisou() {
  INT(N, M);
  s1(N, M);
  s2(N, M);
  s3(N, M);
  s4(N, M);
  s5(N, M);
  s6(N, M);
  s7(N, M);
  s8(N, M);
  s9(N, M);
  s10(N, M);
  s11(N, M);
  s12(N, M);
}
#include "YRS/aa/main.hpp"