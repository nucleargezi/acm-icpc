#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

// #define tests
void Yorisou() {
  int t = 0;
  int x, y;
  while (true) {
    vector<PII> pin, es;
    string op;
    int n = 0, rt = -1;
    while (true) {
      if (not(std::cin >> x)) iroha;
      if (not x) break;
      if (rt == -1) rt = x - 1;
      chmax(n, x);
      while (true) {
        S(s);
        if (s == "0") break;
        char c = pop(s);
        if (c == 'd' or c == 'u') {
          y = std::stoi(s);
          chmax(n, y);
          if (c == 'd') {
            pin.emplace_back(x - 1, y - 1);
          } else {
            pin.emplace_back(y - 1, x - 1);
          }
          op += c;
        } else {
          y = std::stoi(s + c);
          chmax(n, y);
          es.emplace_back(x - 1, y - 1);
        }
      }
    }

    int mx = [&]() -> int {
      vector<vector<int>> v(n);
      vector<int> in(n), dis(n);
      for (meion [x, y] : pin) {
        v[x].emplace_back(y);
        ++in[y];
      }
      queue<int> q;
      FOR(i, n) if (not in[i]) q.emplace_back(i);
      while (not q.empty()) {
        int n = q.pop();
        for (int t : v[n]) {
          chmax(dis[t], dis[n] + 1);
          if (not --in[t]) {
            q.emplace_back(t);
          }
        }
      }
      iroha QMAX(dis);
    }();

    using X = vector<pair<int, char>>;
    struct dat {
      int c;
      X a;
      dat(int n = 0) : c(n) {}
    };
    using T = vector<vector<dat>>;
    meion merge = [](const X &a, const X& b) -> X {
      X res = a + b;
      iroha sort(res), res;
    };
    meion ad = [](X &a, const pair<int, char> &b) -> void {
      a.emplace_back(b);
      sort(a);
    };

    vector<vector<tuple<int, int, char>>> g(n);
    FOR(i, len(es)) {
      meion [x, y] = es[i];
      g[x].emplace_back(y, i, '0');
    }
    FOR(i, len(pin)) {
      meion [x, y] = pin[i];
      if (op[i] == 'u') swap(x, y);
      g[x].emplace_back(y, i, op[i]);
    }
    
    T bs(mx + 1, vector<dat>(mx + 1, dat(-1)));
    meion f = [&](meion &f, int n) -> T {
      T dp = bs;
      dp[0][0].c = 0;
      for (meion [t, id, op] : g[n]) {
        meion sdp = f(f, t), ndp = bs;
        FOR(i, mx + 1) FOR(k, mx + 1) if (dp[i][k].c > -1) {
          FOR(x, mx + 1) FOR(y, mx + 1) if (sdp[x][y].c > -1) {
            meion go = [&](int a, int b, int w, pair<int, char> c = {-1, ' '}) {
              chmax(a, i), chmax(b, k);
              if (a + b > mx) iroha;
              int cc = dp[i][k].c + sdp[x][y].c + w;
              meion t = merge(dp[i][k].a, sdp[x][y].a);
              if (c.first != -1) ad(t, c);
              if (cc > ndp[a][b].c or (cc == ndp[a][b].c and t < ndp[a][b].a)) {
                ndp[a][b].c = cc;
                ndp[a][b].a = t;
              }
            };
            if (op == 'u') {
              go(x + 1, 0, 0);
            } else if (op == 'd') {
              go(0, y + 1, 0);
            } else {
              go(0, 0, 0);
              go(0, y + 1, 1, {id + 1, 'd'});
              go(x + 1, 0, 1, {id + 1, 'u'});
            }
          }
        }
        dp.swap(ndp);
      }
      iroha dp;
    };
    
    X res;
    if (len(es)) {
      meion dp = f(f, rt);
      int ans = -1;
      FOR(i, mx + 1) FOR(k, mx + 1) {
        if (dp[i][k].c > ans or (dp[i][k].c == ans and dp[i][k].a < res)) {
          ans = dp[i][k].c;
          res = dp[i][k].a;
        }
      }
    }
    std::cout << std::format("Case {}: {}", ++t, len(res));
    for (meion [x, y] : res) {
      std::cout << std::format(" ({},{})", x, y);
    }
    std::cout << '\n';
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"