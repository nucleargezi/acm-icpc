#include <iostream>
#include <algorithm>
#include <ranges>
#include <random>
#include <numeric>

#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>
#include <set>

#include <cstring>
#include <cassert>

using std::cin, std::cout, std::swap;
using std::vector, std::pair, std::map, std::set, std::string, std::array;

using u8 = unsigned char;
using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

bool chmax(auto &x, auto y) { return x < y ? x = y, 1 : 0; }
bool chmin(auto &x, auto y) { return x > y ? x = y, 1 : 0; }
void Yes(bool f = 1) { cout << (f ? "Yes\n" : "No\n"); }
void No(bool f = 1) { Yes(not f); }
int floor(int x, int y) { return x / y - (x % y and (x ^ y) < 0); }
int ceil(int x, int y) { return floor(x + y - 1, y); }

int n, m;

PLL rol(PLL p, int t) {
  auto [x, y] = p;
  if (t == 0) return {x, y};
  if (t == 1) return {-y, x};
  if (t == 2) return {-x, -y};
  return {y, -x};
}

std::mt19937 rd(0);
uint rng() { return rd(); }
uint rng(uint lim) { return rng() % lim; }
int rng(int l, int r) { return rng() % (r - l) + l; }

PLL sub(PLL a, PLL b) {
  return {a.first - b.first, a.second - b.second};
}
PLL add(PLL a, PLL b) {
  return {a.first + b.first, a.second + b.second};
}
void yorisou() {
  cin >> n >> m;
  vector<string> s(n);
  for (auto &x : s) cin >> x;
  int h, w;
  cin >> h >> w;
  vector<string> t(h);
  for (auto &x : t) cin >> x;
  vector<PLL> SS, T;
  for (int i = 0; i < n; ++i) for (int k = 0; k < m; ++k) {
    if (s[i][k] == 'o') SS.emplace_back(i, k);
  }
  for (int i = 0; i < h; ++i) for (int k = 0; k < w; ++k) {
    if (t[i][k] == 'o') T.emplace_back(i, k);
  }
  const int N = T.size();
  
  auto H = [&](ll x, ll y) -> ll {
    return (x << 20) + y;
  };
  set<ll> tse;
  for (auto [x, y] : T) {
    tse.emplace(H(x, y));
  }

  for (int r = 0; r < 4; ++r) {
    vector<PLL> S(N);
    for (int i = 0; i < N; ++i) S[i] = rol(SS[i], r);
    std::ranges::sort(S);
    set<ll> se;
    for (auto [x, y] : S) {
      se.emplace(H(x, y));
    }

    int ch = std::min(N, 100);
    vector<PLL> dif;
    for (int i = 0; i < ch; ++i) {
      for (int k = 0; k < ch; ++k) {
        dif.emplace_back(sub(T[i], S[k]));
      }
    }
    for (int i = 0; i < ch; ++i) {
      for (int k = 0; k < ch; ++k) {
        dif.emplace_back(sub(T[N - 1 - i], S[N - 1 - k]));
      }
    }
    for (int i = 0; i < ch; ++i) {
      for (int k = 0; k < ch; ++k) {
        dif.emplace_back(sub(T[N - 1 - i], S[k]));
      }
    }
    for (int i = 0; i < ch; ++i) {
      for (int k = 0; k < ch; ++k) {
        dif.emplace_back(sub(T[i], S[N - 1 - k]));
      }
    }
    for (int i = 0; i < 1000; ++i) {
      int x = rng(N), y = rng(N);
      dif.emplace_back(sub(T[x], S[y]));
    }
    std::ranges::sort(dif);
    dif.erase(std::unique(dif.begin(), dif.end()), dif.end());

    for (auto t : dif) {
      int c = 0;
      PLL mis{};
      for (auto p : S) {
        auto pp = add(p, t);
        ll id = H(pp.first, pp.second);
        if (not tse.contains(id)) {
          ++c;
          mis = p;
          if (c > 1) break;
        }
      }
      if (c != 1) continue;
      PLL ls{};
      bool f = 0;
      for (auto p : T) {
        auto pp = sub(p, t);
        ll id = H(pp.first, pp.second);
        if (not se.contains(id)) {
          ls = p;
          f = 1;
          break;
        }
      }
      if (not f) continue;
      PLL A = rol(mis, (4 - r) & 3);
      PLL B = rol(sub(ls, t), (4 - r) & 3);
      cout << A.second << ' ' << A.first << '\n';
      cout << B.second << ' ' << B.first << '\n';
      return;
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) yorisou();
  return 0;
}