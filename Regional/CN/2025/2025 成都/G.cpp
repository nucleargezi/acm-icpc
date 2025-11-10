#include <bits/stdc++.h>
using namespace std;
#define F(a) for (int i = 0; i < (a); ++i)
#define FF(i, a) for (int i = 0; i < (a); ++i)
#define FFF(i, a, b) for (int i = (a); i < (b); ++i)
#define OV(a, b, c, d, ...) d
#define FOR(...) OV(__VA_ARGS__, FFF, FF, F)(__VA_ARGS__)
#define Z auto

using ll = long long;
bool chmin(Z &a, Z b) { return a > b ? a = b, 1 : 0; }

void yorisou() {
  ll N, K, M;
  cin >> N >> K >> M;
  if (K > N) return cout << "0\n", void();
  ll ans = min(N, M + 1);
  ll d = N / K - 1;
  chmin(d, N - ans);
  ans += d / 2;
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    yorisou();
  }
  return 0;
}