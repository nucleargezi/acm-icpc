#include <bits/stdc++.h>
using namespace std;
#define F(a) for (int i = 0; i < (a); ++i)
#define FF(i, a) for (int i = 0; i < (a); ++i)
#define FFF(i, a, b) for (int i = (a); i < (b); ++i)
#define OV(a, b, c, d, ...) d
#define FOR(...) OV(__VA_ARGS__, FFF, FF, F)(__VA_ARGS__)
#define Z auto
#define all(a) a.begin(), a.end()
#define ep emplace_back
#define eb emplace
#define fi first
#define se second

using ll = long long;
bool chmin(Z &a, Z b) { return a > b ? a = b, 1 : 0; }

int sc[] = {0, 2, 3 + 2, 4 + 3 + 2, 5 + 4 + 3 + 2, 6 + 5 + 4 + 3 + 2,
    7 + 6 + 5 + 4 + 3 + 2};
string ss[] = {"", "2", "23", "234", "2345", "23456", "234567"};

int dp[150][150][2][16][7];
pair<ll, string> fa[150][150][2][16][7];
constexpr int msk = (1 << 10) - 1;
tuple<int, int, int, int, int> make(ll x) {
  return {x >> 40 & msk, x >> 30 & msk, x >> 20 & msk, x >> 10 & msk, x & msk};
}
ll mer(ll a, ll b, ll c, ll d, ll e) {
  return (a << 40) | (b << 30) | (c << 20) | (d << 10) | e;
}
mt19937 rd;
int rng(int l, int r) {
  int x = rd() % (r - l) + l;
  return x;
}
void yorisou() {
  dp[0][0][0][15][6] = 1;
  fa[0][0][0][15][6] = {0, {}};
  queue<ll> q;
  q.emplace(mer(0, 0, 0, 15, 6));
  while (not q.empty()) {
    ll t = q.front();
    q.pop();
    Z [a, b, o, lst, l] = make(t);
    if (lst == 0) {
      if (not l) continue;
      if (not dp[a][b][o ^ 1][lst][l]) {
        dp[a][b][o ^ 1][lst][l] = 1;
        fa[a][b][o ^ 1][lst][l] = {mer(a, b, o, lst, l), "/"};
        q.eb(mer(a, b, o ^ 1, lst, l));
      }
      int g = 8 - l;
      int aa = a, bb = b;
      if (o == 0) aa += g;
      else bb += g;
      if (not dp[aa][bb][o][lst][l - 1]) {
        dp[aa][bb][o][lst][l - 1] = 1;
        fa[aa][bb][o][lst][l - 1] = {mer(a, b, o, lst, l), to_string(g)};
        q.eb(mer(aa, bb, o, lst, l - 1));
      }
    } else {
      if (not dp[a][b][o ^ 1][lst][l]) {
        dp[a][b][o ^ 1][lst][l] = 1;
        fa[a][b][o ^ 1][lst][l] = {mer(a, b, o, lst, l), "/"};
        q.eb(mer(a, b, o ^ 1, lst, l));
      }
      for (int g = 7; g > 1; g--) {
        int aa = a, bb = b;
        if (o == 0) aa += 1 + g;
        else bb += 1 + g;
        if (not dp[aa][bb][o][lst - 1][l]) {
          dp[aa][bb][o][lst - 1][l] = 1;
          fa[aa][bb][o][lst - 1][l] = {mer(a, b, o, lst, l), string("1") + to_string(g)};
          q.eb(mer(aa, bb, o, lst - 1, l));
        }
      }

      int aa = a, bb = b;
      if (o == 0) aa += 1;
      else bb += 1;
      if (not dp[aa][bb][o ^ 1][lst - 1][l]) {
        dp[aa][bb][o ^ 1][lst - 1][l] = 1;
        fa[aa][bb][o ^ 1][lst - 1][l] = {mer(a, b, o, lst, l), "1/"};
        q.eb(mer(aa, bb, o ^ 1, lst - 1, l));
      }
    }
  }
  int Q;
  cin >> Q;
  FOR(Q) {
    int a, b, o, lst;
    cin >> a >> b >> lst >> o;
    if (a > 147 or b > 147) {
      cout << "NA\n";
    } else {
      bool ok = false;
      FOR(k, 7) FOR(i, 16) if (i + k == lst and dp[a][b][o][i][k]) {
        ll t = mer(a, b, o, i, k);
        vector<string> s;
        while (t) {
          Z [a, b, o, lst, l] = make(t);
          // cerr << a << ' ' << b << ' ' << o << ' ' << lst << ' ' << l << '\n';
          s.ep(fa[a][b][o][lst][l].se);
          t = fa[a][b][o][lst][l].fi;
        }
        ok = 1;
        reverse(all(s));
        string ans;
        for (Z &s : s) ans += s;
        cout << ans << '\n';
        break;
      }
      if (not ok) cout << "NA\n";
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  yorisou();
  return 0;
}