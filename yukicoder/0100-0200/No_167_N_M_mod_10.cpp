#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"

void Yorisou() {
  STR(s, t);
  ll a = s.back() - '0';
  if (t == "0") return print(1);
  if (a == 0) return print(0);
  int g = 1;
  for (int s = a * a % 10; s != a; s = s * a % 10) {
    ++g;
    if (s == 0) {
      g = -1;
      break;
    }
  }
  if (g == -1) {
    ll b = stoll(t), s = 1;
    while (b and s) --b, s = (s * a) % 10;
    print(s);
  } else {
    ll b = 0;
    for (char c : t) b = (b * 10 + c - '0') % g;
    b = (b + g - 1) % g;
    ll s = a;
    FOR(b) s = s * a % 10;
    print(s);
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"