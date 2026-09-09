#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/min_cost_bflow.hpp"

void Yorisou() {
  int a[16]{}, b[16]{}, c[56], p[56], q[56], rs = -1;
  string s = "BRWY";
  FOR(i, 56) {
    CH(x);
    c[i] = 1 << s.find(x);
  }
  FOR(i, 4) FOR_R(k, i, 4) IN(a[(1 << i) | (1 << k)]);

  Z ke = [&] {
    int f[16]{}, g[16]{}, r = 0, t = 0;
    FOR(i, 16) {
      int x = min(a[i], b[i]);
      f[i] = b[i] - x, g[i] = a[i] - x;
      r += a[i] + b[i];
    }
    FOR(i, 4) FOR(k, 16) if (k >> i & 1)
      f[k] += f[k ^ (1 << i)], g[k] += g[k ^ (1 << i)];
    FOR(i, 16) chmax(t, f[i] + g[i ^ 15]);
    return r - t;
  };
  Z f = [&](Z &f, ull s) -> void {
    if (rs == 56) return;
    if (not s) {
      if (chmax(rs, ke())) copy(p, p + 56, q);
      return;
    }
    int x = lowbit(s);
    s ^= 1ull << x;
    for (int i : {1, 8}) {
      int y = x + i;
      if (y >= 56 or (i == 1 and x % 8 == 7) or not(s >> y & 1)) continue;
      p[x] = y, p[y] = x;
      ++b[c[x] | c[y]];
      f(f, s ^ (1ull << y));
      --b[c[x] | c[y]];
    }
  };
  f(f, (1ull << 56) - 1);
  print(rs);

  vc<string> mp(13, string(15, '.'));
  FOR(i, 56) if (i < q[i]) ++b[c[i] | c[q[i]]];
  Z pl = [&](int x, int y) {
    --b[c[x] | c[y]];
    FOR(i, 4) FOR(k, i, 4) {
      int r = 1 << i, h = 1 << k, m = r | h;
      if (not a[m]) continue;
      int v = (c[x] == r) + (c[y] == h), w = (c[x] == h) + (c[y] == r);
      --a[m];
      if (ke() + max(v, w) == rs) {
        if (v < w) swap(r, h);
        rs -= max(v, w);
        mp[x / 8 * 2][x % 8 * 2] = s[lowbit(r)];
        mp[y / 8 * 2][y % 8 * 2] = s[lowbit(h)];
        mp[x / 8 + y / 8][x % 8 + y % 8] = y - x == 1 ? '-' : '|';
        return;
      }
      ++a[m];
    }
  };
  FOR(i, 56) if (i < q[i]) pl(i, q[i]);
  for (var x : mp) print(x);
}

int main() { Yorisou(); }