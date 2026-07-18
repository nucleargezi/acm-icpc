#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"
#include "YRS/ds/st/range_max.hpp"
#include "YRS/ds/seg/segd_t.hpp"
#include "YRS/al/m/add.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/ds/basic/hashmap.hpp"

using MX = Add<int>;
using DS = segd_t<MX, 1>;
using np = DS::np;
using mint = M99;

void Yorisou() {
  INT(N, Q);
  STR(s);
  for (char &c : s) c -= 'a';
  VEC(ll, a, N);
  range_max<ll> st(pre_sum<0>(a));
  a = pre_sum(a);
  vc<ll> mn(N + 1);
  FOR(i, 1, N + 1) mn[i] = min(mn[i - 1], a[i]);
  vc<ll> aa = pre_sum<0>(a);

  sam ss(N);
  ss.build(s);
  int M = si(ss);
  Z en = std::move(ss.en);
  vc<int> to(M, -1);
  FOR(i, N) to[en[i]] = i;
  Z g = ss.build_dir_g();
  vc<int> V, L(M), sz(M, 1), q{0};
  while (si(q)) {
    int n = pop(q);
    L[n] = si(V);
    V.ep(n);
    int sz = si(g[n]);
    FOR_R(i, sz) q.ep(g[n][i]);
  }
  FOR_R(i, M) {
    int n = V[i];
    for (int x : g[n]) sz[n] += sz[x];
  }

  DS seg(0, N);
  vc<np> t(M + 1);
  FOR(i, M) {
    t[i + 1] = t[i];
    int p = to[V[i]];
    if (p != -1) t[i + 1] = seg.add(t[i + 1], p, 1);
  }

  vc<int> ps(N);
  Z f = [&](Z &f, np a, np b, int l, int r) -> void {
    if ((b ? b->x : 0) - (a ? a->x : 0) == 0) return;
    if (l + 1 == r) {
      ps.ep(l);
      return;
    }
    int m = (l + r) >> 1;
    f(f, a ? a->l : 0, b ? b->l : 0, l, m);
    f(f, a ? a->r : 0, b ? b->r : 0, m, r);
  };
  
  hashmap<PLL> mp;
  FOR(Q) {
    STR(s);
    for (char &x : s) x -= 'a';
    int m = si(s), x = 0;
    for (int c : s) {
      x = ss[x][c];
      if (x == -1) break;
    }
    if (x == -1) {
      print(0, 0);
      continue;
    }
    ull ke = ull(x) << 32 | m;
    if (mp.contains(ke)) {
      print(mp[ke]);
      continue;
    }
    ps.clear();
    f(f, t[L[x]], t[L[x] + sz[x]], 0, N);
    ll mx = -inf<ll>;
    mint sm;
    FOR(i, si(ps)) {
      int l = ps[i], mi = l - m + 1, r = i + 1 < si(ps) ? ps[i + 1] : N;
      chmax(mx, st.prod(l, r) - mn[mi]);
      mint sr = aa[r] - aa[l], sl = aa[mi];
      sm += sr * (mi + 1) - sl * (r - l);
    }
    print(mp[ke] = {mx, sm.val()});
  }
}

int main() {
  Yorisou();
  return 0;
}