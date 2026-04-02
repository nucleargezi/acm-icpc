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

using ll = long long;
using ull = unsigned long long;

int N, M;

struct Monoid {
  using X = ll;
  static X op(X a, X b) { return max(a, b); }
  static X unit() { return 0; }
  static constexpr bool commute = 1;
};
struct dual_seg {
  using MA = Monoid;
  using A = MA::X;
  int N, log, sz;
  vc<A> a;
  dual_seg(int N) {
    build(N, [&](int i) -> int { return 0; });
  }

  void build(int M, Z f) {
    N = M, log = 1;
    while ((1 << log) < N) ++log;
    sz = 1 << log;
    a.assign(sz << 1, MA::unit());
    FOR(i, N) a[sz + i] = f(i);
  }

  void push(int x) {
    if (a[x] == MA::unit()) return ;
    app(x << 1, a[x]), app(x << 1 | 1, a[x]);
    a[x] = MA::unit();
  }
  void app(int x, A f) { a[x] = MA::op(a[x], f); }

  void apply(int l, int r, const A &f) {
    assert(0 <= l and l <= r and r <= N);
    if (l == r) return;
    l += sz, r += sz;
    if constexpr (not MA::commute) {
      FOR_R(i, 1, log + 1) {
        if (((l >> i) << i) != l) push(l >> i);
        if (((r >> i) << i) != r) push((r - 1) >> i);
      }
    }
    while (l < r) {
      if (l & 1) app(l++, f);
      if (r & 1) app(--r, f);
      l >>= 1, r >>= 1;
    }
  }
  vc<A> get_all() {
    FOR(i, sz) push(i);
    return {a.begin() + sz, a.begin() + sz + N};
  }
};

void yorisou() {
  vc<PII> q(M);
  for (Z &[x, y] : q) cin >> x >> y, --x, --y;
  dual_seg seg(N);
  for (Z [x, y] : q) {
    if (x > y) swap(x, y);
    int d = min(y - x, N - (y - x));
    if (y - x <= N / 2) {
      seg.apply(0, x, d);
      seg.apply(y, N, d);
      seg.apply(x, y, N - d);
    } else {
      seg.apply(x, y, d);
      seg.apply(0, x, N - d);
      seg.apply(y, N, N  - d);
    }
  } 
  cout << QMIN(seg.get_all()) << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // int T = 1;
  // cin >> T;
  while (cin >> N >> M) yorisou();
  // while (T--) yorisou();
  return 0; 
}