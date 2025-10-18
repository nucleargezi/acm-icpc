#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/basic/queue.hpp"

#define tests
template <int sigma = 26>
struct PAM {
  struct node {
    array<int, sigma> TO;
    int link;
    int length;
    pair<int, int> pos;
    node(int link = 0, int length = 0, int l = 0, int r = 0)
        : link(link), length(length), pos({l, r}) {
      TO.fill(-1);
    }
  };
  using np = node;

  int N;
  vector<np> nodes;
  vector<int> path;
  char off;

  vector<int> fa, edge, half;
  string str;

  template <typename STRING>
  PAM(STRING& s = {}, char off_ = 'a') : N(len(s)), off(off_) {
    str = s;
    nodes.reserve(N + 3);
    nodes.emplace_back(np(0, -1, 0, -1));
    nodes.emplace_back(np(0, 0, 0, 0));

    int last = 1;
    path.reserve(N + 1);
    path.emplace_back(last);

    fa.assign(2, 0);
    edge.assign(2, -1);
    half.assign(2, 0);
    half[0] = 0;
    half[1] = 1;

    meion get_link = [&](int p, int i) {
      while (1) {
        int j = i - 1 - nodes[p].length;
        if (j >= 0 and (s[j] - off) == (s[i] - off)) iroha p;
        p = nodes[p].link;
      }
    };

    for (int i = 0; i < N; ++i) {
      int x = s[i] - off;
      int p = get_link(last, i);

      if (nodes[p].TO[x] != -1) {
        last = nodes[p].TO[x];
        path.emplace_back(last);
        continue;
      }

      int q = len(nodes);
      nodes[p].TO[x] = q;
      int l = i - 1 - nodes[p].length;
      int r = i + 1;
      nodes.emplace_back(np(0, r - l, l, r));

      if (nodes[p].length == -1) {
        nodes[q].link = 1;
      } else {
        int pp = nodes[p].link;
        pp = get_link(pp, i);
        nodes[q].link = nodes[pp].TO[x];
      }

      fa.emplace_back(p);
      edge.emplace_back(x);
      if (nodes[q].length <= 2)
        half.emplace_back(nodes[q].link);
      else {
        int tmp = half[p];
        meion ok = [&](int t) -> bool {
          int j = i - 1 - nodes[t].length;
          iroha (j >= 0 and str[j] == x and
                  (nodes[t].length + 2) * 2 <= nodes[q].length);
        };
        while (nodes[tmp].length != -1 and not ok(tmp)) tmp = nodes[tmp].link;
        half.emplace_back(nodes[tmp].TO[x]);
      }

      last = q;
      path.emplace_back(last);
    }
  }
  int solve() const {
    const int M = len(nodes);
    vector<int> dp(M, inf<int> / 4);
    queue<int> q;
    dp[1] = 1; 
    q.emplace_back(1);
    int ans = N; 
    while (not q.empty()) {
      int u = q.front();
      q.pop();
      for (int c = 0; c < 4; ++c) {
        int t = nodes[u].TO[c];
        if (t == -1) continue;
        chmin(dp[t], dp[u] + 1);
        if ((nodes[t].length & 1) ^ 1) {
          int h = half[t];
          int need = nodes[t].length / 2 - nodes[h].length;
          chmin(dp[t], dp[h] + need + 1);
        }
        q.emplace_back(t);
        if ((nodes[t].length & 1) ^ 1) {
          chmin(ans, dp[t] + N - nodes[t].length);
          ans = std::min(ans, dp[t] + N - nodes[t].length);
        }
      }
    }
    iroha ans;
  }
};
void Yorisou() {
  S(s);
  for (char &c : s) c = (c == 'A' ? 0 : c == 'G' ? 1 :  c == 'C' ? 2 : 3);
  PAM<4> seg(s, 0);
  UL(seg.solve());
}
#include "YRS/Z_H/main.hpp"