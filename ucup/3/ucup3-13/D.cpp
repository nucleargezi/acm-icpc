#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ep emplace_back
#define eb emplace
#define Z auto
#define all(a) a.begin(), a.end()

using ll = long long;
constexpr int mod = 998244353;
int N, M;
unordered_map<ll, ll> mem;
int f(int n) {
  if (mem.contains(n)) return mem[n];
  if (n & 1) return mem[n] = 1ll * f(n / 2) * mem[1] % mod;
  return mem[n] = (f(n / 2) + f(n / 2 - 1)) % mod;
}
struct X {
  ll a[4][4];
};
X mul(X x, X y) {
  X res{};
  FOR(i, 0, 4) FOR(j, 0, 4) FOR(k, 0, 4) {
    res.a[i][j] += x.a[i][k] * y.a[k][j];
    res.a[i][j] %= mod;
  }
  return res;
}
X pow(X x, ll k) {
  X res{};
  FOR(i, 0, 4) res.a[i][i] = 1;
  while (k) {
    if (k & 1) res = mul(res, x);
    x = mul(x, x);
    k >>= 1;
  }
  return res;
}
void yorisou() {
  cin >> N >> M;
  mem[0] = 1;
  X a{};
  a.a[0][3] = 1;
  a.a[1][3] = 1;
  a.a[2][1] = 1;
  a.a[3][0] = a.a[3][2] = 1;
  a = pow(a, N);
  ll s = (a.a[0][0] + a.a[1][1] + a.a[2][2] + a.a[3][3]) % mod;
  
  mem[1] = s;
  cout << f(M);
}

int main() {
  int T = 1;
  // cin >> T;
  while (T--) yorisou();
  return 0;
}