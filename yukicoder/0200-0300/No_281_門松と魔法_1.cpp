#include "YRS/all.hpp"

ll f(ll d, ll a, ll b, ll c) {
  ll s = 0;
  if (a > b) {
    ll e = ceil(a - b, d);
    s += e;
    a -= e * d;
    chmax(a, 0);
  }
  if (c > b) {
    ll e = ceil(c - b, d);
    s += e;
    c -= e * d;
    chmax(c, 0);
  }
  while ((a >= b or c >= b or a == c) and not(a == 0 and c == 0)) {
    if (a > c) a -= d, ++s;
    else c -= d, ++s;
    chmax(a, 0);
    chmax(c, 0);
  }
  if (a == c) return inf<ll>;
  return s;
}
ll g(ll d, ll a, ll b, ll c) {
  ll s = 0;
  if (a == c) ++s, a -= d, chmax(a, 0);
  if (a > c) swap(a, c);
  if (b >= a) {
    ll e = ceil(b - a, d);
    s += e;
    b -= e * d;
    chmax(b, 0);
  }
  if (b == a) ++s, b -= d, chmax(b, 0);
  if (a != b and b != c and a != c) return s;
  return inf<ll>; 
}
void Yorisou() {
  LL(d, a, b, c);
  if (d == 0) {
    if (a != c and ((a < b and b > c) or (a > b and b < c))) return print(0);
    return print(-1);
  }
  ll s = inf<ll>;
  chmin(s, f(d, a, b, c));
  chmin(s, g(d, a, b, c));
  print(s == inf<ll> ? -1 : s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"