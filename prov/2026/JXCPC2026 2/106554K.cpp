#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/ds/basic/queue.hpp"
#include "YRS/random/rng.hpp"

bool no(char c) {
  return c == '#' or c == 'U' or c == 'D' or c == 'L' or c == 'R';
}
void Yorisou() {
  INT(N, M);
  VEC(string, s, N);
  vc<PII> dgs;
  FOR(i, N) FOR(k, M) if (no(s[i][k]) and s[i][k] != '#') dgs.ep(i, k);

  int sx, sy, tx, ty;
  FOR(i, N) FOR(k, M) {
    if (s[i][k] == 'S') sx = i, sy = k;
    if (s[i][k] == 'E') tx = i, ty = k;
  }

  retsu<int> ls(N, M), rs(N, M), cs(N, M), ds(N, M);
  FOR(i, N) {
    int pr = -1;
    FOR(k, M) {
      ls[i][k] = pr;
      if (no(s[i][k])) pr = k;
    }
    pr = M;
    FOR_R(k, M) {
      rs[i][k] = pr;
      if (no(s[i][k])) pr = k;
    }
  }
  FOR(k, M) {
    int pr = -1;
    FOR(i, N) {
      cs[i][k] = pr;
      if (no(s[i][k])) pr = i;
    }
    pr = N;
    FOR_R(i, N) {
      ds[i][k] = pr;
      if (no(s[i][k])) pr = i;
    }
  }

  retsu<ull> xx(N + 1, M + 1);
  retsu<int> sm(N + 1, M + 1);
  vc<T4<int>> rgs;
  vc<ull> hsh, f;
  Z ad = [&](int l, int r, int c ,int d) -> void {
    ull h = rng_64();
    hsh.ep(h);
    rgs.ep(l, r, c, d);
    ++sm[l][c];
    ++sm[r][d];
    --sm[l][d];
    --sm[r][c];
    xx[l][c] ^= h;
    xx[r][d] ^= h;
    xx[l][d] ^= h;
    xx[r][c] ^= h;
  };
  
  for (var [i, k] : dgs) {
    int l = ls[i][k] + 1, r = rs[i][k], c = cs[i][k] + 1, d = ds[i][k];
    if (s[i][k] == 'U') {
      ad(c, i, k, k + 1);
    } else if (s[i][k] == 'D') {
      ad(i + 1, d, k, k + 1);
    } else if (s[i][k] == 'L') {
      ad(i, i + 1, l, k);
    } else if (s[i][k] == 'R') {
      ad(i, i + 1, k + 1, r);
    }
  }
  vc<int> I = argsort(hsh);
  f = rearrange(hsh, I);
  sm.pres();
  FOR(i, N + 1) FOR(k, 1, M + 1) xx[i][k] ^= xx[i][k - 1];
  FOR(k, M + 1) FOR(i, 1, N + 1) xx[i][k] ^= xx[i - 1][k];
  Z in = [&](int x, int y) -> int {
    int id = lb(f, xx[x][y]);
    if (id >= si(f) or f[id] != xx[x][y]) return -1;
    return I[id];
  };

  retsu<char> vis(N, M);
  queue<PII> q, qq;
  q.eb(sx, sy);
  vis[sx][sy] = 1;
  static constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
  int sz = si(dgs);
  vc<vc<PII>> ta(sz), tb(sz);
  while (si(q)) {
    Z [x, y] = pop(q);
    if (sm[x][y] == 1) {
      qq.eb(x, y);
      continue;
    } 
    if (x == tx and y == ty) return print(dgs[0].fi + 1, dgs[0].se + 1);
    FOR(d, 4) {
      int xx = x + dx[d], yy = y + dy[d];
      if (min(xx, yy) < 0 or xx >= N or yy >= M or no(s[xx][yy]) or
          vis[xx][yy] or sm[xx][yy] > 1)
        continue;
      vis[xx][yy] = 1;
      q.eb(xx, yy);
    }
  }
  while (si(qq)) {
    Z [x, y] = pop(qq);
    ta[in(x, y)].ep(x, y);
    FOR(d, 4) {
      int XX = x + dx[d], yy = y + dy[d];
      if (min(XX, yy) < 0 or XX >= N or yy >= M or no(s[XX][yy]) or
          vis[XX][yy] or sm[XX][yy] != 1 or xx[XX][yy] != xx[x][y])
        continue;
      vis[XX][yy] = 1;
      qq.eb(XX, yy);
    }
  }

  vis.fill(0);
  q.eb(tx, ty);
  vis[tx][ty] = 1;
  while (si(q)) {
    Z [x, y] = pop(q);
    if (sm[x][y] == 1) {
      qq.eb(x, y);
      continue;
    }
    FOR(d, 4) {
      int xx = x + dx[d], yy = y + dy[d];
      if (min(xx, yy) < 0 or xx >= N or yy >= M or no(s[xx][yy]) or
          vis[xx][yy] or sm[xx][yy] > 1)
        continue;
      vis[xx][yy] = 1;
      q.eb(xx, yy);
    }
  }
  while (si(qq)) {
    Z [x, y] = pop(qq);
    tb[in(x, y)].ep(x, y);
    FOR(d, 4) {
      int XX = x + dx[d], yy = y + dy[d];
      if (min(XX, yy) < 0 or XX >= N or yy >= M or no(s[XX][yy]) or
          vis[XX][yy] or sm[XX][yy] != 1 or xx[XX][yy] != xx[x][y])
        continue;
      vis[XX][yy] = 1;
      qq.eb(XX, yy);
    }
  }

  PII ans{inf<int>, inf<int>};
  FOR(i, sz) if (si(ta[i]) and si(tb[i])) {
    sort(ta[i]);
    sort(tb[i]);
    bool ok = 0;
    for(var x : tb[i]) {
      if (binary_search(all(ta[i]), x)) {
        ok = 1;
        break;
      }
    }
    if (ok) chmin(ans, dgs[i]);
  }
  if (ans.fi == inf<int>) print(-1, -1);
  else print(ans.fi + 1, ans.se + 1);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}