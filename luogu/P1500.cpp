#define YRSD
#include "YRS/all.hpp"
#include "YRS/flow/hungarian.hpp"

void nor(ll &a, ll &b) {
  ll g = gcd(a, b);
  a /= g, b /= g;
  if (a < 0 or (a == 0 and b < 0)) a = -a, b = -b;
}
ll sq(ll a) { return a * a; }
ll dist(PII a, PII b) { return sq(a.fi - b.fi) + sq(a.se - b.se); }
void fmt(string &s) {
  for (char &c : s) if (c >= 'A' and c <= 'Z') c -= 'A' - 'a';
}
void Yorisou() {
  LL(K, N);
  vc<PII> p(N << 1);
  vc<string> s(N << 1);
  map<string, int> mp;
  FOR(i, N << 1) IN(p[i], s[i]), fmt(s[i]), mp[s[i]] = i;
  retsu<ll> a(N, N, -inf<int>);
  
  Z con = [&](int i, int k, int w) -> void {
    if (i > k) swap(i, k);
    if (i >= N or k < N) return;
    if (dist(p[i], p[k]) > K * K) return;
    bool ok = 1;
    FOR(j, N << 1) if (j != i and j != k and ok) {
      if (p[i].fi == p[k].fi) {
        if (p[j].fi == p[i].fi) {
          int l = p[i].se, r = p[k].se;
          if (l > r) swap(l, r);
          if (p[j].se >= l and p[j].se <= r) ok = 0;
        }
      } else {
        if (p[j].fi != p[i].fi and p[j].fi != p[k].fi) {
          ll a = p[i].se - p[j].se, b = p[i].fi - p[j].fi;
          ll c = p[j].se - p[k].se, d = p[j].fi - p[k].fi;
          nor(a, b), nor(c, d);
          if (a == c and b == d and
              max(dist(p[i], p[j]), dist(p[k], p[j])) < dist(p[i], p[k])) {
            ok = 0;
          }
        }
      }
    }
    if (ok) a[i][k - N] = w;
  };
  
  FOR(i, N) FOR(k, N, N << 1) con(i, k, 1);

  string l, r;
  ll w;
  while (IN(l), fmt(l), l != "end") {
    IN(r, w);
    fmt(r);
    int i = mp[l], k = mp[r];
    con(i, k, w);
  }
  print(get<0>(hungarian(a)));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"