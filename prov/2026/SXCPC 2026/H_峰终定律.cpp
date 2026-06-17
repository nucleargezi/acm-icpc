#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_t.hpp"
#include "YRS/al/m/maxidx.hpp"

void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  vc<PII> dat;
  vc<int> rs(N);
  int c = 0;
  vc<int> I;
  FOR(i, N - 1) {
    if (a[i] >= 0) dat.ep(a[i], c++), I.ep(i); 
  }
  ll s = a[N - 1];
  rs[N - 1] = 1;
  int t = 2;
  seg_t<Maxidx<int>> seg(dat);
  bool f = 1;
  if (si(dat)) {
    f = 0;
    Z [mx, id] = seg.prod();
    seg.set(id, {-inf<int>, -1});
    s += mx;
  }
  K -= 1;
  vc<T3<int>> st;
  for (;;) {
    Z [mx, id] = seg.prod();
    if (id == -1) break;
    seg.set(id, {-inf<int>, -1});
    Z [mxx, idd] = seg.prod();
    if (idd ==-1) {
      st.ep(mx, I[id], -1);
    } else {
      seg.set(idd, {-inf<int>, -1});
      st.ep(mx + mxx, I[id], I[idd]);
    }
  }
  sort(st, greater());
  
  for (var [w, a, b] : st) if (K) {
    --K;
    s += w;
    if (a != -1) rs[a] = t;
    if (b != -1) rs[b] = t;
    ++t;
  }
  int mx = -inf<int>;
  FOR(i, N - 1) if (rs[i] == 0) {
    if (f) chmax(mx, a[i]);
    rs[i] = 1;
  }
  if (mx != -inf<int>) s += mx;
  print(s);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}