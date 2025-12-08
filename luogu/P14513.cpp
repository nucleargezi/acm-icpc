#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
struct bitvec {
  int N;
  vc<pair<ull, uint>> s;
  bitvec(int N = 0) : N(N), s((N + 127) >> 6) {}

  void set(int i) { s[i >> 6].fi |= 1ull << (i & 63); }

  void build() {
    int N = len(s) - 1;
    FOR(i, N) s[i + 1].se = s[i].se + pc(s[i].fi);
  }

  int rank(int k, bool f = 1) const {
    Z [a, b] = s[k >> 6];
    int r = b + pc(a & ((1ull << (k & 63)) - 1));
    return f ? r : k - r;
  }
};
struct DIS {
  vc<int> f;
  vc<int> build(vc<int> a) {
    f = a;
    unique(f);
    for (int &x : a) x = lb(f, x);
    return a;
  }
  int operator[](int x) { return lb(f, x); }
};
using std::move;
struct wave_mat {
  int N, log, sz;
  DIS d;
  vc<int> mid;
  vc<bitvec> bit, bbit;

  void build(vc<int> y, vc<int> yy) {
    N = len(y);
    vc<int> a = d.build(y), aa = yy;
    for (int &x : aa) x = d[x];
    sz = QMAX(a) + 1;

    log = 0;
    while ((1 << log) < sz) ++log;
    mid.resize(log);
    bit.assign(log, bitvec(N));
    bbit.assign(log, bitvec(N));

    vc<int> b(N), bb(N);
    FOR_R(k, log) {
      int p = 0, pp = 0;
      FOR(i, N) {
        if (a[i] >> k & 1) bit[k].set(i), bb[pp++] = a[i];
        else b[p++] = a[i];
      }
      swap(a, b);
      move(bb.begin(), bb.begin() + pp, a.begin() + p);
      mid[k] = p;
      bit[k].build();
    }
    FOR_R(k, log) {
      int p = 0, pp = 0;
      FOR(i, N) {
        if (aa[i] >> k & 1) bbit[k].set(i), bb[pp++] = aa[i];
        else b[p++] = aa[i];
      }
      swap(aa, b);
      move(bb.begin(), bb.begin() + pp, aa.begin() + p);
      bbit[k].build();
    }
  }

  int rank(int L, int R, int y) {
    int p = d[y];
    if (L == R or p == 0) return 0;
    if (p == sz) return R - L;
    int c = 0;
    FOR_R(i, log) {
      int l = bit[i].rank(L, 0), r = bit[i].rank(R, 0);
      int ll = L + mid[i] - l, rr = R + mid[i] - r;
      if (p >> i & 1) c += r - l, L = ll, R = rr;
      else L = l, R = r;
    }
    return c;
  }

  int rrk(int L, int R, int y) {
    int p = d[y];
    if (L == R or p == 0) return 0;
    if (p == sz) return R - L;
    int c = 0;
    FOR_R(i, log) {
      int l = bbit[i].rank(L, 0), r = bbit[i].rank(R, 0);
      int ll = L + mid[i] - l, rr = R + mid[i] - r;
      if (p >> i & 1) c += r - l, L = ll, R = rr;
      else L = l, R = r;
    }
    return c;
  }

  int bina(int L, int R, int L2, int R2, int K) {
    int c = 0, p = 0;
    FOR_R(i, log) {
      int l1 = bit[i].rank(L, 0), r1 = bit[i].rank(R, 0);
      int ll1 = L + mid[i] - l1, rr1 = R + mid[i] - r1;
      int cc = c + r1 - l1;
      int pp = p | 1 << i;
      int l2 = bbit[i].rank(L2, 0), r2 = bbit[i].rank(R2, 0);
      int ll2 = L2 + mid[i] - l2, rr2 = R2 + mid[i] - r2;
      cc -= r2 - l2;
      if (cc < K) {
        tie(p, c, L, R, L2, R2) = {pp, cc, ll1, rr1, ll2, rr2};
      } else {
        tie(L, R, L2, R2) = {l1, r1, l2, r2};
      }
    }
    return d.f[p];
  }
};
T4<vc<int>> work(int N) {
  vc<PII> ls(N), rs(N);
  FOR(i, N) {
    INT(l, r, w);
    ls[i] = {l, w}, rs[i] = {r + 1, w};
  }
  sort(ls), sort(rs);
  vc<int> pl(N), pr(N), wl(N), wr(N);
  FOR(i, N) {
    tie(pl[i], wl[i]) = ls[i];
    tie(pr[i], wr[i]) = rs[i];
  }
  ls.clear(), ls.shrink_to_fit();
  rs.clear(), rs.shrink_to_fit();
  return {std::move(pl), std::move(pr), std::move(wl), std::move(wr)};
}
void Yorisou() {
  INT(N, Q);
  Z [pl, pr, wl, wr] = work(N);
  wave_mat wm;
  wm.build(wl, wr);
  int ans = 0;
  FOR(Q) {
    INT(x, y);
    x ^= ans, y ^= ans;
    int l = ub(pl, x), r = ub(pr, x);
    int k = wm.rank(0, l, y + 1) - wm.rrk(0, r, y + 1);
    ans = k == 0 ? 0 : wm.bina(0, l, 0, r, k);
    print(ans);
    ans &= (1 << 21) - 1;
  }
}
#include "YRS/Z_H/main.hpp"