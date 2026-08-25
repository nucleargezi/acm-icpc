#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, Q);
  map<int, map<string, int>> mp;
  map<int, PII> dp;
  int t = 1;
  FOR(i, N) {
    STR(s);
    string n;
    int x = 0;
    for (char c : s) {
      if (c == '/') {
        if (not mp[x].contains(n)) mp[x][n] = t++;
        x = mp[x][n];
        n = "";
      } else {
        n += c;
      }
    }
    if (not n.empty()) {
      if (not mp[x].contains(n)) mp[x][n] = t++;
      x = mp[x][n];
    }
    dp[x] = {1, 0};
  }
  FOR(Q) {
    STR(s);
    string n;
    int x = 0;
    for (char c : s) {
      if (c == '/') {
        if (not mp[x].contains(n)) mp[x][n] = t++;
        x = mp[x][n];
        n = "";
      } else {
        n += c;
      }
    }
    if (not n.empty()) {
      if (not mp[x].contains(n)) mp[x][n] = t++;
      x = mp[x][n];
    }
    dp[x] = {0, 1};
  }
  vc<int> V{0}, fa(t, -1);
  FOR(i, si(V)) {
    int n = V[i];
    for (var [_, x] : mp[n]) V.ep(x), fa[x] = n;
  }
  int rs = 0;
  for (int i = t - 1; i >= 1; --i) {
    int n = V[i];
    Z [a, b] = dp[n];
    int f = fa[n];
    if (b == 0) {
      dp[f].fi += not not a;
    } else {
      rs += a;
      dp[f].se = 1;
    }
  }
  Z [a, b] = dp[0];
  rs += a;
  print(rs);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
}