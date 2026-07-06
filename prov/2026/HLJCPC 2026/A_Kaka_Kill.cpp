#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/hld.hpp"

struct dat {
  int op, cd, s, t;
};

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  hld v(g, 0);
  vc<dat> a(M);
  vc<vc<int>> st(N);
  FOR(i, M) {
    Z &[op, cd, s, t] = a[i];
    IN(op, cd, s, t);
    --op, --s, --t;
  }
  
  vc<char> vis(M);
  vc<int> q[4], out;
  for (int c = 0, t = 1; c < M; ++t) {
    FOR(i, M) if (not vis[i]) {
      Z &[op, cd, s, t] = a[i];
      s = v.jump(s, t, 1);
      if (s == t) vis[i] = 1, out.ep(i + 1), ++c;
      else st[s].ep(i);
    }
    FOR(i, N) if (si(st[i])) {
      for (int id : st[i]) q[a[id].op].ep(id);
      st[i].clear();
      bool kl[4]{};
      for (int i : q[1]) if (not kl[0]) {
        if (t % a[i].cd == 0) kl[0] = 1;
      }
      for (int i : q[2]) if (not kl[1]) {
        if (t % a[i].cd == 0) kl[1] = 1;
      }
      vc<int> qq;
      for (int i : q[3]) {
        if (t % a[i].cd == 0) kl[1] = kl[2] = 1, qq.ep(i);
      }
      if (not kl[0]) {
        for (int i : q[0]) {
          if (t % a[i].cd == 0) kl[1] = kl[2] = kl[3] = 1;
        }
      }
      int n = min(si(qq), 2ll);
      FOR(i, n) {
        int x = qq[i];
        for (int t : q[3]) if (t != x) c += not vis[t], vis[t] = 1;
      }
      FOR(i, 4) {
        if (kl[i]) for (int x : q[i]) c += not vis[x], vis[x] = 1;
        q[i].clear();
      }
    }
  }
  sort(out);
  print(si(out));
  for (int x : out) print(x);
}

int main() {
  Yorisou();
  return 0;
}