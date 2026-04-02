#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FO(i, n) for (int i = 0; i < (n); ++i)
#define fi first
#define se second
#define Z auto
#define ep emplace_back
#define eb emplace
#define all(a) a.begin(), a.end()

using ll = long long;
using u8 = unsigned char;
using AR = array<int, 4>;

bool chmin(Z &x, Z y) {
  return x > y ? x = y, 1 : 0;
}
bool chmax(Z &x, Z y) {
  return x < y ? x = y, 1 : 0;
}

using RE = long double;
using P = complex<RE>;
constexpr RE eps = 1e-10;
RE len(P x) { return sqrtl(x.imag() * x.imag() + x.real() * x.real()); }
constexpr int N = 3;
array<P, 4> a[N], p[N];
pair<P, P> wz[N];
void yorisou() {
  FOR(i, 0, N) FOR(k, 0, N + 1) p[i][k] = {};
  int N = 3;
  FOR(i, 0, N) {
    P w, z;
    RE e, r, t, y;
    cin >> e >> r >> t >> y;
    w = {e, r}, z = {t, y};
    wz[i] = {w, z};
    a[i][0] = z;
    a[i][1] = w;
    a[i][2] = -1;
    a[i][3] = -w * z;
  }
  bool f1 = 0;
  FOR(i, 0, N) {
    bool gg = 1;
    FOR(j, 0, N) {
      if (len(a[i][j]) <= eps) continue;
      if (len(p[j][j]) > eps) {
        if (len(p[j][j]) < len(a[i][j])) {
          FOR(k, j, N + 1) {
            swap(p[j][k], a[i][k]);
          }
        }
        P cc = a[i][j] / p[j][j];
        FOR(k, j, N + 1) {
          a[i][k] -= cc * p[j][k];
        }
      } else {
        FOR(k, j, N + 1) {
          p[j][k] = a[i][k];
        }
        gg = 0;
        break;
      }
    }
    if (gg) f1 = 1;
  }
  vector<P> ans(N);
  for (int i = N; i--; ) {
    P s{};
    for (int k = N - 1; k > i; k--) {
      s += ans[k] * p[i][k];
    }
    ans[i] = (p[i][N] - s) / p[i][i];
  }
  FOR(i, 0, N) FOR(k, 0, N + 1) p[i][k] = {};
  if (f1) {
    int N = 2;
    FOR(i, 0, N) {
      a[i][0] = wz[i].fi;
      a[i][1] = wz[i].se;
      a[i][2] = {1, 0};
    }

    bool f1 = 0;
    FOR(i, 0, N) {
      bool gg = 1;
      FOR(j, 0, N) {
        if (len(a[i][j]) <= eps) continue;
        if (len(p[j][j]) > eps) {
          if (len(p[j][j]) < len(a[i][j])) {
            FOR(k, j, N + 1) {
              swap(p[j][k], a[i][k]);
            }
          }
          P cc = a[i][j] / p[j][j];
          FOR(k, j, N + 1) {
            a[i][k] -= cc * p[j][k];
          }
        } else {
          FOR(k, j, N + 1) {
            p[j][k] = a[i][k];
          }
          gg = 0;
          break;
        }
      }
      if (gg) f1 = 1;
    }
    vector<P> ans(N);
    for (int i = N; i--; ) {
      P s{};
      for (int k = N - 1; k > i; k--) {
        s += ans[k] * p[i][k];
      }
      ans[i] = (p[i][N] - s) / p[i][i];
    }
    if (f1) {
      P p{};
      RE x, y;
      cin >> x >> y;
      P in_w{x, y};
      FOR(i, 0, 3) {
        if (wz[i].fi != P{0, 0}) {
          Z [w, z] = wz[i];
          p = z / w * in_w;
          return cout << p.real() << ' ' << p.imag() << '\n', void();
        }
      }
    }

    P A = ans[0], B = ans[1];
    P w;
    RE x, y;
    cin >> x >> y;
    w = {x, y};
    P z = (P{1, 0} - A * w) / B;
    cout << z.real() << ' ' << z.imag() << '\n';
    return;
  } 
  P A = ans[0], B = ans[1], C = ans[2];
  P w;
  RE x, y;
  cin >> x >> y;
  w = {x, y};
  P z = (C - B * w) / (w + A);
  cout << z.real() << ' ' << z.imag() << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cout << fixed << setprecision(15);
  cin >> T;
  while (T--) yorisou();
  return 0;
}