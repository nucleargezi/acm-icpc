#include <bits/stdc++.h>
using namespace std;

#define F1(a) for (int i = 0; i < (a); ++i)
#define F2(i, a) for (int i = 0; i < (a); ++i)
#define F3(i, a, b) for (int i = (a); i < (b); ++i)
#define FF1(a) for (int i = a - 1; i > -1; --i)
#define FF2(i, a) for (int i = a - 1; i > -1; --i)
#define FF3(i, a, b) for (int i = b - 1; i >= a; --i)
#define OV(a, b, c, d, ...) d
#define FOR(...) OV(__VA_ARGS__, F3, F2, F1)(__VA_ARGS__)
#define FOR_R(...) OV(__VA_ARGS__, FF3, FF2, FF1)(__VA_ARGS__)
#define all(a) a.begin(), a.end()
#define ep emplace_back
#define eb emplace
#define Z auto
#define fi first
#define se second
#define len(a) ((int)(a.size()))
#define pc(x) popcount(x)
using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;

constexpr bool dbg = 0;
mt19937 rd(0);

int LB(const vector<int> &a, int x) { return lower_bound(all(a), x) - a.begin(); }
vector<int> rearrange(const vector<int> &a, const vector<int> &I) {
  const int N = len(a);
  vector<int> b(N);
  FOR(i, N) b[i] = a[I[i]];
  return b;
}

struct monoid_max {
  using X = int;
  static constexpr X unit() { return -1; }
  static constexpr X op(X a, X b) { return max(a, b); }
};
struct monoid_max_pair {
  using X = PII;
  static constexpr X unit() { return {-1, 0}; }
  static constexpr X op(X a, X b) { return max(a, b); }
};
struct monoid_add {
  using X = int;
  static constexpr X unit() { return 0; }
  static constexpr X op(X a, X b) { return a + b; } 
};
template <typename mono>
struct Seg {
  using MX = mono;
  using X = MX::X;
  int N, log, sz;
  vector<X> dat;

  void upd(int i) { 
    dat[i] = MX::op(dat[i << 1], dat[i << 1 | 1]); 
  }

  void build(int M) {
    build(M, [&](int) { return MX::unit(); });
  }
  void build(const vector<X> &a) {
    build(len(a), [&](int i) -> X { return a[i]; });
  }
  void build(int M, Z f) {
    N = M, log = 1;
    while ((1 << log) < N) ++log;
    sz = 1 << log;
    dat.assign(sz << 1, MX::unit());
    FOR(i, N) dat[i + sz] = f(i);
    FOR_R(i, 1, sz) upd(i);
  }
  X prod(int l, int r) {
    X x = MX::unit(), y = MX::unit();
    l += sz, r += sz;
    while (l < r) {
      if (l & 1) x = max(x, dat[l++]);
      if (r & 1) y = max(y, dat[--r]);
      l >>= 1, r >>= 1;
    }
    return max(x, y);
  }
  X prod_all() { return dat[1]; }
  void set(int i, X x) {
    dat[i += sz] = x;
    while (i >>= 1) upd(i);
  }
  void apply(int i, X x) {
    i += sz;
    dat[i] = MX::op(dat[i], x);
    while (i >>= 1) upd(i);
  }
};

struct bitvec {
  int N;
  vector<pair<ull, int>> s;
  bitvec(int N = 0) : N(N), s((N + 127) >> 6) {}
  void set(int i) { s[i >> 6].fi |= 1ull << (i & 63); }
  void build() {
    int N = len(s) - 1;
    FOR(i, N) s[i + 1].se += s[i].se + pc(s[i].fi);
  }
  int rank(int k, bool f = 1) const {
    Z [a, b] = s[k >> 6];
    int r = b + pc(a & ((1ull << (k & 63)) - 1));
    return f ? r : k - r;
  }
};
struct DIS {
  vector<int> f;
  vector<int> build(vector<int> v) {
    f = v;
    sort(all(f));
    f.erase(unique(all(f)), f.end());
    for (int &x : v) x = LB(f, x);
    return v;
  }
  int operator[](int i) { return LB(f, i); }
};
#define g90() int l = bit[i].rank(L, 0), r = bit[i].rank(R, 0), \
                  ll = L + mid[i] - l,   rr = R + mid[i] - r
struct wave {
  int N, log, sz;
  DIS dis;
  vector<int> mid;
  vector<bitvec> bit;
  vector<Seg<monoid_add>> seg;

  void build(const vector<int> &y, vector<int> x) {
    N = len(y);
    vector<int> a = dis.build(y);
    sz = *max_element(all(a)) + 1;
    log = 0;
    while ((1 << log) < sz) ++log;
    mid.resize(log);
    bit.assign(log, bitvec(N));

    vector<int> b(N), bb(N);
    vector<int> s(N), ss(N);
    seg.resize(log + 1);
    seg[log].build(x);
    FOR_R(k, log) {
      int p = 0, pp = 0;
      FOR(i, N) {
        if (a[i] >> k & 1) {
          bit[k].set(i), bb[pp] = a[i], ss[pp] = x[i];
          ++pp;
        } else {
          b[p] = a[i], s[p] = x[i];
          ++p;
        }
      }
      swap(a, b);
      swap(x, s);
      move(bb.begin(), bb.begin() + pp, a.begin() + p);
      move(ss.begin(), ss.begin() + pp, x.begin() + p);
      mid[k] = p;
      bit[k].build();
      seg[k].build(x);
    }
  }

  int prod(int L, int R, int d, int u) {
    int l = dis[d], r = dis[u];
    int t = 0;
    Z f = [&](Z &f, int i, int L, int R, int ql, int qr) -> void {
      if (r <= ql or qr <= l) return;
      if (l <= ql and qr <= r) {
        t += seg[i].prod(L, R);
        return;
      }
      --i;
      int m = (ql + qr) >> 1;
      g90();
      f(f, i, l, r, ql, m), f(f, i, ll, rr, m, qr);
    };
    f(f, log, L, R, 0, 1 << log);
    return t;
  }

  void set(int i, int x) {
    int L = i, R = i + 1;
    seg[log].set(i, x);
    FOR_R(i, log) {
      g90();
      if (l < r) L = l, R = r;
      if (l == r) L = ll, R = rr;
      seg[i].set(L, x);
    }
  }
};
struct diff_dis {
  vector<int> f;
  vector<int> build(vector<int> v) {
    int N = len(v);
    vector<int> r(N), I(N);
    iota(all(I), 0);
    sort(all(I),
        [&](int i, int k) { return v[i] == v[k] ? i < k : v[i] < v[k]; });
    for (int t = 0; int i : I) {
      r[i] = t++;
      f.ep(v[i]);
    }
    return r;
  }
  int operator[](int i) { return LB(f, i); }
};
struct DS {
  wave seg;
  diff_dis dis;
  int N;
  vector<int> id;
  
  template <typename F>
  void build(int M, F f) {
    N = M;
    vector<int> X(N), Y(N), S(N);
    FOR(i, N) tie(X[i], Y[i], S[i]) = f(i);
    id = dis.build(X);
    vector<int> I(N);
    FOR(i, N) I[id[i]] = i;
    Y = rearrange(Y, I);
    S = rearrange(S, I);
    seg.build(Y, S);
  }

  int prod(int l, int r, int y, int yy) {
    return seg.prod(dis[l], dis[r], y, yy);
  }
  void set(int i, int x) { seg.set(id[i], x); }
};
struct mono {
  using X = pair<PII, PII>;
  static constexpr X unit() { return {{-1, 0}, {-1, 0}}; }
  static constexpr X op(X L, X R) {
    if (L.fi.fi == -1) return R;
    if (R.fi.fi == -1) return L;
    Z [a, b] = L;
    Z [c, d] = R;
    if (c > a) swap(a, b), swap(a, c);
    else if (c == a) a.se += c.se;
    else if (c > b) swap(b, c);
    else if (c == b) b.se += c.se;
    if (d > a) swap(a, b), swap(a, d);
    else if (d == a) a.se += d.se;
    else if (d > b) swap(b, d);
    else if (d == b) b.se += d.se;
    return {a, b};
  }
  static constexpr X make(int x) { return {{x, 1}, {-1, 0}}; }
};
void yorisou() {
  int N, Q;
  cin >> N >> Q;
  vector<pair<int, int>> a(N);
  vector<int> f;
  for (Z &[x, y] : a) cin >> x >> y, f.ep(x), f.ep(y);
  vector<tuple<int, int, int>> quis(Q);
  for (Z &[i, x, y] : quis) {
    cin >> i >> x >> y;
    --i;
    f.ep(x), f.ep(y);
  }
  sort(all(f));
  f.erase(unique(all(f)), f.end());
  const int sz = len(f);
  for (Z &[x, y] : a) x = LB(f, x), y = LB(f, y);
  for (Z &[i, x, y] : quis) x = LB(f, x), y = LB(f, y);
  DS wm;
  wm.build(N + Q, [&](int i) -> tuple<int, int, int> {
    if (i < N) return {a[i].se, a[i].fi, 1};
    Z [id, x, y] = quis[i - N];
    return {y, x, 0};
  });
  Seg<mono> mx;
  mx.build(N, [&](int i) { return mono::make(a[i].fi); });
  Seg<monoid_max_pair> mxidx;
  mxidx.build(N, [&](int i)  { return pair{a[i].fi, i}; });
  Z put = [&]() -> void {
    Z [A, B] = mx.prod_all();
    Z [mx, c] = A;
    int mm = B.fi;
    if (c > 1) {
      cout << max(1, wm.prod(mx + 1, sz, 0, sz)) << '\n';
    } else {
      int id = mxidx.prod_all().se;
      int df = a[id].se;
      int ans = wm.prod(mx + 1, sz, 0, sz) - (df > mx) + (df > mm);
      cout << max(1, ans) << '\n';
    }
  };
  put();
  vector<int> I(N);
  iota(all(I), 0);
  FOR(i, Q) {
    Z [id, x, y] = quis[i];
    mx.set(id, mono::make(x));
    mxidx.set(id, {x, id});
    wm.set(I[id], 0);
    I[id] = i + N;
    wm.set(i + N, 1);
    a[id] = {x, y};
    put();
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  if (dbg) T = 1'000'000'0;
  while (T--) yorisou();
  return 0;
}