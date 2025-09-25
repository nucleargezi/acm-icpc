#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(K, N, M, Q);
  FOR(N) { STR(s); }
  string s;
  map<string, map<string, ll>> mp;
  FOR(M) {
    STR(g);
    if (g.back() == ' ' or g.back() == ':') pop(g);
    map<string, ll> m;
    std::getline(cin, s);
    vector<int> I;
    FOR(i, len(s)) if (s[i] == ' ') I.ep(i);
    const int n = len(I) >> 1;
    I.ep(len(s));
    FOR(i, n) {
      string x = s.substr(I[i << 1] + 1, I[i << 1 | 1] - I[i << 1] - 1);
      string y = s.substr(I[i << 1 | 1] + 1, I[(i + 1) << 1] - I[i << 1 | 1]);
      while (y.back() == ',' or y.back() == ' ') pop(y);
      m[x] = std::stoll(y);
    }
    mp[g] = m;
  }

  vector<map<string, ll>> g(K);
  FOR(Q) {
    INT(x);
    --x;
    STR(s);
    ++g[x][s];
    for (Z &[s, mp] : mp) {
      bool upd = true;
      for (Z &[f, c] : mp) {
        if (not g[x].contains(f) or g[x][f] < c) {
          upd = false;
          break;
        }
      }
      if (not upd) continue;
      ++g[x][s];
      for (Z &[f, c] : mp) {
        g[x][f] -= c;
      }
      break;
    }
  }
  FOR(i, K) {
    vector<pair<string, int>> ans;
    for (Z &[s, c] : g[i]) {
      if (c) ans.ep(s, c);
    }
    print(len(ans));
    for (Z &x : ans) print(x);
  }
}
#include "YRS/Z_H/main.hpp"