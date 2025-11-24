#include <bits/stdc++.h>
using namespace std;

#define eb emplace
#define ep emplace_back
#define Z auto
#define all(a) a.begin(), a.end()
#define F(a) for (int i = 0; i < (a); ++i)
#define FF(i, a) for (int i = 0; i < (a); ++i)
#define FFF(i, a, b) for (int i = (a); i < (b); ++i)
#define OV(a, b, c, d, ...) d
#define FOR(...) OV(__VA_ARGS__, FFF, FF, F)(__VA_ARGS__)

using ll = long long;

struct dsu {
  vector<int> fa;
  dsu(int N = 0) : fa(N, -1) {}
  int f(int x) {
    while (fa[x] >= 0) {
      int p = fa[fa[x]];
      if (p < 0) return fa[x];
      x = fa[x] = p;
    }
    return x;
  }
  bool mer(int x, int y) {
    x = f(x), y = f(y);
    if (x == y) return 0;
    if (fa[x] > fa[y]) swap(x, y);
    fa[x] += fa[y];
    fa[y] = x;
    return 1;
  }
};
int l, r, q[100000];
void sol() {
  int N, Q;
  cin >> N >> Q;
  vector g(1 << 12, dsu(N));
  dsu f(N);
  ll ans = 0;
  FOR(Q) {
    char op;
    cin >> op;
    if (op == '+') {
      int x, y, w;
      cin >> x >> y >> w;
      --x, --y;
      f.mer(x, y);
      l = r = 0;
      q[r++] = w;
      while (l < r) {
        int s = q[l++];
        if (not g[s].mer(x, y)) continue;
        for (int x = s, t; x; x -= x & -x) {
          t = s - (x & -x);
          q[r++] = t;
        }
      }
    } else {
      int x, y;
      cin >> x >> y;
      --x, --y;
      int s = 0;
      if (f.f(x) != f.f(y)) {
        s = -1;
      } else {
        for (int i = 12; i--;) {
          if (g[1 << i | s].f(x) == g[1 << i | s].f(y)) {
            s |= 1 << i;
          }
        }
      }
      ans += s;
    }
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while (T--) sol();
  return 0;
}