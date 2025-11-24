#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define eb emplace
#define ep emplace_back
#define Z auto
#define all(a) a.begin(), a.end()
#define F(a) for (int i = 0; i < (a); ++i)
#define FF(i, a) for (int i = 0; i < (a); ++i)
#define FFF(i, a, b) for (int i = (a); i < (b); ++i)
#define OV(a, b, c, d, ...) d
#define FOR(...) OV(__VA_ARGS__, FFF, FF, F)(__VA_ARGS__)

using ll = long long;
using X = pair<ll, int>;

template <typename cmp = less<X>>
struct heap {
  priority_queue<X, vector<X>, cmp> q, e;
  X top() { return q.top(); }
  void pop() { q.pop(), bina(); }
  void pop(X x) { e.eb(x), bina(); }
  void emplace(X x) { q.eb(x); }
  void bina() {
    while (not e.empty() and q.top() == e.top()) q.pop(), e.pop();
  }
  bool empty() { return q.empty(); }
};

void sol() {
  int N;
  cin >> N;
  vector<ll> v(N), l(N);
  FOR(i, N) cin >> v[i];
  FOR(i, N) cin >> l[i];
  int Q;
  cin >> Q;
  vector<ll> t(Q);
  FOR(i, Q) cin >> t[i];
  vector<int> I(Q);
  iota(all(I), 0);
  sort(all(I), [&](int i, int k) { return t[i] < t[k]; });
  heap q;
  heap<greater<X>> qq;
  FOR(i, N) q.eb({l[i], i});
  FOR(i, N) qq.eb({v[i], i});
  vector<ll> ans(Q);
  ll s = 0, cut = 0;
  FOR(i, N) s += v[i];
  FOR(i, N) cut += l[i];
  Z f = [&](int i, int t) -> bool {
    ll V = v[i], L = l[i];
    return t * L <= V;
  };
  for (int i : I) {
    int tm = t[i];
    while (not q.empty()) {
      Z [lmax, i] = q.top();
      Z [vmin, ii] = qq.top();
      if (f(i, tm) and f(ii, tm)) {
        if (i == ii) break;
        if (s - v[i] - v[ii] + max(v[i], v[ii]) -
                (cut - l[i] - l[ii] + min(l[i], l[ii])) * tm >
            s - cut * tm) {
          q.pop(), qq.pop();
          qq.pop({v[i], i});
          q.pop({l[ii], ii});
          s -= v[i] + v[ii];
          cut -= l[i] + l[ii];
          v[i] = max(v[i], v[ii]);
          l[i] = min(l[i], l[ii]);
          s += v[i];
          cut += l[i];
          q.eb({l[i], i});
          qq.eb({v[i], i});
          continue;
        }
        break;
      }
      if (i == ii) {
        q.pop(), qq.pop();
        s -= vmin;
        cut -= lmax;
      } else {
        q.pop(), qq.pop();
        qq.pop({v[i], i});
        q.pop({l[ii], ii});
        s -= v[i] + v[ii];
        cut -= l[i] + l[ii];
        v[i] = max(v[i], v[ii]);
        l[i] = min(l[i], l[ii]);
        s += v[i];
        cut += l[i];
        q.eb({l[i], i});
        qq.eb({v[i], i});
      }
    }
    ans[i] = s - cut * tm;
  }
  FOR(i, Q) cout << ans[i] << " \n"[i + 1 == Q];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while (T--) sol();
  return 0;
}