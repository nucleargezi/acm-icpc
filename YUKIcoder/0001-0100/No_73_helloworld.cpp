#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/nt/fib_search.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  vc<ll> c(0721);
  FOR(i, 26) IN(c[i + 'a']);
  ll s = 1;
  s *= c['h'];
  s *= c['e'];
  s *= c['o'] / 2;
  s *= c['w'];
  s *= (c['o'] + 1) / 2;
  s *= c['r'];
  s *= c['d'];
  ll g = fib_search<ll, 0, ll>([&](ll x) -> ll {
    return x * (x - 1) / 2 * (c['l'] - x);
  }, 0, c['l'] + 1).fi;
  print(s * g);
}
#include "YRS/aa/main.hpp"