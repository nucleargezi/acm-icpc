#include <bits/stdc++.h>
using namespace std;

#define TE template <typename T>
#define TES template <typename T, typename ...S>
#define Z auto
#define ep emplace_back
#define eb emplace
#define fi first
#define se second
#define all(x) x.begin(), x.end()

#define OV(a, b, c, d, e, ...) e
#define F1(a) for (int _ = 0; _ < (a); ++_)
#define F2(i, a) for (int i = 0; i < (a); ++i)
#define F3(i, a, b) for (int i = (a); i < (b); ++i)
#define F4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define FOR(...) OV(__VA_ARGS__, F4, F3, F2, F1)(__VA_ARGS__)

#define FF1(a) for (int _ = (a) - 1; _ >= 0; --_)
#define FF2(i, a) for (int i = (a) - 1; i >= 0; --i)
#define FF3(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define FF4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= (c))
#define FOR_R(...) OV(__VA_ARGS__, FF4, FF3, FF2, FF1)(__VA_ARGS__)

#define sort ranges::sort

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
using u8 = unsigned char;
TE using vc = vector<T>;

TE constexpr T inf = numeric_limits<T>::max();

ll len(const Z &x) { return x.size(); }
void reverse(Z &a) { std::reverse(all(a)); }
TE int pc(T x) { return popcount(make_unsigned_t<T>(x)); }
void unique(Z &a) {
  sort(a);
  a.erase(unique(all(a)), a.end());
}
Z QMAX(const Z &a) { return *max_element(all(a)); }
Z QMIN(const Z &a) { return *min_element(all(a)); }
bool chmax(Z &a, Z b) { return a < b ? a = b, 1 : 0; }
bool chmin(Z &a, Z b) { return a > b ? a = b, 1 : 0; }
Z lb(const Z &a, Z x) { return lower_bound(all(a), x) - a.begin(); }
int topbit(int x) {
  return 31 - __builtin_clz(x);
}

void Yes(bool o = 1) { cout << (o ? "Yes" : "No") << '\n'; }
void No(bool o = 1) { Yes(not o); }

TE T pop(queue<T> &q) {
  T x = q.front();
  return q.pop(), x;
}
TE T pop(vc<T> &q) {
  T x = q.back();
  return q.pop_back(), x;
}

TE ostream &operator<<(ostream &O, const vc<T> &a) {
  int n = len(a);
  FOR(i, n) {
    if (i) O << ' ';
    O << a[i];
  }
  return O;
}

template <typename a_monoid>
struct laz_seg {
  using AM = a_monoid;
  using MX = AM::MX;
  using MA = AM::MA;
  using X = MX::X;
  using A = MA::X;
  int N, log, sz;
  vc<X> a;
  vc<A> lz;

  laz_seg() {}
  laz_seg(int N, Z f) {
    build(N, f);
  };
  
  void build(int M, Z f) {
    N = M, log = 1;
    while((1 << log) < N) ++log;
    sz = 1 << log;
    a.assign(sz << 1, MX::unit());
    lz.assign(sz, MA::unit());
    FOR(i, N) a[sz + i] = f(i);
    FOR_R(i, 1, sz) upd(i);
  }
  void upd(int k) { a[k] = MX::op(a[k << 1], a[k << 1 | 1]); }

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

using LL = ll;

constexpr ll mod = 998244353;

constexpr ll pw(ll a, ll b) {
  ll s = 1;
  for (; b; b >>= 1, a = a * a % mod) 
    if (b & 1) s = s * a % mod;
  return s;
}
constexpr ll inv(ll a) {
  return pw(a, mod - 2);
}

using dat = array<array<ll, 2>, 2>;
constexpr dat get() {
  return {array<ll, 2>{1, 0}, array<ll, 2>{0, 1}};
}

constexpr dat mul(const dat &a, const dat &b) {
    dat res{};
    FOR(i, 2) FOR(j, 2) FOR(k, 2) res[i][j] += a[i][k] * b[k][j];
    FOR(i, 2) FOR(k, 2) res[i][k] %= mod;
    return res;
  }

dat gen(int i) {
  i %= 3;
  dat s{};
  if (i == 0) {
    s[0][0] = s[0][1] = 1;
    s[1][1] = mod - 1;
  } else if (i == 1) {
    s[0][0] = s[1][0] = 1;
    s[1][1] = mod - 1;
  } else if (i == 2) {
    s[0][1] = s[1][1] = 1;
    s[0][0] = mod - 1;
  }
  return s;
}

struct MX {
  using X = array<dat, 3>;
  static constexpr X unit() {
    X res{get(), get(), get()};
    return res;
  }
  static X op(const X &a, const X &b) {
    X res{};
    FOR(i, 3) res[i] = mul(a[i], b[i]);
    return res;
  }
};
struct MA {
  using X = int;
  static X unit() { return 0; }
  static X op(X a, X b) { return (a + b) % 3; }
};
struct AM {
  using MX = ::MX;
  using MA = ::MA;
  using X = MX::X;
  using A = MA::X;
  static X act(const X &x, A f, int) {
    X res{};
    FOR(i, 3) res[i] = x[(i + f) % 3];
    return res;
  }
};
void yorisou() {
  int N, Q;
  string s;
  cin >> N >> Q >> s;
  FOR(i, N) s[i] -= '0';

  laz_seg<AM> seg(N, [&](int i) {
    MX::X res{};
    FOR(k, 3) res[k] = gen(s[i] + k);
    return res;
  });

  FOR(Q) {
    int op, l, r;
    cin >> op >> l >> r;
    --l;
    if (op == 1) {
      seg.apply(l, r, 1);
    } else {
      Yes(seg.prod(l, r) == MX::unit());
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  FOR(T) yorisou();
  return 0;
}