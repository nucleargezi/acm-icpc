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

template <typename T = int, bool dir = 0>
struct graph {
  struct E {
    int f, to;
    T w;
    int id;
  };
  int N, M = 0;
  vc<vc<E>> g;
  vc<E> edges;
  graph(int N) : N(N), g(N) {}
  void add(int x, int y, T w = 1) {
    edges.ep(E{x, y, w, M});
    g[x].ep(E{x, y, w, M});
    if (not dir) g[y].ep(E{y, x, w, M});
    ++M;
  }
  Z &operator[](int i) { return g[i]; }
  const Z &operator[](int i) const { return g[i]; }
};

#define TG template <typename GT>

struct dsu {
  vc<int> fa;
  dsu(int N) : fa(N, -1) {}
  int f(int x) {
    while (fa[x] >= 0) {
      int p = fa[fa[x]];
      if (p < 0) return fa[x];
      x = fa[x] = p;
    }
    return x;
  }
  int operator[](int i) { return f(i); }
  bool merge(int x, int y) {
    x = f(x), y = f(y);
    if (x == y) return 0;
    if (fa[x] > fa[y]) swap(x, y);
    fa[x] += fa[y];
    fa[y] = x;
    return 1;
  }
};
TG vc<int> coloring01(const GT &g) {
  int N = g.N;
  dsu fa(N << 1);
  for (Z &&e : g.edges) fa.merge(e.f, e.to + N), fa.merge(e.to, e.f + N);
  vc<int> c(N << 1, -1);
  FOR(i, N) if (fa[i] == i and c[fa[i]] < 0) c[fa[i]] = 0, c[fa[i + N]] = 1;
  FOR(i, N) if (fa[i] == fa[i + N]) return {};
  FOR(i, N) c[i] = c[fa[i]];
  return c.resize(N), c;
}
TG struct BM {
  int N;
  GT &g;
  vc<int> col, dis, mat;
  vc<u8> vis;

  BM(GT &g) : N(g.N), g(g), dis(N, -1), mat(N, -1) {
    col = coloring01(g);
    if (N > 0) assert(not col.empty());
    while (1) {
      bfs();
      vis.assign(N, 0);
      int f = 0;
      FOR(i, N) if (not col[i] and mat[i] == -1 and dfs(i)) ++f;
      if (not f) break;
    }
  }
  void bfs() {
    fill(all(dis), -1);
    queue<int> q;
    FOR(i, N) if (not col[i] and mat[i] == -1) q.eb(i), dis[i] = 0;
    while (not q.empty()) {
      int n = pop(q);
      for (Z &&e : g[n]) {
        dis[e.to] = 0;
        int w = mat[e.to];
        if (w != -1 and dis[w] == -1) dis[w] = dis[n] + 1, q.eb(w);
      }
    }
  }
  bool dfs(int n) {
    vis[n] = 1;
    for (Z &&e : g[n]) {
      int w = mat[e.to];
      if (w == -1 or (not vis[w] and dis[w] == dis[n] + 1 and dfs(w))) {
        mat[e.to] = n, mat[n] = e.to;
        return 1;
      }
    }
    return 0;
  }
  vc<PII> matching() {
    vc<PII> res;
    FOR(i, N) if (i < mat[i]) res.ep(i, mat[i]);
    return res;
  }
};

TE struct max_flow {
  struct edge {
    int to, rev;
    T cap, flow = 0;
  };

  int N, SS, TT;
  vc<vc<edge>> es;
  vc<PII> pos;
  vc<int> prog, le;
  vc<int> q;
  bool ok;
  max_flow() {}
  max_flow(int N, int SS, int TT) 
      : N(N), SS(SS), TT(TT), es(N), ok(0), ans(0) {}
  
  void add(int f, int t, T cap, T rev_cap = 0) {
    ok = 0;
    int a = len(es[f]);
    int b = f == t ? a + 1 : len(es[t]);
    pos.ep(f, a);
    es[f].ep(edge{t, b, cap, 0});
    es[t].ep(edge{f, a, rev_cap, 0});
  }

  T ans;

  bool set_level() {
    q.resize(N);
    le.assign(N, -1);
    le[SS] = 0;
    int l = 0, r = 0;
    q[r++] = SS;
    while (l < r) {
      int x = q[l++];
      for (Z &&e : es[x]) {
        if (e.cap > 0 and le[e.to] == -1) {
          le[e.to] = le[x] + 1;
          if (e.to == TT) return true;
          q[r++] = e.to;
        }
      }
    }
    return false;
  }

  T dfs(int x, T lm) {
    if (x == TT) return lm;
    T res = 0;
    for (int &i = prog[x]; i < len(es[x]); ++i) {
      Z &e = es[x][i];
      if (e.cap > 0 and le[e.to] == le[x] + 1) {
        T a = dfs(e.to, min(lm, e.cap));
        if (a > 0) {
          e.cap -= a, e.flow += a;
          es[e.to][e.rev].cap += a, es[e.to][e.rev].flow -= a;
          res += a;
          lm -= a;
          if (lm == 0) break;
        }
      }
    }
    return res;
  }

  vc<u8> vis;
  T flow() {
    if (ok) return ans;
    ok = true;
    while (set_level()) {
      prog.assign(N, 0);
      while (1) {
        T x = dfs(SS, inf<T>);
        if (x == 0) break;
        ans += x;
        chmin(ans, inf<T>);
        if (ans == inf<T>) return ans;
      }
    }
    return ans;
  }

  vc<tuple<int, int, T>> get_flow_edges() {
    vc<tuple<int, int, T>> res;
    FOR(frm, N) {
      for (Z &&e : es[frm]) {
        if (e.flow <= 0) continue;
        res.ep(frm, e.to, e.flow);
      }
    }
    return res;
  }
};

void yorisou() {
  int L, R, M;
  cin >> L >> R >> M;
  int N = L + R;
  vc<PII> e(M);
  graph g(N);
  map<PII, bool> mp;
  for (Z &[x, y] : e) {
    cin >> x >> y;
    --x, --y;
    y += L;
    g.add(x, y);
    mp[{x, y}] = 1;
  }
  int a = N, b = 0;
  BM f(g);
  vc<PII> mts = f.matching();
  a -= 2 * len(mts);
  vc<int> in(N);
  for (Z [x, y] : mts) {
    mp[{x, y}] = 0;
    ++in[x], ++in[y];
  }
  int s = N, t = s + 1;
  max_flow<int> fl(t + 1, s, t);
  for (Z [e, ok] : mp) {
    int x = e.fi, y = e.se;
    if (not ok) {
      fl.add(y, x, 1);
    } else {
      fl.add(x, y, 1);
    }
  }
  FOR(i, L) if (in[i] == 0) fl.add(s, i, 1);
  FOR(i, L, N) if (in[i] == 1) fl.add(i, t, 1);
  int d = fl.flow();
  a -= d, b += d;
  for (Z [f, to, w] : fl.get_flow_edges()) {
    if (f == s) {
      ++in[to];
    } else if (to == t) {
      ++in[f];
    } else {
      mp[{min(f, to), max(f, to)}] = f < to;
    }
  }
  fl = max_flow<int>(t + 1, s, t);
  FOR(i, L) if (in[i] == 1) fl.add(s, i, 1);
  FOR(i, L, N) if (in[i] == 0) fl.add(i, t, 1);
  for (Z [e, ok] : mp) {
    int x = e.fi, y = e.se;
    if (not ok) {
      fl.add(y, x, 1);
    } else {
      fl.add(x, y, 1);
    }
  }
  d = fl.flow();
  a -= d, b += d;
  cout << a << ' ' << b << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  FOR(T) yorisou();
  return 0;
}