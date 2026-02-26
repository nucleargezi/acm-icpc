#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define Z auto
#define ep emplace_back
#define eb emplace
#define all(a) a.begin(), a.end()
#define F1(a) for (int _ = 0; _ < (a); ++_)
#define F2(i, a) for (int i = 0; i < (a); ++i)
#define F3(i, a, b) for (int i = (a); i < (b); ++i)
#define F4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define FF1(a) for (int _ = (a) - 1; _ >= 0; --_)
#define FF2(i, a) for (int i = (a) = 1; i >= 0; --i)
#define FF3(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define FF4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= (c))
#define OV(a, b, c, d, e, ...)e
#define FOR(...) OV(__VA_ARGS__, F4, F3, F2, F1)(__VA_ARGS__)
#define FOR_R(...) OV(_VA_ARGS__, FF4, FF3, FF2, FF1)(__VA_ARGS__)

using ll = long long;
using PII = pair<int, int>;
template <typename T>
using vc = vector<T>;

constexpr ll len(const Z &s) { return s.size(); }
int topbit(int x) {
  if (x == 0) return -1;
  return 31 - __builtin_clz(x);
}

int bina(Z f, int l, int r) {
  assert(f(l));
  while (abs(r - l) > 1) {
    int x = (l + r) >> 1;
    (f(x) ? l : r) = x;
  }
  return l;
}

struct E {
  int to, lc, rc;
  E(int x, int y, int z) : to(x), lc(y), rc(z) {}
};

template <typename T>
T pop(queue<T> &q) {
  T x = q.front();
  q.pop();
  return x;
}

void Yorisou() {
  int N, M, K;
  cin >> N >> M >> K;
  vc<vc<E>> v(N);
  vc<map<int, int>> mp(N);
  FOR(M) {
    int f, t, lc, rc;
    cin >> f >> t >> lc >> rc;
    --f, --t;
    v[f].ep(t, lc, rc);
    v[t].ep(f, lc, rc);
  }
  queue<PII> q;
  vc<char> vis(N);
  vc<PII> ans;
  FOR(i, N) {
    for (Z &&e : v[i]) ++mp[i][e.rc];
    if (len(mp[i]) == 1) q.eb(i, mp[i].begin()->fi), vis[i] = 1;
    if (mp[i].empty()) q.eb(i, 1), vis[i] = 1;
  }
  while (not q.empty()) {
    Z [n, c] = pop(q);
    ans.ep(n, c);
    for (Z &&e : v[n]) if (not vis[e.to]) {
      if (mp[e.to].contains(c)) {
        --mp[e.to][c];
        if (mp[e.to][c] == 0) mp[e.to].erase(c);
      }
      if (len(mp[e.to]) == 1)
        q.eb(e.to, mp[e.to].begin()->fi), vis[e.to] = 1;
    }
  }
  reverse(all(ans));
  map<ll, int> g;
  for (Z [n, c] : ans) {
    for (Z &&e : v[n]) {
      int x = n, y = e.to;
      if (x > y) swap(x, y);
      g[ll(x) << 30 | y] = c;
    }
  }
  FOR(n, N) {
    for (Z &&e : v[n]) {
      int x = n, y = e.to;
      if (x > y) swap(x, y);
      ll h = ll(x) << 30 | y;
      if (g.contains(h)) {
        if (g[h] != e.rc) return cout << "-1\n", void();
      } else {
        if (e.lc != e.rc) return cout << "-1\n", void();
      }
    }
  }
  cout << len(ans) << '\n';
  for (Z [x, y] : ans) cout << x + 1 << ' ' << y << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) Yorisou();
  return 0;
}