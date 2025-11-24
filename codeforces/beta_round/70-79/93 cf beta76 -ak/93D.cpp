#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/math/line/mat.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M17;
using MT = matrix<mint>;
bool o(int a, int b) {
  if (a == b) return 0;
  if ((a == 2 and b == 3) or (a == 3 and b == 2)) return 0;
  if ((a == 1 and b == 0) or (a == 0 and b == 1)) return 0;
  return 1;
}
bool o(int a, int b, int c) {
  if (not o(a, b) or not o(b, c)) return 0;
  if (a == 0 and b == 2 and c == 1) return 0;
  if (a == 1 and b == 2 and c == 0) return 0;
  return 1;
}
MT v(17);
mint c[17];
mint ff(int x) {
  if (x < 2) return x == 1 ? 4 : 0;
  MT m = v.pow(x - 2);
  mint r;
  FOR(i, 17) r += m[16][i] * c[i];
  return r + 4;
}
mint f(int x) {
  if (x <= 0) return 0;
  return (ff(x) + ff((x + 1) / 2)) / 2;
}
void Yorisou() {
  FOR(a, 4) FOR(b, 4) FOR(c, 4) if (o(a, b, c)) 
    v[b * 4 + c][a * 4 + b] = 1;
  FOR(i, 16) FOR(k, 16) v[16][i] += v[k][i];
  v[16][16] = 1;
  FOR(a, 4) FOR(b, 4) if (o(a, b)) c[a * 4 + b] += 1;
  FOR(i, 16) c[16] += c[i];
  INT(l, r);
  print(f(r) - f(l - 1));
}
#include "YRS/Z_H/main.hpp"