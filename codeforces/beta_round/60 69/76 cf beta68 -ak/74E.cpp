#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
constexpr int N = 6;
constexpr char t[N][N] = {
  {'0', '1', '2', '3', '4', '5'},
  {'6', '7', '8', '9', 'A', 'B'}, 
  {'C', 'D', 'E', 'F', 'G', 'H'},
  {'I', 'J', 'K', 'L', 'M', 'N'}, 
  {'O', 'P', 'Q', 'R', 'S', 'T'},
  {'U', 'V', 'W', 'X', 'Y', 'Z'}};
void Yorisou() {
  char s[N][N];
  FOR(i, N) FOR(k, N) IN(s[i][k]);
  vector<string> ans;
  Z L = [&](int x) {
    vector<int> a;
    FOR(i, N) a.ep(s[x][i]);
    std::rotate(a.begin(), a.begin() + 1, a.end());
    FOR(i, N) s[x][i] = a[i];
    ans.ep("L" + to_s(x + 1));
  };
  Z R = [&](int x) {
    vector<int> a;
    FOR(i, N) a.ep(s[x][i]);
    std::rotate(a.begin(), a.begin() + N - 1, a.end());
    FOR(i, N) s[x][i] = a[i];
    ans.ep("R" + to_s(x + 1));
  };
  Z U = [&](int x) -> void {
    vector<int> a;
    FOR(i, N) a.ep(s[i][x]);
    std::rotate(a.begin(), a.begin() + 1, a.end());
    FOR(i, N) s[i][x] = a[i];
    ans.ep("U" + to_s(x + 1));
  };
  Z D = [&](int x) -> void {
    vector<int> a;
    FOR(i, N) a.ep(s[i][x]);
    std::rotate(a.begin(), a.begin() + N - 1, a.end());
    FOR(i, N) s[i][x] = a[i];
    ans.ep("D" + to_s(x + 1));
  };

  FOR(i, N) FOR(k, N) {
    int x, y;
    bool ok = false;
    FOR(j, N) if (not ok) {
      FOR(l, N) if (not ok) {
        if (s[j][l] == t[i][k]) {
          x = j, y = l;
          ok = true;
        }
      }
    }
    while (y < k) {
      FOR(i, N - 1) U(y), L(x), D(y), R(x), U(y);
      ++y;
    }
    while (y > k) {
      --y;
      FOR(i, N - 1) U(y), L(x), D(y), R(x), U(y);
    }
    while (x > i) R(x), D(y), L(x), U(y), R(x), --x;
  }
  print(len(ans));
  for (Z &s : ans) print(s);
}
#include "YRS/Z_H/main.hpp"