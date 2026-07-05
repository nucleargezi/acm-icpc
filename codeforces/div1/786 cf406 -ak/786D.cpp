#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/bs.hpp"
#include "YRS/gg/csr.hpp"

void Yorisou() {
  INT(N, Q);
  csr<csr_edge_w<u8>> g(N);
  vc<vc<edge_id>> q(N);
  vc<u16> fa(N, -1), c(N), d(N), vis(N), cp(N), st(N), rs(Q), ch(N << 1 | 1);
  FOR(N - 1) {
    INT(a, b);
    CH(w);
    --a, --b;
    g.add(a, b, w);
    g.add(b, a, w);
  }
  g.build();
  FOR(i, Q) {
    INT(a, b);
    --a, --b;
    q[a].ep(b, i);
  }

  Z se = [&](Z &f, int n, int p) -> void {
    for (Z &&e : g[n]) if (e != p) {
      fa[e] = n, c[e] = e.w;
      f(f, e, n);
    }
  };
  se(se, 0, -1);

  int T = 0;
  Z run = [&](int a, int b) -> int {
    if (a == b) return 0;
    ++T;
    int r = b, rs = -1;
    d[b] = N;
    while (r != a) {
      ch[d[r]] = c[r];
      vis[r] = T;
      cp[r] = 1;
      d[fa[r]] = d[r] - 1;
      r = fa[r];
      ++rs;
    }
    vis[a] = T, cp[a] = 1;

    FOR(k, N) if (vis[k] != T) {
      int cc = 0;
      r = k;
      while (vis[r] != T) st[cc++] = r, r = fa[r];
      while (cc) {
        int x = st[--cc];
        d[x] = d[fa[x]] + 1;
        vis[x] = T;
        if (cp[fa[x]] != 1) {
          cp[x] = cp[fa[x]];
        } else if (ch[d[x]] > c[x]) {
          cp[x] = 0;
        } else if (ch[d[x]] == c[x]) {
          cp[x] = 1;
        } else {
          cp[x] = 2;
        }
        rs += cp[x] == 0 or (cp[x] == 1 and d[x] < d[b]);
      }
    }
    return rs;
  };

  Z f = [&](Z &f, int n, int p) -> void {
    for (var [b, id] : q[n]) rs[id] = run(n, b);
    int op = fa[n], oc = c[n];
    for (Z &&e : g[n]) if (e != p) {
      fa[n] = e, c[n] = e.w;
      f(f, e, n);
    }
    fa[n] = op;
    c[n] = oc;
  };
  f(f, 0, -1);
  FOR(i, Q) print(rs[i]);
}

int main() {
  Yorisou();
  return 0;
}