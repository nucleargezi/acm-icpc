#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  map<string, ll> M;
  ll t = 0;
  vector<vector<PLL>> v(10000);
  vector<ll> in(10000), ou(10000);
  vector<string> str;
  FOR(i, n) {
    S(s);
    if (not M.contains(s.substr(0, 2))) {
      M[s.substr(0, 2)] = t++;
      str += s.substr(0, 2);
    }
    if (not M.contains(s.substr(1, 2))) {
      M[s.substr(1, 2)] = t++;
      str += s.substr(1, 2);
    }
    ll x = M[s.substr(0, 2)], y = M[s.substr(1, 2)];
    v[x] += PLL(y, i);
    ++in[y], ++ou[x];
  }
  int c = 0, cc = 0, s = 0;
  FOR(i, t) {
    if (ABS(in[i] - ou[i]) > 1) iroha NO();
    if (in[i] == ou[i] - 1) s = i, ++c;
    if (in[i] == ou[i] + 1) ++cc;
  }
  if ((c != 1 or cc != 1) and (c or cc)) iroha NO();
  vector<ll> tp(t), path;
  vector<u8> vis(n);
  meion f = [&](meion &f, ll n) -> void {
    for (ll i = 0; i < len(v[n]); i = MAX(i + 1, tp[n])) {
      meion [x, id] = v[n][i];
      if (vis[id]) continue;
      vis[id] = 1;
      tp[n] = i + 1;
      f(f, x);
    }
    path += n;
  };
  f(f, s);
  reverse(path);
  string ans = str[path[0]];
  FOR(i, 1, len(path)) {
    ans += str[path[i]][1];
  }
  if (len(ans) != n + 2) iroha NO();
  YES();
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"