#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define Z auto 
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define ep emplace_back


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

void fail() { cout << "-1\n"; }

bool check(int K, int N, int M, vector<int> a, vector<int> b) {
  priority_queue<int, vector<int>, greater<int>> q;
  FOR(i, 0, N) q.emplace(a[i]);
  FOR(i, 0, K) {
    int x = q.top();
    q.pop();
    q.emplace(x + 1);
    q.pop();
  }
  a.clear();
  while (not q.empty()) a.ep(q.top()), q.pop();
  N -= K;
  int d = N - M;
  ll s = 0;
  FOR(i, 0, M) {
    s += b[i] - a[i + d];
    if (b[i] > a[i + d]) return false;
  }
  return s == d;
}

void yorisou() {
  int N, M;
  cin >> N >> M;
  vector<int> a(N), b(M);
  for (int &x : a) cin >> x;
  for (int &x : b) cin >> x;
  sort(all(a));
  sort(all(b));

  if (N == M) {
    if (a == b) cout << "0\n";
    else cout << "-1\n";
    return;
  }

  int D = N - M;
  Z check = [&](int m) -> bool {
    if (m == -1) return true;
    priority_queue<int, vector<int>, greater<int>> q;
    FOR(i, 0, N) q.emplace(a[i]);
    FOR(i, 0, m) {
      int x = q.top();
      q.pop();
      q.emplace(x + 1);
      q.pop();
    }
    vector<int> a;
    while (not q.empty()) {
      a.ep(q.top());
      q.pop();
    }
    int N = a.size();
    int d = N - M;
    ll s = 0;
    FOR(i, 0, M) {
      if (b[i] < a[i + d]) return false;
      s += b[i] - a[i + d];
    }
    return s < d;
  };
  int m = bina(check, -1, D) + 1;
  vector<int> ans;
  priority_queue<int, vector<int>, greater<int>> q;
  FOR(i, 0, N) q.emplace(a[i]);
  FOR(i, 0, m) {
    int x = q.top();
    ans.ep(x);
    q.pop();
    q.emplace(x + 1);
    q.pop();
  }
  a.clear();
  while (not q.empty()) {
    a.ep(q.top());
    q.pop();
  }
  N = a.size();
  int d = N - M;
  ll s = 0;
  FOR(i, 0, M) {
    if (b[i] < a[i + d]) return fail();
    s += b[i] - a[i + d];
  }
  if (s != d) return fail();
  for (int i = M; i--; ) {
    while (b[i] > a[i + d]) {
      ans.ep(a[i + d]++);
    }
  }
  int sz = ans.size();
  cout << sz << '\n';
  FOR(i, 0, sz) cout << ans[i] << " \n"[i + 1 == sz];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) yorisou();
  return 0;
}