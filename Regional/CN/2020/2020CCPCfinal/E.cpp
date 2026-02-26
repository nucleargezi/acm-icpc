#include <bits/stdc++.h>
using namespace std;

#define TE template <typename T>
#define fi first
#define se second
#define Z auto
#define all(x) x.begin(), x.end()
#define ep emplace_back
#define eb emplace


#define F1(a) for (int _ = 0; _ < (a); ++_)
#define F2(i, a) for (int i = 0; i < (a); ++i)
#define F3(i, a, b) for (int i = (a); i < (b); ++i)
#define F4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define OV(a, b, c, d, e, ...) e
#define FOR(...) OV(__VA_ARGS__, F4, F3, F2, F1)(__VA_ARGS__)

#define FF1(a) for (int _ = (a) - 1; _ >= 0; --_)
#define FF2(i, a) for (int i = (a) - 1; i >= 0; --i)
#define FF3(i, a, b) for (int i = (b) - 1; i >= 0; --i)
#define FOR_R(...) OV(__VA_ARGS__, FF3, FF3, FF2, FF1)(__VA_ARGS__)

#define sort ranges::sort

using ll = long long;
using ull = unsigned long long;
TE using vc = vector<T>;
using PII = pair<int, int>;
mt19937 rd(114514);
int rng(int l, int r) {
  return rd() % (r - l) + l;
}

bool chmax(Z &a, Z b) {  return a < b ? a = b, 1 : 0; }
bool chmin(Z &a, Z b) {  return a > b ? a = b, 1 : 0; }

Z QMAX(const Z &a) { return *max_element(all(a)); } 
Z QMIN(const Z &a) { return *min_element(all(a)); } 

int topbit(int x) {
  if (x == 0) return -1;
  return 31 - __builtin_clz(x);
}

using ll = long long;
using ull = unsigned long long;

template <typename a_monoid>
struct lazy_seg {
  using AM = a_monoid;
  using MX = AM::MX;
  using MA = AM::MA;
  using X = MX::X;
  using A = MA::X;
  int N, log, sz;
  vc<X> a;
  vc<A> lz;

  lazy_seg() {};
  lazy_seg(int N, Z f) { build(N, f); }

  void build(int M, Z f) {
    N = M, log = 1;
    while ((1 << log) < N) ++log;
    sz = 1 << log;
    a.assign(sz << 1, MX::unit());
    lz.assign(sz, MA::unit());
    FOR(i, N) a[sz + i] = f(i);
    FOR_R(i, 1, sz) upd(i);
  }

  void upd(int k) { a[k] = MX::op(a[k << 1], a[k << 1 | 1]); };
  void app(int k, A f) {
    a[k] = AM::act(a[k], f, 1 << (log - topbit(k)));
    if (k < sz) lz[k] = MA::op(lz[k], f);
  }
  void push(int k) {
    if (lz[k] == MA::unit()) return;
    app(k << 1, lz[k]), app(k << 1 | 1, lz[k]);
    lz[k] = MA::unit();
  }
  void apply(int l, int r, A f) {
    if (l == r) return;
    l += sz, r += sz;
    FOR_R(i, 1, log + 1) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }
    int cl = l, cr = r;
    while (l < r) {
      if (l & 1) app(l++, f);
      if (r & 1) app(--r, f);
      l >>= 1, r >>= 1;
    }
    l = cl, r = cr;
    FOR(i, 1, log + 1) {
      if (((l >> i) << i) != l) upd(l >> i);
      if (((r >> i) << i) != r) upd((r - 1) >> i);
    }
  }
  X prod(int l, int r) {
    if (l == r) return MX::unit();
    l += sz, r += sz;
    FOR_R(i, 1, log + 1) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }
    X ls = MX::unit(), rs = MX::unit();
    while (l < r) {
      if (l & 1) ls = MX::op(ls, a[l++]);
      if (r & 1) rs = MX::op(a[--r], rs);
      l >>= 1, r >>= 1;
    }
    return MX::op(ls, rs);
  }
};

struct MX {
  struct X {
    int c;
    ll s, rs;
  };
  static X op(X a, X b) {
    return {a.c + b.c, a.s + b.s, a.rs + b.rs};
  }
  static X unit() {
    return {0, 0, 0};
  }
};
struct MA {
  using X = char;
  static X op(X a, X b) { return a ^ b; }
  static X unit() { return 0; }
};
struct AM {
  using MX = ::MX;
  using MA = ::MA;
  using X = MX::X;
  using A = MA::X;
  static X act(X a, A f, int sz) {
    if (f) return {sz - a.c, a.rs, a.s};
    return a;
  }
};

int N, Q;

void yorisou() {
  string s;
  cin >> s;
  FOR(i, N) s[i] -= '0';
  lazy_seg<AM> seg(N, [&](int i) -> MX::X {
    if (s[i]) return {1, i + 1, 0};
    return {0, 0, i + 1};
  });
  FOR(Q) {
    int l, r;
    cin >> l >> r;
    --l;
    seg.apply(l, r, 1);
    Z [cnt, sum, rs] = seg.prod(0, N);
    cout << ((sum - cnt * ll(cnt + 1) / 2) * 2 + cnt) % 998244353 << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // int T = 1;
  // cin >> T;
  while (cin >> N >> Q) yorisou();
  // while (T--) yorisou();
  return 0; 
}