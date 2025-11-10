#include <bits/stdc++.h>
using namespace std;

#define F(a) for (int i = 0; i < (a); ++i)
#define FF(i, a) for (int i = 0; i < (a); ++i)
#define FFF(i, a, b) for (int i = (a); i < (b); ++i)
#define OV(a, b, c, d, ...) d
#define FOR(...) OV(__VA_ARGS__, FFF, FF, F)(__VA_ARGS__)
#define all(a) a.begin(), a.end()
#define ep emplace_back
#define Z auto

using ll = long long;

int bina(Z f, int l, int r) {
  f(l);
  while (abs(r - l) > 1) {
    int x = (l + r) >> 1;
    (f(x) ? l : r) = x;
  }
  return l;
}
constexpr bool dbg = 0;
mt19937 rd(0);

void yorisou() {
  int N;
  string s;
  if (dbg) {
    N = 20;
    FOR(N) {
      int x = rd() % 3;
      s += x == 0 ? 'C' : x == 1 ? 'W' : 'P';
    }
  } else {
    cin >> N >> s;
  }
  vector<int> a(N);
  FOR(i, N) a[i] = s[i] == 'C' ? 0 : s[i] == 'W' ? 1 : 2;
  vector<array<int, 3>> c(N + 1);
  FOR(i, N) c[i + 1][a[i]] += 1;
  FOR(i, 1, N + 1) FOR(k, 3) c[i][k] += c[i - 1][k];
  
  vector<char> L(N), R(N);
  FOR(i, 1, N) L[i] = a[i] == a[i - 1];
  FOR(i, N - 1) R[i] = a[i] == a[i + 1];
  FOR(i, 1, N) L[i] |= L[i - 1];
  for (int i = N - 2; i >= 0; --i) R[i] |= R[i + 1];
  if (not L[N - 1]) {
    if (not dbg)
      return cout << "Beautiful\n", void();
    else
      return;
  }

  Z f = [&](int l, int r) -> bool {
    if (l + 1 == r) return 1;
    int t[3]{};
    FOR(i, 3) t[i] = c[r][i] - c[l][i];
    sort(t, t + 3);
    return t[2] - 1 <= t[0] + t[1];
  };

  Z get = [&](int l, int r) -> vector<pair<int, int>> {
    if (l + 1 == r) return vector{pair{a[l], a[l]}};
    int t[3]{};
    FOR(i, 3) t[i] = c[r][i] - c[l][i];
    int I[3]{0, 1, 2};
    sort(I, I + 3, [&](int i, int k) -> bool {
      return t[i] == t[k] ? i < k : t[i] < t[k];
    });
    int x = I[0], y = I[1], z = I[2];
    if (t[x] == 0) {
      if (t[y] == t[z] - 1) return vector{pair{z, z}};
      else if (t[y] == t[z]) return vector{pair{y, z}, {z, y}};
      else return vector{pair{y, y}, {y, z}, {z, y}, {z, z}};
    } else {
      if (t[x] + t[y] == t[z] - 1) return vector{pair{z, z}};
      if (t[x] + t[y] == t[z]) return vector{pair{x, z}, {z, x}, {y, z}, {z, y}, {z, z}};
      return vector{pair{x, z}, {z, x}, {y, z}, {z, y}, {x, y}, {y, x}, {x, x}, {y, y}, {z, z}};
    }
  };

  if (not f(0, N)) {
    if (not dbg) return cout << "Impossible\n", void();
    else return;
  }
  int pl = 0, pr = 0, ls = 0, rs = 0;
  bina([&](int sz) -> bool {
    FOR(i, N - sz + 1) if ((i ? not L[i - 1] : 1) and (i + sz != N ? not R[i + sz] : 1) and
        f(i, i + sz)) {
      for (Z [l, r] : get(i, i + sz)) {
        bool ok = 1;
        if (i) ok &= l != a[i - 1];
        if (i + sz != N) ok &= r != a[i + sz];
        if (ok) {
          ls = l, rs = r;
          pl = i, pr = i + sz;
          return true;
        }
      }
    }
    return false;
  }, N, 1);

  vector<int> res(N, -1);
  Z make = [&](int l, int r, int ls, int rs) -> void {
    if (l + 1 == r) return res[l] = a[l], void();
    int t[3]{};
    FOR(i, 3) t[i] = c[r][i] - c[l][i];
    int I[3]{0, 1, 2};
    sort(I, I + 3, [&](int i, int k) -> bool {
      return t[i] == t[k] ? i < k : t[i] < t[k];
    });
    int x = I[0], y = I[1], z = I[2];
    if (t[x] == 0) {
      if (t[y] == t[z] - 1) {
        FOR(i, l, r) res[i] = ((i & 1) == (l & 1)) ? z : y;
      } else {
        int a = ls, b = a ^ y ^ z;
        FOR(i, l, r) res[i] = ((i - l) & 1) ? b : a;
      }
    } else {
      if (t[x] + t[y] == t[z] - 1) {
        for (int i = l; i < r; i += 2) res[i] = z;
        for (int i = l + 1; i < r; i += 2) {
          if (t[x]) --t[x], res[i] = x;
          else res[i] = y;
        }
      } else if (t[x] + t[y] == t[z]) {
        if (ls != rs) {
          if (ls == z) {
            for (int i = l; i < r; i += 2) res[i] = z;
            for (int i = l + 1; i < r; i += 2) {
              if (rs == x) res[i] = t[y] ? --t[y], y : x;
              else res[i] = t[x] ? --t[x], x : y;
            }
          } else {
            for (int i = l + 1; i < r; i += 2) res[i] = z;
            for (int i = l; i < r; i += 2) {
              if (ls == x) res[i] = t[x] ? --t[x], x : y;
              else res[i] = t[y] ? --t[y], y : x;
            }
          }
        } else {
          vector<int> g{z};
          --t[z];
          while (t[z]) {
            if (t[x]) --t[x], g.ep(x), g.ep(z);
            else --t[y], g.ep(y), g.ep(z);
          }
          vector<int> c{g[0]};
          FOR(i, 1, (int)g.size()) {
            while (1) {
              bool f = 0;
              if (t[x] and x != c.back() and x != g[i]) --t[x], c.ep(x), f = 1;
              if (t[y] and y != c.back() and y != g[i]) --t[y], c.ep(y), f = 1;
              if (not f) break;
            }
            c.ep(g[i]);
          }
          FOR(i, l, r) res[i] = c[i - l];
        }
      } else {
        --t[ls], --t[rs];
        vector<int> q{ls};
        sort(I, I + 3, [&](int i, int k) -> bool {
          return t[i] == t[k] ? i < k : t[i] < t[k];
        });
        int x = I[0], y = I[1], z = I[2];
        if (t[z] and z != ls) q.ep(z), --t[z];
        while (t[z]) {
          if (t[x]) q.ep(x), q.ep(z), --t[x], --t[z];
          else q.ep(y), q.ep(z), --t[y], --t[z];
        }
        if (rs == z) {
          if (t[x]) --t[x], q.ep(x), q.ep(rs);
          else --t[y], q.ep(y), q.ep(rs);
        } else {
          q.ep(rs);
        }
        vector<int> c{ls};
        for (int i = 1; i < (int)q.size(); ++i) {
          while (1) {
            bool f = 0;
            if (t[x] and x != c.back() and x != q[i]) {
              c.ep(x);
              --t[x];
              f = 1;
            }
            if (t[y] and y != c.back() and y != q[i]) {
              c.ep(y);
              --t[y];
              f = 1;
            }
            if (not f) break;
          }
          c.ep(q[i]);
        }
        assert((int)c.size() == r - l);
        FOR(i, l, r) res[i] = c[i - l];
      }
    }
  };
  make(pl, pr, ls, rs);
  FOR(i, pl) res[i] = a[i];
  FOR(i, pr, N) res[i] = a[i];
  string ans;
  FOR(i, N) ans += res[i] == 0 ? 'C' : res[i] == 1 ? 'W' : 'P';
  if (dbg) {
    // cerr << "Sz: " << sz << '\n';
    FOR(i, N - 1) if (ans[i] == ans[i - 1]) {
      cerr << s << '\n';
      cerr << ans << '\n';
      exit(0);
    }
  } else {
    cout << "Possible\n";
    cout << pl + 1 << ' ' << pr << '\n';
    cout << ans << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  if (dbg) T = 1'000'000'0;
  else cin >> T;
  while (T--) yorisou();
  return 0;
}