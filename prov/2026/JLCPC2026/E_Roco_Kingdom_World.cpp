#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/spl/splay_mset.hpp"

using DS = splay_mset<ll, ll>;
using np = DS::np;
void Yorisou() {
  INT(N, A, B, sz, Q);
  vc<array<int, 2>> dat(N);
  for (Z &[a, b] : dat) IN(a, b), --a, --b;
  vc<int> a[2], aa[2];
  vc<ll> ca[2], pt[2];
  FOR(i, 2) {
    sh(a[i], i ? B : A);
    sh(aa[i], i ? B : A);
    sh(ca[i], i ? B : A);
    sh(pt[i], i ? B : A);
  }
  IN(a[0], a[1], aa[0], aa[1]);
  
  DS seg;
  np t = 0;
  ll r = 0;
  map<ll, PLL> mp;
  FOR(Q) {
    CH(op);
    if (op == 'C') {
      CH(ty);
      LL(x, c);
      --x;
      bool f = ty != 'F';
      x = dat[x][f];
      ll &w = ca[f][x];
      w += c;
      ll d = w / a[f][x];
      w %= a[f][x];
      if (d) seg.ins(t, r << 1 | f, d), mp[r << 1 | f] = {x, d}, ++r;
      for (ll d = seg.size(t) - sz; d > 0; ) {
        Z it = bg(mp);
        if (it->se.se > d) {
          it->se.se -= d;
          seg.del(t, it->fi, d);
          d = 0;
        } else {
          seg.del(t, it->fi, it->se.se);
          d -= it->se.se;
          mp.erase(it);
        }
      }
    } else {
      LL(K, lm);
      if (seg.size(t) < K) {
        print("MISS");
        continue;
      }
      K = seg.kth(t, K - 1);
      seg.del(t, K);
      Z it = mp.find(K);
      Z &[x, w] = it->se;
      --w;
      bool f = K & 1;
      pt[f][x] += 1;
      if (lm <= aa[f][x] or pt[f][x] >= 80) {
        pt[f][x] = 0;
        print("SHINY", f ? 'E' : 'F', x + 1);
      } else {
        print("NORMAL", f ? 'E' : 'F', x + 1, pt[f][x]);
      }
      if (w == 0) mp.erase(it);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}