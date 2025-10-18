#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define Z auto 
#define fi first
#define se second

using ll = long long;

bool chmax(Z &a, Z b) { return a < b ? a = b, 1 : 0; }
bool chmin(Z &a, Z b) { return a > b ? a = b, 1 : 0; }

ll bina(const Z &f, ll l, ll r) {
  while (abs(r - l) > 1) {
    ll x = (r + l) >> 1;
    (f(x) ? l : r) = x;
  }
  return l;
}

void yorisou() {
  int N;
  cin >> N;
  vector<int> a(N), b(N);
  FOR(i, 0, N) cin >> a[i] >> b[i];

  Z check = [&](ll mid) -> bool {
    vector<pair<int, int>> v(N);
    FOR(i, 0, N) {
      int x = a[i] >= mid;
      int y = b[i] >= mid;
      v[i] = {x, y};
    }
    int mx = 0, s = 0;
    FOR(i, 0, N) s += v[i].fi;
    mx = s;
    int ss = s;
    queue<int> q;
    for (Z [x, y] : v) {
      int d = y - x;
      s += d;
      q.emplace(d);
      while (s < ss) {
        int d = q.front();
        q.pop();
        s -= d;
      }
      chmax(mx, s);
    }
    return mx >= (N + 1) / 2;
  };
  cout << bina(check, 1, 1'000'000'000 + 1) << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  while (T--) yorisou();
  return 0;
}