#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
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

struct SA {
  int N;
  vector<int> s;
  vector<int> p, rk, height;

  SA(const string &s) : N(s.size()), p(N), rk(N) {
    build(vector<int>{all(s)});
  } 

  void build(const vector<int> &str) {
    s = str;
    int k = 0;
    iota(all(p), 0);
    std::ranges::sort(p, {}, [&](int i) { return s[i]; });
    FOR(i, 0, N) {
      rk[p[i]] = i and s[p[i]] == s[p[i - 1]] ? rk[p[i - 1]] : k++;
    }
    vector<int> q, cnt, newrk(N);
    for (int M = 1; M < N; M <<= 1) {
      q.resize(M);
      iota(all(q), N - M);
      for (int i : p) {
        if (i >= M) q.ep(i - M);
      }
      cnt.assign(k, 0);
      for (int i : rk) {
        ++cnt[i];
      }
      partial_sum(all(cnt), cnt.begin());
      for (int i = N; i--; ) {
        p[--cnt[rk[q[i]]]] = q[i];
      }
      Z cmp = [&](int i, int k) -> bool {
        int rki = i + M < N ? rk[i + M] : -1;
        int rkk = k + M < N ? rk[k + M] : -1;
        return rk[i] == rk[k] and rki == rkk;
      };
      k = 0;
      FOR(i, 0, N) {
        newrk[p[i]] = i and cmp(p[i], p[i - 1]) ? newrk[p[i - 1]] : k++;
      }
      rk.swap(newrk);
    }
    height.resize(N, 0);
    int h = 0;
    FOR(i, 0, N) {
      if (rk[i] == 0) continue;
      if (h > 0) --h;
      int j = p[rk[i] - 1];
      while (i + h < N and j + h < N and s[i + h] == s[j + h]) ++h;
      height[rk[i]] = h;
    }
  }
};
void yorisou() {
  string s;
  cin >> s;
  const int N = s.size();
  SA seg(s);
  Z &p = seg.p, &rk = seg.rk, &ht = seg.height;
  vector<pair<int, int>> ans;
  FOR(i, 0, N) ++rk[i];
  rk.insert(rk.begin(), 0);
  FOR(i, 0, N)++ p[i];
  p.insert(p.begin(), 0);
  ht.insert(ht.begin(), 0);
  s = ' ' + s;
  int now = N;
  int j = now - 1;
  int tmp = ht[N];
  for (int i = N; i >= 1; --i) {
    while (j > 0) {
      if (p[j] > p[now]) {
        tmp = min(tmp, ht[j]);
        j--;
        continue;
      }
      if (i >= p[now] && i - p[now] + 1 > tmp) break;
      now = j;
      j = now - 1;
      tmp = ht[now];
    }
    ans.emplace_back(p[now], i);
  }
  for (int i = N - 1; i >= 0; --i) {
    cout << ans[i].fi << ' ' << ans[i].se << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) yorisou();
  return 0;
}