#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  vc<ll> a, b;
  FOR(N) {
    INT(x);
    (x < 0 ? a : b).ep(std::abs(x));
  }
  sort(a, greater());
  sort(b, greater());
  ll s = 0;
  if (a.empty() or b.empty()) {
    if (a.empty()) a.swap(b);
    max_heap<ll> q;
    q.eb(a[0]);
    q.eb(a[1]);
    s += a[0] * a[1];
    FOR(i, 2, N) {
      ll x = a[i], y = pop(q);
      s += x * y;
      q.eb(x);
    }
    s += pop(q) * pop(q);
    return print(s);
  }
  if (len(b) > len(a)) a.swap(b);
  max_heap<ll> q;
  q.eb(a[0]);
  q.eb(a[1]);
  s += a[0] * a[1];
  FOR(i, 2, len(a)) {
    ll x = a[i], y = pop(q);
    s += x * y;
    q.eb(x);
  }
  ll x = pop(q), y = pop(q);
  if (len(b) == 1) {
    s += (x + y) * -pop(b);
  } else {
    a.swap(b);
    q.eb(a[0]);
    q.eb(a[1]);
    s += a[0] * a[1];
    FOR(i, 2, len(a)) {
      ll x = a[i], y = pop(q);
      s += x * y;
      q.eb(x);
    }
    ll e = pop(q), r = pop(q);
    s += max(-e * x + -r * y, -e * y + -r * x);
  }
  print(s);
}
#include "YRS/aa/main.hpp"