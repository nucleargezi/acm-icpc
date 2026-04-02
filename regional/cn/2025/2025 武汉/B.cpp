#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
constexpr bool dbg = 1;
struct Sat {
  int N;
  vector<vector<int>> v;
  vector<int> ans, dfn, low, id, s;
  vector<char> vis;
  int t = 0, c = 0;

  Sat(int N) : N(N), v(N << 1), ans(N), dfn(N << 1), low(N << 1), id(N << 1), vis(N << 1) {};

  void add(int x, int y) {
    v[x].ep(y);
    v[y ^ 1].ep(x ^ 1);
  }
  void ban(int x, int y, int xx, int yy) {
    xx ^= 1, add(x << 1 | xx, y << 1 | yy);
  }
  bool solve() {
    FOR(i, N << 1) if (not dfn[i]) f(i);
    FOR(i, N) {
      if (id[i << 1] == id[i << 1 | 1]) return false;
      ans[i] = id[i << 1] < id[i << 1 | 1];
    }
    return true;
  }
  
  void f(int n) {
    dfn[n] = low[n] = ++t;
    vis[n] = 1;
    s.ep(n);
    for (int x : v[n]) {
      if (not dfn[x]) f(x), chmin(low[n], low[x]);
      else if (vis[x]) chmin(low[n], dfn[x]);
    }
    if (dfn[n] == low[n]) {
      while (1) {
        int x = pop(s);
        id[x] = c;
        vis[x] = 0;
        if (x == n) break;
      }
      ++c;
    }
  }
};
void Yorisou() {
  INT(N);
  vector<vector<int>> v(N);
  FOR(i, 1, N) {
    INT(f);
    --f;
    v[f].ep(i);
  }
  int t = 0;
  vector<vector<int>> p(N);
  vector<int> L(N), R(N), V(N), dis(N);
  Z f = [&](Z &f, int n) -> void {
    p[dis[n]].ep(n);
    V[t] = n;
    L[n] = t++;
    for (int x : v[n]) dis[x] = dis[n] + 1, f(f, x);
    R[n] = t;
  };
  f(f, 0);

  vector<int> bn(N), id(N); // bn bds序第i个点的实际id id 点i的bfn
  int l = 0, r = 0;
  bn[r++] = 0;
  while (l < r) {
    int n = bn[l];
    id[n] = l++;
    for (int x : v[n]) bn[r++] = x;
  }

  vector<vector<int>> g(N);
  INT(Q);
  FOR(Q) {
    INT(x, y);
    --x;
    if (dis[x] + y < N) g[dis[x] + y].ep(x);
  }

  int log = 1;
  while ((1 << log) < N) ++log;
  int sz = 1 << log;
  vector<int> dat(sz << 1, -1);
  FOR(i, N) dat[i + sz] = bn[i];
  t = N;
  FOR(i, sz << 1) if (dat[i] == -1) dat[i] = t++;
  Sat st(sz << 1);
  FOR(i, sz) {
    st.ban(dat[i], dat[i << 1], 1, 0);
    st.ban(dat[i], dat[i << 1 | 1], 1, 0);
  }
  Z apply = [&](int x, int l, int r) {
    l += sz, r += sz;
    while (l < r) {
      if (l & 1) st.ban(x, dat[l++], 1, 1);
      if (r & 1) st.ban(x, dat[--r], 1, 1);
      l >>= 1, r >>= 1;
    }
  };

  FOR(i, N) for (int x : v[i]) st.ban(i, x, 0, 0);

  Z bina = [](Z ck, int l, int r) -> int {
    while (std::abs(r - l) > 1) {
      int x = (l + r) >> 1;
      (ck(x) ? l : r) = x;
    }
    return l;
  };
  FOR(i, N) for (int x : g[i]) {
    r = bina([&](int m) -> bool {
      return m == -1 or L[p[i][m]] < R[x];
    }, -1, len(p[i]));
    l = bina([&](int m) -> bool {
      return m == len(p[i]) or L[p[i][m]] >= L[x];
    }, len(p[i]), -1);
    if (l > r or r == -1 or l == len(p[i])) continue;
    l = id[p[i][l]], r = id[p[i][r]] + 1;
    apply(x, l, r);
  }
  if (dbg) {
    Sat st(N);
    FOR(i, N) for (int x : v[i]) st.ban(i, x, 0, 0);
    FOR(i, N) for (int x : g[i]) {
      int l = L[x], r = R[x];
      for (int y : p[i]) {
        if (L[y] >= l and L[y] < r) st.ban(x, y, 1, 1);
      }
    }
    if (st.solve()) {
      print("dbg", "Yes");
      vector<int> ans;
      FOR(i, N) if (st.ans[i]) ans.ep(i + 1);
      print(ans);
    } else print("dbg No");
  }
  if (st.solve()) {
    Yes();
    vector<int> ans;
    FOR(i, N) if (st.ans[i]) ans.ep(i + 1);
    print(len(ans));
    print(ans);
  } else No();
}
#include "YRS/Z_H/main.hpp"