#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ep emplace_back
#define eb emplace
#define Z auto
#define all(a) a.begin(), a.end()

using ll = long long;

void yorisou() {
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int &x : a) cin >> x;
  
  vector<vector<pair<int, int>>> v(K);
  FOR(i, 0, N) v[i % K].ep(i, i);
  FOR(i, 0, K) {
    Z &vv = v[i];
    int sz = vv.size();
    for (int i = sz - 1; i > 0; --i) {
      if (a[vv[i].second] > a[vv[i - 1].second]) {
        vv[i - 1].second = vv[i].second;
      }
    }
  }
  int p = -1, idx = 0;
  vector<int> ans;
  while (p < N) {
    Z &vv = v[idx];
    int sz = vv.size();
    int i = upper_bound(all(vv), pair{p, p}) - vv.begin();
    if (i == sz) break;
    Z [id, rid] = vv[i];
    ans.ep(a[rid]);
    p = rid;
    idx = (idx + 1) % K;
  }
  int sz = ans.size();
  FOR(i, 0, sz) cout << ans[i] << " \n"[i + 1 == sz];
}

int main() {
  int T = 1;
  // cin >> T;
  while (T--) yorisou();
  return 0;
}