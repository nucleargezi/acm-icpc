#include <bits/stdc++.h>
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

constexpr int N = 1'000'0;
vector<int> v[N];
int dis[N];

AR split(int x) {
  AR a{};
  FOR(i, 0, 4) {
    a[i] = x % 10;
    x /= 10;
  }
  reverse(all(a));
  return a;
}
int keis(const AR &a) {
  int x = 1000 * a[0] + 100 * a[1] + 10 * a[2] + a[3];
  return x;
}
void yorisou() {
  fill(dis, dis + N, N << 1);
  queue<int> q;
  q.emplace(0);
  FOR(i, 0, N) {
    AR f = split(i);
    FOR(l, 0, 4) FOR(r, l, 4) {
      AR t = f;
      FOR(i, l, r + 1) {
        t[i] += 1;
        if (t[i] > 9) t[i] -= 10;
      }
      v[keis(f)].ep(keis(t));
      
      t = f;
      FOR(i, l, r + 1) {
        t[i] -= 1;
        if (t[i] < 0) t[i] += 10;
      }
      v[keis(f)].ep(keis(t));
    }
  }
  dis[0] = 0;
  q.eb(0);
  while (not q.empty()) {
    int n = q.front();
    q.pop();
    for (int t : v[n]) {
      if (chmin(dis[t], dis[n] + 1)) {
        q.eb(t);
      }
    }
  }
  int T;
  cin >> T;
  while (T--) {
    string f, t;
    cin >> f >> t;
    FOR(i, 0, 4) f[i] -= '0', t[i] -= '0';
    FOR(i, 0, 4) {
      t[i] -= f[i];
      if (t[i] < 0) t[i] += 10;
    }
    int x = 0;
    FOR(i, 0, 4) x = x * 10 + t[i];
    cout << dis[x] << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) yorisou();
  return 0;
}