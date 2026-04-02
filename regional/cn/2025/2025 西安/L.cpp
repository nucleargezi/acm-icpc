#include <bits/stdc++.h>
using namespace std;

#define F(a) for (int i = 0; i < (a); ++i)
#define FF(i, a) for (int i = 0; i < (a); ++i)
#define FFF(i, a, b) for (int i = (a); i < (b); ++i)
#define OV(a, b, c, d, ...) d
#define FOR(...) OV(__VA_ARGS__, FFF, FF, F)(__VA_ARGS__)
#define all(a) a.begin(), a.end()
#define ep emplace_back
using ll = long long;

void yorisou() {
  int N;
  cin >> N;
  vector<ll> a(N);
  FOR(i, N) cin >> a[i];
  sort(all(a));
  ll s = accumulate(all(a), 0ll);
  vector<ll> ans;
  int l = 0, r = N - 1;
  while (r - l + 1 >= 3) {
    while (l and a[r] * 2 >= s) s += a[--l], s -= a[r--];
    ans.ep(a[r] * 2 < s ? s : 0);
    s -= (a[r] * 2 < s - a[l]) ? a[l++] : a[r--];
  }
  while ((int)ans.size() < N) ans.ep(0);
  reverse(all(ans));
  FOR(i, N) cout << ans[i] << " \n"[i + 1 == N];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) yorisou();
  return 0;
}