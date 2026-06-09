// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/binom.hpp"

void Yorisou() {
  LL(a, b, p);
  ll g = 1'000'000'000;
  FOR(x, p) {
    if (x > a) break;
    ll y = x * -g % p;
    if (y < 0) y += p;
    if (y > b) {
      string s = to_string(x);
      while (si(s) < 9) s = '0' + s;
      return print(1, s);
    }
  }
  print(2);
}

int main() {
  Yorisou();
  return 0;
}