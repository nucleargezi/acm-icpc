#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"

using T = M11;

void Yorisou() {
  map<PLL, int> mp;
  INT(N);
  FOR(N) {
    LL(a, b);
    ll g = gcd(a, b);
    if (g) a /= g, b /= g;
    if ((a < 0 and b < 0) or (a < 0 and b > 0)) a = -a, b = -b;
    ++mp[{a, b}];
  }
  T s = 1;
  ll d = 0, x = 0, y = 0;
  vc<PLL> go;
  for (var [f, c] : mp) {
    var [a, b] = f;
    if (a == 0 or b == 0) {
      if (a == 0 and b == 0) d += c;
      else (a == 0 ? x : y) += c;
      continue;
    }
    if (a > 0 and b > 0) {
      int d = mp.contains({b, -a}) ? mp[{b, -a}] : 0;
      go.ep(c, d);
    } else {
      int d = mp.contains({-b, a}) ? mp[{-b, a}] : 0;
      if (not d) go.ep(c, 0);
    }
  }
  go.ep(x, y);
  for (var [a, b] : go) s *= T(2).pow(a) + T(2).pow(b) - 1;
  print(s - 1 + d);
}

int main() { Yorisou(); }