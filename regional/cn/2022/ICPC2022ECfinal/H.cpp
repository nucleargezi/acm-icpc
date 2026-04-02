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
ostream &operator<<(ostream &O, const pair<T, T> &x) {
  return O << x.fi << ' ' << x.se;
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

void md(vc<PII> &a) {
  for (Z &[x, y] : a) ++x;
}
void mvl(vc<PII> &a) {
  for (Z &[x, y] : a) --y;
}
void mvr(vc<PII> &a) {
  for (Z &[x, y] : a) ++y;
}
void adl(vc<PII> &a) {
  Z [x, y] = a[0];
  a.insert(a.begin(), {x, y - 2});
}
void adr(vc<PII> &a) {
  Z [x, y] = a.back();
  a.ep(x, y + 2);
}

vc<PII> s[17];

vc<pair<PII, PII>> v[17][17];
bool vis[17][17], viss[17][17], ok[17][17];
int sz;

map<PII, PII> mp, to;
void go() {
  s[0].ep(0, 0);
  FOR(i, 1, 4) {
    s[i] = s[i - 1];
    md(s[i]);
    mvl(s[i]);
    adr(s[i]);
  }
  s[4] = s[3];
  md(s[4]);
  mvl(s[4]);
  FOR(4) adl(s[4]);
  FOR(5) adr(s[4]);

  FOR(i, 5, 9) {
    s[i] = s[i - 1];
    md(s[i]);
    mvr(s[i]);
    s[i].pop_back();
  }
  FOR(i, 9, 13) {
    s[i] = s[i - 1];
    md(s[i]);
    mvl(s[i]);
    adr(s[i]);
  }
  s[13] = s[12];
  s[13].erase(s[13].begin(), s[13].begin() + 4);
  FOR(5) s[13].pop_back();
  md(s[13]);
  mvr(s[13]);
  FOR(i, 14, 17) {
    s[i] = s[i - 1];
    md(s[i]);
    mvr(s[i]);
    s[i].pop_back();
  }
  FOR(i, 17) FOR(k, len(s[i])) {
    mp[{i, k}] = s[i][k];
    to[s[i][k]] = {i, k};
  }

  FOR(i, 17) dbg(s[i]);
  sz = len(mp);
  // cerr << "Sz: " << sz << '\n';
  for (Z [f, t] : mp) {
    for (Z [ff, tt] : mp) {
      if (f != ff) {
        int x = t.fi + tt.fi, y = t.se + tt.se;
        int dx = t.fi - tt.fi, dy = t.se - tt.se;
        dx = abs(dx), dy = abs(dy);
        // if (t.fi != tt.fi and dx != dy) continue;
        if ((x & 1) or (y & 1)) continue;
        x >>= 1, y >>= 1;
        if (to.contains({x, y})) {
          v[f.fi][f.se].ep(ff, to[{x, y}]);
        }
      }
    }
  }
}
PII SS;
bool can_go(PII f, PII t, PII m) {
  if ((ok[t.fi][t.se] and t != SS) or not ok[m.fi][m.se]) return 0;
  // cerr << "FTM: " << f << ' ' << t << ' ' << m << '\n';
  f = mp[f];
  t = mp[t];
  m = mp[m];
  if (f.fi == t.fi) {
    int l = f.se, r = t.se;
    if (l > r) swap(l, r);
    FOR(i, l + 2, r, 2) if (PII(f.fi, i) != m) {
      if (to.contains({f.fi, i})) {
        Z [x, y] = to[{f.fi, i}];
        if (ok[x][y] and SS != PII{x, y}) return 0;
      }
    }
  } else {
    Z [x, y] = f;
    Z [xx, yy] = t;
    if (abs(xx - x) != abs(yy - y)) return 0;
    int g = abs(xx - x);
    int dx = xx < x ? -1 : 1, dy = yy < y ? -1 : 1;
    // cerr << "F: " << f << " T: " << t << '\n';
    FOR(i, 1, g) {
      int gx = x + dx * i, gy = y + dy * i;
      // cerr << "G: " << gx << ' ' << gy << '\n';
      if (m == PII{gx, gy} or mp[SS] == PII(gx, gy)) continue;
      if (to.contains({gx, gy})) {
        PII id = to[{gx, gy}];
        if (ok[id.fi][id.se]) return 0;
      }
    }
  }
  return 1;
}
constexpr bool fl = 0;
void Yorisou() {
  memset(ok, 0, sizeof ok);
  int N;
  vc<PII> g;
  if (not fl) {
    cin >> N;
    g.resize(N);
    for (Z & [ x, y ] : g) {
      cin >> x >> y;
      --x, --y;
      ok[x][y] = 1;
    }
  } else {
    Z ad = [&](int x, int y) {
      g.ep(x, y);
      ok[x][y] = 1;
    };
    ad(2, 1);
    ad(3, 1), ad(3, 2);
    ad(4, 6);
  }
  // vc<PII> g;

  // ad(4, 5), ad(4, 6), ad(5, 5);

  // FOR(i, 17) FOR(k, len(s[i])) g.ep(i, k), ok[i][k] = 1;
  
  int ans = 0;
  vc<PII> q(sz << 1);
  vc<int> dis(sz << 1);
  bool ret = 0;
  for (Z s : g) {
    SS = s;
    memset(vis, 0, sizeof vis);
    // memset(viss, 0, sizeof viss);
    int l = 0, r = 0, x = s.fi, y = s.se;
    dis[r] = 0;
    q[r++] = {x, y};
    // cerr << "NMSL: " << x << ' ' << y << '\n';
    // vis[x][y] = 1;
    while (l < r) {
      int x = q[l].fi, y = q[l].se, dd = dis[l];
      // cerr << "x y d " << x << ' ' << y << ' ' << dd << '\n';
      ++l;
      for (Z P : v[x][y]) {
        PII t = P.fi, m = P.se;
        // if (t == s and dd <= 1) continue;
        if (t == s) continue;
        if (m != s and can_go(PII{x, y}, t, m)) {
          if (not vis[t.fi][t.se]) {
            vis[t.fi][t.se] = 1;
            ++ans;
            // if (t == s) --ans, ret = 0;
            dis[r] = dd + 1;
            q[r++] = t;
          }
          // if (dd >= 1 and not viss[t.fi][t.se]) {
          //   viss[t.fi][t.se] = 1;
          //   dis[r] = dd + 1;
          //   q[r++] = t;
          // }
        } 
      }
    }
    // cerr << "SN: " << ans << '\n';
  }
  cout << ans + int(ret) << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  go();
  int T = 1;
  if (not fl) cin >> T;
  FOR(T) Yorisou();
  return 0;
}