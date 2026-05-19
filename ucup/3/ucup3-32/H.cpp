#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/bs.hpp"
#include "YRS/ds/basic/queue.hpp"

bool any(const bs &a, const bs &b) {
  int N = si(a.a);
  FOR(i, N) if (a.a[i] & b.a[i]) return 1;
  return 0;
}

bool any1(const bs &a, const bs &b) {
  int N = si(a.a);
  FOR(i, N) {
    ull x = a.a[i], o = (x << 1) | (x >> 1);
    if (i) o |= a.a[i - 1] >> 63;
    if (i + 1 < N) o |= (a.a[i + 1] & 1ull) << 63;
    if (o & b.a[i]) return 1;
  }
  return 0;
}

inline int lz(ull x) { return __builtin_ctzll(x); }

inline int dis(ull x, ull y, int rs) {
  if (not x or not y) return rs;
  if (x & y) return 0;
  if (pc(x) > pc(y)) swap(x, y);
  for (; x; x &= x - 1) {
    int p = lz(x);
    if (p) {
      ull l = y & ((1ull << p) - 1);
      if (l) chmin(rs, p - topbit(l));
    }
    if (p != 63) {
      ull R = y >> (p + 1);
      if (R) chmin(rs, lz(R) + 1);
    }
    if (rs <= 1) break;
  }
  return rs;
}

int sol(const bs &a, const vc<u16> &lp, const bs &b, const vc<u16> &rp, int s) {
  int i, k = 0, j = 0, la = -inf<int>, lb = la;
  while (k < si(lp) or j < si(rp)) {
    if (j == si(rp)) i = lp[k];
    else if (k == si(lp)) i = rp[j];
    else i = min(lp[k], rp[j]);
    int bs = i << 6;
    ull x = 0, y = 0;
    if (k < si(lp) and lp[k] == i) x = a.a[i], ++k;
    if (j < si(rp) and rp[j] == i) y = b.a[i], ++j;
    if (x and lb != -inf<int>) chmin(s, bs + lz(x) - lb);
    if (y and la != -inf<int>) chmin(s, bs + lz(y) - la);
    if (x and y) s = dis(x, y, s);
    if (s <= 1) return s;
    if (x) la = bs + topbit(x);
    if (y) lb = bs + topbit(y);
  }
  return s;
}

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N), rg(N);
  vector to(N, bs(N)), fr(to);
  vc<int> in(N), ou(N);
  FOR(M) {
    INT(f, t);
    --f, --t;
    g[f].ep(t);
    ++ou[t];
    rg[t].ep(f);
    ++in[f];
  }

  queue<int> q;
  FOR(i, N) if (in[i] == 0) q.eb(i);
  FOR(i, N) to[i].set(i);
  while (not q.empty()) {
    int n = pop(q);
    for (int x : rg[n]) {
      to[x] |= to[n];
      if (--in[x] == 0) q.eb(x);
    }
  }
  q.clear();
  FOR(i, N) if (ou[i] == 0) q.eb(i);
  FOR(i, N) fr[i].set(i);
  while (not q.empty()) {
    int n = pop(q);
    for (int x : g[n]) {
      fr[x] |= fr[n];
      if (--ou[x] == 0) q.eb(x);
    }
  }

  vc<u16> c(N), d(N);
  vc<vc<u16>> lp(N), rp(N);

  FOR(i, N) {
    const bs &v = to[i];
    int n = si(v.a);
    c[i] = v.count();
    FOR(k, n) if (v.a[k]) lp[i].ep(k);
  }
  FOR(i, N) {
    const bs &v = fr[i];
    int n = si(v.a);
    d[i] = v.count();
    FOR(k, n) if (v.a[k]) rp[i].ep(k);
  }

  INT(Q);
  FOR(Q) {
    INT(f, t);
    --f, --t;
    if (2 * c[f] >= N and 2 * d[t] >= N) {
      print(not any(to[f], fr[t]));
    } else {
      int s = abs(f - t);
      if (any(to[f], fr[t])) s = 0;
      else if (any1(to[f], fr[t])) s = 1;
      else {
        if (c[f] < d[t]) {
          chmin(s, sol(to[f], lp[f], fr[t], rp[t], s));
        } else {
          chmin(s, sol(fr[t], rp[t], to[f], lp[f], s));
        }
      }
      print(s);
    }
  }
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}