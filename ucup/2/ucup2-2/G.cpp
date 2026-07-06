#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using bs = bitset<1'000'00>;
void Yorisou() {
  INT(N, M);
  vc<PII> es(M);
  vc<int> in(N);
  vc<vc<int>> g(N);
  FOR(i, M) {
    INT(a, b);
    --a, --b;
    es[i] = {a, b};
    g[a].ep(i);
    g[b].ep(i);
  }
  
  int sq = (int)sqrtl(N) + 1;
  vc<char> vis(N);
  map<int, bs> mp;
  FOR(i, N) {
    if (si(g[i]) >= sq) {
      Z &se = mp[i];
      vis[i] = 1;
      for (int x : g[i]) se.set(x);
    }
  }

  bs s{};
  Z dl = [&](int v, int e) -> void {
    if (vis[v]) {
      mp[v].reset(e);
    } else {
      g[v].erase(find(all(g[v]), e));
    }
  };
  INT(Q);
  FOR(Q) {
    CH(op);
    if (op == '+' or op == '-') {
      INT(i);
      --i;
      if (vis[i]) {
        s ^= mp[i];
      } else {
        for (int x : g[i]) s.flip(x);
      }
    } else {
      int i = s._Find_first(), rs = -1;
      if (i < M) {
        rs = i;
        s.reset(rs);
        var [a, b] = es[rs];
        dl(a, rs);
        dl(b, rs);
      }
      print(rs + 1);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}