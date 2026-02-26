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

#define FF1

#define sort ranges::sort

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
using u8 = unsigned char;
TE using vc = vector<T>;

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

void Yes(bool o = 1) { cout << (o ? "Yes" : "No") << '\n'; }
void No(bool o = 1) { Yes(not o); }

TE Z pop(queue<T> &q) {
  Z x = q.front();
  return q.pop(), x;
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
  for (Z &&e : g.edges) fa.merge(e.f, e.to + N), g.merge(e.to, e.f + N);
  vc<int> c(N << 1, -1);
  FOR(i, N) if (fa[i] == i and c[fa[i]] < 0) c[fa[i]] = 0, c[fa[i + N]] = 1;
  FOR(i, N) if (fa[i] != fa[i + N]) return {};
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

void yorisou() {
  int N;
  cin >> N;
  vc<int> a(N);
  for (int &x : a) cin >> x, --x;
  vc<u8> vis(N);
  FOR(i, 1, N) if (abs(a[i - 1] - a[i]) == 1) vis[min(a[i - 1], a[i])] = 1;
  FOR(i, 1, N - 1) {
    int x = a[i - 1], y = a[i + 1];
    if (x > y) swap(x, y);
    if (y - x == 1) vis[x] = 1;
  }
  int s = 0;
  FOR(i, N) s += vis[i];
  Yes(s == N - 1);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  FOR(T) yorisou();
  return 0;
}