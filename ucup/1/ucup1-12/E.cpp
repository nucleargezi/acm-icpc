#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  vc<int> a[5];
  FOR(i, 5) {
    a[i].resize(N);
    IN(a[i]);
    sort(a[i]);
  }
  vc<int> f;
  FOR(i, 5) for (int x : a[i]) f.ep(x);
  unique(f);
  int sz = si(f);
  FOR(i, 5) for (int &x : a[i]) x = lb(f, x);
  vc<vc<int>> g(sz);
  FOR(i, 5) for (int x : a[i]) g[x].ep(i);

  Z prod = [&](int i, int l, int r) -> mint {
    return lb(a[i], r) - lb(a[i], l);
  };
  
  bool vis[5]{};
  mint rs = 0;
  FOR(i, sz) {
    unique(g[i]);
    int sm = si(g[i]);
    vc<int> I;
    FOR(s, 1, 1 << sm) {
      I.clear();
      FOR(k, sm) if (s >> k & 1) vis[g[i][k]] = 1;
      FOR(i, 5) {
        if (not vis[i]) I.ep(i);
        else vis[i] = 0;
      }

      int ls = 5 - pc(s);
      mint ad = 1;
      FOR(k, sm) if (s >> k & 1) ad *= prod(g[i][k], i, i + 1);
      FOR(ms, 1 << ls) {
        int p = pc(ms);
        if (p < 3 and ls - p < 3) {
          mint go = ad;
          FOR(k, ls) {
            if (ms >> k & 1) go *= prod(I[k], 0, i);
            else go *= prod(I[k], i + 1, sz);
          }
          rs += go * f[i];
        }
      }
    }
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}