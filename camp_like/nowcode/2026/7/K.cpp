#include "YRS/all.hpp"

void Yorisou() {
  INT(N);
  vc<vc<string>> a(N);
  string buf;
  cin.ignore();
  FOR(i, N) {
    getline(cin, buf);
    string na;
    for (char c : buf) {
      if (c == ' ') {
        a[i].ep(na);
        na.clear();
      } else {
        na += c;
      }
    }
    if (not na.empty()) a[i].ep(na);
  }
  map<string, vc<pair<int, vc<int>>>> dp, ndp;
  FOR(i, N) {
    string s;
    vc<int> zp;
    for (string t : a[i]) s += t[0], zp.ep(1);
    dp[s].ep(i, zp);
  }
  Z ext = [&](int i, vc<int> vis) -> void {
    string s;
    if (vis.back() == 0) {
      for (var x : a[i]) s += x;
      ndp[s].ep(i, vis);
    } else {
      FOR(i, si(vis)) if (vis[i]) {
        vis[i] = 0;
        break;
      }
      FOR(k, si(vis)) {
        if (vis[k]) s += a[i][k][0];
        else s += a[i][k];
      }
      ndp[s].ep(i, vis);
    }
  };
  while (si(dp) < N) {
    ndp.clear();
    for (var [st, v] : dp) {
      if (si(v) == 1) {
        ndp[st] = v;
      } else {
        for (var [i, vs] : v) {
          ext(i, vs);
        }
      }
    }
    dp.swap(ndp);
  }
  vc<string> rs(N);
  for (var [s, v] : dp) {
    assert(si(v) == 1);
    rs[v[0].fi] = s;
  }
  for (var s : rs) print(s);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  Yorisou();
  return 0;
}