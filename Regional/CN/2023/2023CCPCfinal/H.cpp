#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define ep emplace_back
#define eb emplace

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

template <typename T, typename U>
bool chmax(T &a, U b) { return a < b ? a = b, 1 : 0; }
template <typename T, typename U>
bool chmin(T &a, U b) { return a > b ? a = b, 1 : 0; }

void Kev(bool o = 1) { cout << (o ? "Kevin\n" : "Qingyu\n"); }

void Yorisou() {
  int N;
  cin >> N;
  N <<= 1;
  vc<int> a(N);
  FOR(i, N) cin >> a[i], --a[i];
  vc<int> c(N);
  for (int x : a) ++c[x];
  int x = 0;
  FOR(i, N) x += max(0, c[i] - 1);
  Kev(x < N / 2);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  FOR(T) Yorisou();
  return 0;
}