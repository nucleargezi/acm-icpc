#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/barrett.hpp"

/*
struct DS {
  int bs, sz;
  ll s;
  vc<int> a, to;
  dsu g;
  map<int, int> mp;

  DS(const vc<int> &dat, int l, int r) : to(1'000'01, -1) {
    bs = l, sz = r - l;
    s = 0;
    a.resize(sz);
    g.build(sz);
    FOR(i, sz) a[i] = dat[i + bs], s += a[i], ++mp[a[i]];
    for (int pr = -1; int i : argsort(a)) {
      if (pr != -1 and a[pr] == a[i]) g.merge(pr, i);
      pr = i;
    }
    FOR(i, sz) to[a[i]] = g[i];
  }

  void apply(int l, int r, int c, int d, int w) {
    l -= bs, r -= bs;
    chmax(l, 0);
    chmin(r, sz);
    if (r - l == sz) {
      static vc<map<int, int>::iterator> buf;
      buf.clear();
      int ac = 0;
      for (Z it = mp.lower_bound(c); it != ed(mp) and it->fi < d; ++it) {
        buf.ep(it);
        s -= ll(it->fi) * it->se;
        s += w * it->se;
        ac += it->se;
      }
      if (si(buf)) {
        int ii = to[buf[0]->fi];
        for (Z it : buf) g.merge(ii, to[it->fi]), ii = g[ii];
        ii = g[ii];
        if (to[w] != -1) {
          g.merge(ii, to[w]);
          ii = g[ii];
        }
        for (Z it : buf) to[it->fi] = -1;
        a[ii] = w;
        to[w] = ii;
        for (Z it : buf) mp.erase(it);
        mp[w] += ac;
      }
    } else {
      s = 0;
      for (var [a, b] : mp) to[a] = -1;
      mp.clear();
      FOR(i, sz) a[i] = a[g[i]], s += a[i];
      FOR(i, l, r) {
        if (a[i] < d and a[i] >= c) {
          s -= a[i];
          a[i] = w;
          s += w;
        }
      }
      FOR(i, sz) ++mp[a[i]];
      g.reset();
      for (int pr = -1; int i : argsort(a)) {
        if (pr != -1 and a[pr] == a[i]) g.merge(pr, i);
        pr = i;
      }
      FOR(i, sz) to[a[i]] = g[i];
    }
  }

  ll pow(ll a, ll k, int p) {
    ll s = 1;
    for (; k; k >>= 1, a = a * a % p) {
      if (k & 1) s = s * a % p;
    }
    return s;
  }

  ll prod(int l, int r, int k, int p) {
    l -= bs, r -= bs;
    chmax(l, 0);
    chmin(r, sz);
    ll s = 0;
    if (r - l == sz) {
      for (var [a, b] : mp) {
        s = (s + pow(a, k, p) * b) % p;
      }
    } else {
      static int c[1'000'01];
      FOR(i, l, r) {
        ++c[a[g[i]]];
      }
      FOR(i, l, r) {
        int ii = a[g[i]];
        if (c[ii]) {
          s = (s + pow(ii, k, p) * c[ii]) % p;
          c[ii] = 0;
        }
      }
    }
    return s;
  }
};
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  vc<DS> g;
  static constexpr int B = 1 << 9;
  for (int l = 0, r; l < N; l = r) {
    r = min(N, l + B);
    g.ep(a, l, r);
  }
  ll ans = 0;
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(l, r, c, d, w);
      --l, ++d;
      int ls = l / B, rs = (r - 1) / B;
      FOR(i, ls, rs + 1) g[i].apply(l, r, c, d, w);
    } else {
      INT(l, r, k, p);
      --l;
      int ls = l / B, rs = (r - 1) / B;
      ll s = 0;
      FOR(i, ls, rs + 1) s = (s + g[i].prod(l, r, k, p)) % p;
      ans ^= s;
    }
  }
  print(ans);
}
*/

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  ll ans = 0;
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(l, r, c, d, w);
      --l, ++d;
      FOR(i, l, r) {
        if (a[i] >= c and a[i] < d) a[i] = w;
      }
    } else {
      INT(l, r, k, p);
      --l;
      ll s = 0;
      static int c[1'000'01];
      FOR(i, l, r) ++c[a[i]];
      const barrett bt(p);
      FOR(i, l, r) {
        int x = a[i];
        if (c[x]) {
          s += bt.ml(bt.pow(bt.mo(x), k), c[x]);
          if (s >= p) s -= p;
          c[x] = 0;
        } 
      }
      ans ^= s;
    }
  }
  print(ans);
}

int main() {
  Yorisou();
  return 0;
}