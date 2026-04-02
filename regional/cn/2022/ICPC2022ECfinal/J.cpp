#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define ep emplace_back
#define eb emplace

#define F1(a) for (int _ = 0; _ < (a); ++_)
#define F2(i, a) for (int i = 0; i < (a); ++i)
#define F3(i, a, b) for (int i = (a); i < (b); ++i)
#define F4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define OV(a, b, c, d, e, ...) e
#define FOR(...) OV(__VA_ARGS__, F4, F3, F2, F1)(__VA_ARGS__)

using ll = long long;
template <typename T>
using vc = vector<T>;

template <typename T, typename U>
bool chmax(T &a, U b) { return a < b ? a = b, 1 : 0; }
template <typename T, typename U>
bool chmin(T &a, U b) { return a > b ? a = b, 1 : 0; }

void Yorisou() {
  int N;
  cin >> N;
  vc<vc<int>> v(N);
  vc<int> c(N);
  FOR(N - 1) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    v[x].ep(y);
    v[y].ep(x);
    ++c[x], ++c[y];
  }
  FOR(i, N) c[i] = c[i] == 1;
  int s = accumulate(all(c), 0);
  if (s == N or s == N - 1) return cout << "-1\n", void();
  int ans = 0;
  FOR(n, N) {
    int lf = 0;
    for (int x : v[n]) lf += c[x];
    chmax(ans, max(lf, (s + 1) / 2));
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  FOR(T) Yorisou();
  return 0;
}