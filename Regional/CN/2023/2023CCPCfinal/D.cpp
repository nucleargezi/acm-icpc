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

void Yes(bool o = 1) { cout << (o ? "Yes\n" : "No\n"); }

void Yorisou() {
  int N, M;
  cin >> N >> M;
  vc<int> a(N), b(M);
  FOR(i, N) cin >> a[i];
  FOR(i, M) cin >> b[i];
  bool ok = 1;
  for (int i = 0; int x : b) {
    while (i < N and a[i] != x) ++i;
    if (i >= N or a[i] != x) {
      ok = 0;
      break;
    } else {
      ++i;
    }
  }
  Yes(ok);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  FOR(T) Yorisou();
  return 0;
}