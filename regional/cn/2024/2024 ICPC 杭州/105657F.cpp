#include <iostream>
#include <algorithm>
#include <numeric>

#include <vector>
#include <map>
#include <set>

#include <cassert>

using std::cin, std::cout, std::swap;
using std::vector, std::pair, std::set, std::map;

using ll = long long;

bool chmin(auto &x, auto y) {
  return x > y ? x = y, 1 : 0;
}

struct X {
  int ls, lc, rs, rc, sz;
  ll ans;
};
X op(X L, X R) {
  if (L.ls == -1) return R;
  if (R.ls == -1) return L;
  int ls, lc, rs, rc, sz;
  sz = L.sz + R.sz;
  ll ans = L.ans + R.ans;
  ls = L.ls, lc = L.lc;
  if (lc == R.lc and L.sz == ls) {
    ls += R.ls;
  }
  rs = R.rs, rc = R.rc;
  if (rc == L.rc and R.sz == rs) {
    rs += L.rs;
  }
  if (L.rc == R.lc) {
    ans += 1ll * L.rs * R.ls;
  }
  return {ls, lc, rs, rc, sz, ans};
}
X unit() { return {-1, -1, -1, -1, -1, -1}; }

struct segment_tree {
  vector<X> dat;
  int n, sz, log; 

  void build(int N, const auto &f) {
    n = N, log = 1;
    while ((1 << log) < n) ++log;
    sz = 1 << log;
    dat.assign(sz << 1, unit());
    for (int i = 0; i < n; ++i) dat[sz + i] = f(i);
    for (int i = sz - 1; i >= 1; i--) dat[i] = op(dat[i << 1], dat[i << 1 | 1]);
  }

  X prod(int l, int r) {
    X L = unit(), R = unit();
    l += sz, r += sz;
    while (l < r) {
      if (l & 1) L = op(L, dat[l++]);
      if (r & 1) R = op(dat[--r], R);
      l >>= 1, r >>= 1;
    }
    return op(L, R);
  }
};

void yorisou() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<vector<int>> a(k, vector<int>(n));
  vector<vector<int>> v(n);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      --a[i][j];
      if (j) v[a[i][j - 1]].emplace_back(a[i][j]);
    }
  }

  vector<int> dfn(n), low(n), s, id(n);
  vector<char> vis(n);
  int tot = 0, cnt = 0;
  auto f = [&](auto &f, int n) -> void {
    dfn[n] = low[n] = ++tot;
    vis[n] = 1;
    s.emplace_back(n);
    for (int x : v[n]) {
      if (not dfn[x]) {
        f(f, x);
        chmin(low[n], low[x]);
      } else if (vis[x]) {
        chmin(low[n], dfn[x]);
      }
    }
    if (dfn[n] == low[n]) {
      while (1) {
        int x = s.back();
        s.pop_back();
        vis[x] = 0;
        id[x] = cnt;
        if (x == n) break;
      }
      ++cnt;
    }
  };

  for (int i = 0; i < n; ++i) if (not dfn[i]) f(f, i);

  vector<segment_tree> seg(k);
  for (int rk = 0; rk < k; ++rk) {
    seg[rk].build(n, [&](int i) { return X{1, id[a[rk][i]], 1, id[a[rk][i]], 1, 0}; });
  }
  ll ans = 0;

  while (q--) {
    int id, l, r;
    cin >> id >> l >> r;
    id = (id + ans) % k;
    l = (l + ans) % n;
    r = (r + ans) % n;
    ++r;
    cout << (ans = seg[id].prod(l, r).ans) << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) yorisou();
}