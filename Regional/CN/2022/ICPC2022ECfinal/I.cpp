#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define ep emplace_back
#define eb emplace
#define Z auto

#define F1(a) for (int _ = 0; _ < (a); ++_)
#define F2(i, a) for (int i = 0; i < (a); ++i)
#define F3(i, a, b) for (int i = (a); i < (b); ++i)
#define F4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define OV(a, b, c, d, e, ...) e
#define FOR(...) OV(__VA_ARGS__, F4, F3, F2, F1)(__VA_ARGS__)
#define FF1(a) for (int _ = (a) - 1; _ >= 0; --_)
#define FF2(i, a) for (int i = (a) - 1; i >= 0; --i)
#define FF3(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define FF4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= c)
#define FOR_R(...) OV(__VA_ARGS__, FF4, FF3, FF2, FF1)(__VA_ARGS__) 

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

template <typename T>
using vc = vector<T>;
template <typename T>
using min_heap = priority_queue<T, vc<T>, greater<T>>;

int pc(int x) { return popcount(uint(x)); }
ll pc(ll x) { return popcount(ull(x)); }
int topbit(int x) {
  if (x == 0) return -1;
  return 31 - __builtin_clz(x);
}
int lowbit(int x) {
  if (x == 0) return -1;
  return __builtin_ctz(x);
}

template <typename T, typename U>
bool chmax(T &a, U b) { return a < b ? a = b, 1 : 0; }
template <typename T, typename U>
bool chmin(T &a, U b) { return a > b ? a = b, 1 : 0; }
template <typename T>
ll len(const T &x) {
  return x.size();
}
template <typename T>
T pop(min_heap<T> &q) {
  Z x = q.top();
  q.pop();
  return x;
}

template <typename T>
void print(const vc<T> &x) {
  for (T a : x) {
    cerr << a << ' ';
  }
  cerr << endl;
}
// #define YRSD
#ifdef YRSD
#define dbg(x) cerr << __LINE__ << " "#x << " : ", print(x)
#else 
#define dbg(...) void(0721)
#endif

constexpr ll inf = 9223372036854775807ll >> 2;
vc<ll> dij(const vc<vc<PII>> &v, int s) {
  int N = len(v);
  vc<ll> dis(N, inf);
  dis[s] = 0;
  min_heap<PLL> q;
  q.eb(0, s);
  while (not q.empty()) {
    Z [d, n] = pop(q);
    if (d != dis[n]) continue;
    for (Z [t, w] : v[n]) {
      if (chmin(dis[t], d + w)) q.eb(dis[t], t);
    }
  }
  return dis;
}
void Yorisou() {
  int N, M, K, D;
  cin >> N >> M >> K >> D;
  --K;
  vc<vc<PII>> g(N);
  FOR(M) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].ep(y, 1);
    g[y].ep(x, 1);
  }
  
  vc<ll> d0 = dij(g, K), dt = dij(g, N - 1);
  dbg(d0);
  dbg(dt);
  vc<char> ban(N);
  FOR(i, N) if (d0[i] >= D) ban[i] = 1;
  min_heap<PLL> q;
  vc<ll> d1(N, inf);
  q.eb(0, 0);
  d1[0] = 0;
  vc<int> pin;
  while (not q.empty()) {
    Z [d, n] = pop(q);
    if (d != d1[n]) continue;
    for (Z [t, w] : g[n]) {
      int dis = d0[t];
      if (dis >= D) w = D;
      else w = D - dis;
      if (chmin(d1[t], d1[n] + w)) {
        if (ban[t]) pin.ep(t);
        else q.eb(d1[t], t);
      }
    }
  }
  sort(all(pin));
  pin.erase(unique(all(pin)), pin.end());
  dbg(pin);
  ll ans = inf;
  for (int s : pin) {
    int dis = dt[s];
    ll w = d1[s];
    int k = dis / D;
    w += k * ll(1 + D) * D / 2;
    k = dis % D;
    w += ll(D - 1 + D - k) * k / 2;
    chmin(ans, w);
  }
  if (d1[N - 1] != inf) chmin(ans, d1[N - 1]);
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  FOR(T) Yorisou();
  return 0;
}