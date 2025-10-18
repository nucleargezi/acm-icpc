#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/mod/modint.hpp"

// #define tests
using RE = long double;
using M0 = M99;
using M1 = M17;
using M2 = modint<1'000'000'009>;
struct X {
  M0 a;
  M1 b;
  M2 c;
  X(ll x = 0) : a(x), b(x), c(x) {}
  
  void add(int x) {
    a = a * 10 + x;
    b = b * 10 + x;
    c = c * 10 + x;
  }

  bool operator<(const X &p) const {
    Z [aa, bb, cc] = p;
    if (aa != a) return a.val < aa.val;
    if (bb != b) return b.val < bb.val;
    if (cc != c) return c.val < cc.val;
    return false;
  }
};
X sum(X a, X b) {
  a.a += b.a;
  a.b += b.b;
  a.c += b.c;
  return a;
}
X sub(X a, X b) {
  a.a -= b.a;
  a.b -= b.b;
  a.c -= b.c;
  return a;
}
using std::log;
void Yorisou() {
  vector<ll> g{0, 1};
  vector<RE> fib{0, 0};
  while (len(g) <= 60) {
    g.ep(g.end()[-1] + g.end()[-2]);
    fib.ep(log(g.back()));
  }
  vector<X> H;
  for (ll x : g) H.ep(x);
  const RE fi = log(RE(1 + sqrtl(5)) / 2), se = log(RE(sqrtl(6)));
  FOR(i, 61, 1'000'000'0) {
    fib.ep(i * fi - se);
    H.ep(sum(H.end()[-2], H.end()[-1]));
  }

  INT(N);
  VEC(string, a, N);
  sort(a, [&](string &a, string &b) -> bool {
    if (len(a) != len(b)) return len(a) < len(b);
    return a < b;
  });

  map<X, int> mp;
  ll ans = 0;
  FOR(i, N) {
    string &s = a[i];
    const int N = len(s);
    X h;
    for (char &c : s) {
      c -= '0';
      h.add(c);
    }
    RE val = log(s[0]) + (N - 1) * log(10);
    int p = lower_bound(fib, val);
    FOR(i, 5) {
      int t = p - i;
      if (t < 0) break;
      X v = sub(H[t], h);
      ans += mp.contains(v) ? mp[v] : 0;
    }
    FOR(i, 1, 5) {
      int t = p + i;
      if (t < 0) break;
      X v = sub(H[t], h);
      ans += mp.contains(v) ? mp[v] : 0;
    }
    ++mp[h];
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"