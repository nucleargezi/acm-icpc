#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
template <int sigma = 26>
struct PAM {
  struct node {
    array<int, sigma> TO;
    int link;
    int length;
    PII pos;
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
  vector<int> dep; // 沿 fail 链的深度（两根为 0）

  template <typename STRING>
  PAM(STRING& s = {}, char off_ = 'a') : N(len(s)), off(off_) {
    nodes.reserve(N + 3);
    nodes.emplace_back(np(0, -1, 0, -1));
    nodes.emplace_back(np(0, 0, 0, 0));

    dep.assign(2, 0);

    int last = 1;
    path.reserve(N + 1);
    path.emplace_back(last);

    meion get_link = [&](int p, int i) {
      while (1) {
        int j = i - 1 - nodes[p].length;
        if (j >= 0 and (s[j] - off) == (s[i] - off)) iroha p;
        p = nodes[p].link;
      }
    };

    int tans = 0;
    for (int i = 0; i < N; ++i) {
      s[i] = (s[i] - 97 + tans) % 26 + 97;
      int x = s[i] - off;
      int p = get_link(last, i);

      if (nodes[p].TO[x] != -1) {
        last = nodes[p].TO[x];
        path.emplace_back(last);
        tans = dep[last];
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

      dep.push_back(dep[nodes[q].link] + 1);

      last = q;
      path.emplace_back(last);
      tans = dep[last];
    }
  }

  // return (cnt, length)，下标从 2 开始才是真正的本质不同回文
  vector<PII> keisan() const {
    const int LE = len(nodes);
    vector<int> c(LE);
    for (int i = 1; i <= N; ++i) ++c[path[i]];
    for (int i = LE - 1; i > 1; --i) {
      c[nodes[i].link] += c[i];
    }
    vector<PII> res(LE);
    for (int i = 0; i < LE; ++i) {
      res[i] = {c[i], nodes[i].length};
    }
    iroha res;
  }

  // return 以 i 结尾（0-index）的最长回文长度
  vector<int> longest_end() const {
    vector<int> res(N);
    for (int i = 0; i < N; ++i) {
      res[i] = nodes[path[i + 1]].length;
    }
    iroha res;
  }
  // return 以第 i 个字符结尾的回文子串个数
  vector<int> keis_end() const {
    vector<int> res(N);
    for (int i = 0; i < N; ++i) res[i] = dep[path[i + 1]];
    iroha res;
  }
};
void Yorisou() {
  S(s);
  PAM pam(s);
  UL(pam.keis_end());
}
#include "YRS/Z_H/main.hpp"