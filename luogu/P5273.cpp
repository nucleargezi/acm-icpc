#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/math/poly/fps_log.hpp"
#include "YRS/math/poly/fps_pow.hpp"

// #define tests
using mint = M99;
constexpr int mod = mint::get_mod();
using M2 = modint<mod - 1>;
vector<mint> power(vector<mint> f, int k1, int k2) {
  const int N = len(f);
  int sh = 0;
  while (sh < N and f[sh] == 0) ++sh;
  if (1ll * sh * k1 > N) return vector<mint>(N, 0);
  mint u = mint(f[sh]).inv(), v = mint(f[sh]).pow(k2);
  FOR(i, N - sh) f[i] = f[i + sh] * u;
  FOR(i, N - sh, N) f[i] = 0;
  f = fps_log(f);
  f.resize(N);
  FOR(i, 1, N) f[i] *= k1;
  f = fps_exp(f);
  sh *= k1;
  FOR_R(i, N - sh) f[i + sh] = f[i] * v;
  FOR(i, sh) f[i] = 0;
  return f;
}
void Yorisou() {
  INT(N);
  STR(s);
  for (Z &c : s) c -= '0';
  mint k1;
  M2 k2;
  for (int c : s) {
    k1 = k1 * 10 + c;
    k2 = k2 * 10 + c;
  }
  int k3 = 0, sz = len(s);
  FOR(i, std::min(6, sz)) k3 = 10 * k3 + s[i];
  VEC(mint, a, N);
  if (a[0] == 0 and k3 >= N) {
    fill(all(a), 0);
    return print(a);
  }
  print(power(a, k1.val, k2.val));
}
#include "YRS/Z_H/main.hpp"