#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define F(a) for (int i = 0; i < (a); ++i)
#define FF(i, a) for (int i = 0; i < (a); ++i)
#define FFF(i, a, b) for (int i = (a); i < (b); ++i)
#define OV(a, b, c, d, ...) d
#define FOR(...) OV(__VA_ARGS__, FFF, FF, F)(__VA_ARGS__)
#define ep emplace_back
#define len(a) ((int)(a.size()))
#define all(a) a.begin(), a.end()
#define Z auto

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using uu = unsigned __int128;
mt19937 rd(114514);
mt19937_64 rdd(1919810);
uint rng() { return rd(); }
uint rng(uint N) { return rd() % N; }
int rng(int l, int r) { return rd() % (r - l) + l; }

template <typename T>
void shuffle(vector<T> &v) {
  const int N = len(v);
  FOR(i, 1, N) {
    int k = rng(0, i + 1);
    if (i != k) swap(v[i], v[k]);
  }
}

void YES(bool o = 1) { cout << (o ? "YES\n" : "NO\n"); }

constexpr ull mod = (1ull << 61) - 1;
constexpr int sz = 1'000'00 + 10;
ull base[sz];
ull ad(ull a, ull b) { return ((a += b) >= mod) ? a - mod : a; }
ull ml(ull a, ull b) { return uu(a) * b % mod; }
using X = pair<int, ull>;
constexpr X unit = {0, 1};
X fee(X a, X b) { return {max(a.fi, b.fi), ml(a.se, b.se)}; }
X fev(X a, int i) { return {a.fi + 1, a.se}; }
X fve(X a) { return {a.fi, ad(a.se, base[a.fi])}; }
int t = 0;
vector<int> V, fa;
struct DP {
  int N;
  vector<vector<int>> &v;
  vector<X> dp, dp1, dp2;

  DP(vector<vector<int>> &v) : v(v) {
    N = len(v);
    dp1.assign(N, unit);
    for (int i = N; i--; ) {
      int n = V[i];
      for (int t : v[n])
        if (t != fa[n]) dp1[n] = fee(dp1[n], fve(dp1[t]));
      dp1[n] = fev(dp1[n], n);
    }
    
    dp2.assign(N, unit);
    dp.assign(N, unit);
    FOR(i, N) {
      int n = V[i];
      vector<X> ch_dat;
      X x = unit;
      vector<int> ch;
      for (int t : v[n]) {
        if (t == fa[n]) x = fve(dp2[n]);
        else ch.ep(t), ch_dat.ep(fve(dp1[t]));
      }
      int sz = len(ch);
      if (not sz) {
        dp[n] = fev(x, n);
        continue;
      }
      vector<X> L(sz, x);
      FOR(i, sz - 1) L[i + 1] = fee(L[i], ch_dat[i]);
      X R = unit;
      for (int i = sz; i--; ) {
        dp2[ch[i]] = fev(fee(L[i], R), n);
        R = fee(R, ch_dat[i]);
      }
      dp[n] = fev(fee(x, R), n);
    }
  }
  ull operator[](int x) { return dp[x].se; }
};
struct dsu {
  int N;
  vector<int> fa;
  dsu(int N = 0) : N(N), fa(N, -1) {}
  
  int ff(int x) {
    while (fa[x] >= 0) {
      int p = fa[fa[x]];
      if (p < 0) return fa[x];
      x = fa[x] = p;
    }
    return x;
  }
  bool merge(int x, int y) {
    x = ff(x), y = ff(y);
    if (x == y) return 0;
    if (fa[x] > fa[y]) swap(x, y);
    fa[x] += fa[y];
    fa[y] = x;
    return 1;
  }
  int operator[](int i) { return ff(i); }

  void reset() { fill(all(fa), -1); }
};
void Yorisou() {
  int N, M;
  cin >> N >> M;
  vector<int> in(N);
  vector<vector<int>> g(N);
  vector<pair<int, int>> e;
  FOR(i, M) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    e.ep(x, y);
    ++in[x], ++in[y];
  }

  if (M == N - 1) return YES();
  if (N == M and *max_element(all(in)) == 2) return YES();
  if (N > 3 and M == ll(N) * (N - 1) / 2) return YES(0);
  vector<char> vis(N);
  Z f = [&](Z &f, int n) -> void {
    V[t++] = n;
    vis[n] = 1;
    for (int x : g[n]) if (not vis[x]) {
      fa[x] = n;
      f(f, x);
    }
  };
  vector<int> vv;
  V.resize(N);
  fa.resize(N);
  ull dat = rng(), bs = dat;
  dsu uf(N);
  FOR(N > 800 ? 11 : 35) {
    FOR(i, N) g[i].clear();
    uf.reset();
    shuffle(e);
    for (int s = N; Z [x, y] : e) {
      if (uf.merge(x, y)) {
        --s;
        g[x].ep(y), g[y].ep(x);
      }
      if (s == 1) break;
    }
    fill(all(vis), 0);
    t = 0;
    int st = rng(N);
    fa[st] = -1;
    f(f, st);
    DP dp(g);
    ull x = 0;
    FOR(i, N) x = max(x, dp[i]);
    if (dat == bs) dat = x;
    else if (dat != x) return YES(0);
  }
  YES();
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  FOR(i, sz) base[i] = rdd() % mod;
  int T = 1;
  cin >> T;
  while (T--) Yorisou();
}