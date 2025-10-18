#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define Z auto 
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define ep emplace_back

using ll = long long;

constexpr ll base = 131;

struct edge {
  int f, to, id;
  edge(int f = 0, int to = 0, int id = -1) : f(f), to(to), id(id) {}
};

Z sorted(Z a) {
  sort(all(a));
  return a;
}
Z argsort(const Z &a) {
  const int N = a.size();
  vector<int> I(N);
  iota(all(I), 0);
  sort(all(I), [&](int x, int y) -> bool {
    return a[x] != a[y] ? a[x] < a[y] : x < y;
  });
  return I;
}

using i128 = __int128;
constexpr ll mod = (1ll << 61) - 1;
constexpr int N = 1'000'000 + 10;
ll pw[N];
struct H {
  vector<ll> a;
  int N, M;

  H(const vector<string> &s) {
    N = s.size();
    M = s[0].size();
    string g;
    for (const string &s : s) g += s;
    build(g);
  }

  void build(const string &s) {
    const int sz = s.size();
    a.assign(sz + 1, 0);
    FOR(i, 0, sz) {
      a[i + 1] = (i128(a[i]) * base + s[i] - 'a' + 1) % mod;
    }
  }

  ll get(int i, int l, int r) {
    l += i * M, r += i * M;
    return (a[r] - i128(a[l]) * pw[r - l] % mod + mod) % mod;
  }
};
void yorisou() {
  int N, M;
  cin >> N >> M;
  vector<string> a(N), b(N);
  for (Z &s : a) cin >> s;
  for (Z &s : b) cin >> s;

  if (sorted(a) == sorted(b)) {
    Z aa = argsort(a);
    Z bb = argsort(b);
    FOR(i, 0, N) cout << aa[i] + 1 << " \n"[i + 1 == N];
    FOR(i, 0, N) cout << bb[i] + 1 << " \n"[i + 1 == N];
    return;
  }

  H HA(a), HB(b);

  FOR(cut, 1, M) {
    vector<ll> ha(N << 1);
    int t = 0;
    unordered_map<ll, int> mpa, mpb;
    map<pair<int, int>, vector<int>> es;
    
    FOR(i, 0, N) {
      ha[i] = HA.get(i, 0, cut);
      if (not mpa.contains(ha[i])) mpa[ha[i]] = t++;
      ha[i + N] = HA.get(i, cut, M);
      if (not mpb.contains(ha[i + N])) mpb[ha[i + N]] = t++;
      int x = mpa[ha[i]], y = mpb[ha[i + N]];
      es[{x, y}].ep(i);
    }

    vector<int> in(t);
    bool ok = true;
    int ms = 0;
    vector<vector<edge>> v(t);
    map<pair<int, int>, vector<int>> ees;
    for (int i = 0; i < N and ok; ++i) {
      ll hr = HB.get(i, 0, M - cut);
      ll hl = HB.get(i, M - cut, M);
      if (mpb.contains(hr) and mpa.contains(hl)) {
        int x = mpb[hr];
        int y = mpa[hl];
        ++in[x], --in[y];
        v[x].ep(x, y, ms);
        ++ms;
        ees[{x, y}].ep(i);
      } else {
        ok = false;
      }
    }
    if (not ok) continue;

    FOR(i, 0, N) {
      int x = mpa[ha[i]];
      int y = mpb[ha[i + N]];
      ++in[x], --in[y];
      v[x].ep(x, y, ms);
      ++ms;
    }
    for (int i = 0; i < t and ok; ++i) {
      if (in[i] & 1) ok = false;
    }
    if (not ok) continue;

    fill(all(in), 0);
    int s = 0;
    vector<int> c(t), vis(ms), vs;
    ++in[s];
    Z f = [&](Z &f, int n) -> void {
      int sz = v[n].size();
      for (int &i = c[n]; i < sz; ++i) {
        Z e = v[n][i];
        if (not vis[e.id]) {
          --in[e.f];
          ++in[e.to];
          vis[e.id] = 1;
          f(f, e.to);
        }
      }
      vs.ep(n);
    };
    f(f, s);
    if ((int)vs.size() != ms + 1 or vs[0] != vs.back()) continue;
    for (int x : in) if (x < 0) ok = false;
    if (ok == false) continue;

    vector<int> ia, ib;
    reverse(all(vs));
    ll x = ha[0], y = ha[N];
    x = mpa[x], y = mpb[y];
    if (vs[1] != y) reverse(all(vs));
    vs.pop_back();

    FOR(i, 0, N) {
      int x = vs[i << 1], y = vs[i << 1 | 1];
      if (es[{x, y}].empty()) {
        ok = false;
        break;
      }
      ia.ep(es[{x, y}].back());
      es[{x, y}].pop_back();
    }

    for (int i = 1; i < (int)vs.size(); i += 2) {
      int x = vs[i], y = vs[i + 1];
      if (ees[{x, y}].empty()) {
        ok = false;
        break;
      }
      ib.ep(ees[{x, y}].back());
      ees[{x, y}].pop_back();
    }
    if (not ok) continue;
    FOR(i, 0, N) cout << ia[i] + 1 << " \n"[i + 1 == N];
    FOR(i, 0, N) cout << ib[i] + 1 << " \n"[i + 1 == N];
    return;
  }
  cout << "-1\n";
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  pw[0] = 1;
  FOR(i, 1, N) pw[i] = i128(pw[i - 1]) * base % mod;
  cin >> T;
  while (T--) yorisou();
  return 0;
}