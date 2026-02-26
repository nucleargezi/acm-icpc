#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define ep emplace_back
#define eb emplace
#define Z auto

#define F1(a) for (int _ = 0; _ < (a); ++_)
#define F2(i, a) for (int i = 0; i < (a); ++i)
#define F3(i, a, b) for (int i = (a); i < (b); ++i)
#define F4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define OV(a, b, c, d, e, ...) e
#define FOR(...) OV(__VA_ARGS__, F4, F3, F2, F1)(__VA_ARGS__)
#define FF1(a) for (int _ = (a) - 1; _ >= 0; --_)
#define FF2(i, a) for (int i = (a) - 1; i >= 0; --i)
#define FF3(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define FF4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= c)
#define FOR_R(...) OV(__VA_ARGS__, FF4, FF3, FF2, FF1)(__VA_ARGS__) 

using ll = long long;
using ull = unsigned long long;
template <typename T>
using vc = vector<T>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vc<T>, greater<T>>;

int pc(int x) { return popcount(uint(x)); }
ll pc(ll x) { return popcount(ull(x)); }
int topbit(int x) {
  if (x == 0) return -1;
  return 31 - __builtin_clz(x);
}
int lowbit(int x) {
  if (x == 0) return -1;
  return __builtin_ctz(x);
}

ll len(const Z &x) { return x.size(); }

template <typename T, typename U>
bool chmax(T &a, U b) { return a < b ? a = b, 1 : 0; }
template <typename T, typename U>
bool chmin(T &a, U b) { return a > b ? a = b, 1 : 0; }

#define int ll
constexpr ll in = 9223372036854775807ll;
void Yorisou() {
  int N, M;
  cin >> N >> M;
  vc<int> a(N), b(N);
  for (int &x : a) cin >> x;
  for (int &x : b) cin >> x;
  sort(all(b));
  FOR(i, 1, N) b[i] += b[i - 1];
  a.insert(a.begin(), 0);
  a.ep(M);
  a.erase(unique(all(a)), a.end());
  int sz = len(a);
  vc<int> c(sz - 1, in);
  int pr = -1;
  FOR(i, N) {
    int x = b[i];
    int l = upper_bound(all(a), x) - a.begin();
    --l;
    chmax(l, pr + 1);
    if (l < sz - 1) {
      c[l] = x - a[l];
      pr = l;
    }
  }
  FOR(i, sz - 1) if (c[i] != in and c[i] < 0) c[i] = 0;
  int ans = 0;
  min_heap<int> q;
  FOR(i, sz - 1) {
    if (c[i] == in) {
      ans += a[i + 1] - a[i];
      q.eb(a[i + 1] - a[i]);
      ans -= q.top();
      q.pop();
    } else {
      ans += a[i + 1] - a[i];
      q.eb(a[i + 1] - a[i]);
      int x = q.top();
      ans -= x;
      q.pop();
      x -= c[i];
      ans += max(x, 0ll);
      q.eb(max(x, 0ll));
    }
  }
  cout << ans << '\n';
}
#undef int
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  FOR(T) Yorisou();
  return 0;
}