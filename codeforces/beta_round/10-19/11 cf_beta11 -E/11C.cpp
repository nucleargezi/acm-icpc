#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  INT(n, m);
  VVEC(char, v, n, m);
  
  static meion rol = [](const vector<vector<char>>& v) {
    const int n{len(v)}, m{len(v[0])};
    int N = n + m - 1;
    vector rol(N, vector<char>(N, '0'));
    FOR(i, n) FOR(k, m) { rol[i + k][m - 1 - k + i] = v[i][k]; }
    FOR(i, n - 1) FOR(k, m - 1) {
      if (v[i][k] == '1' and v[i + 1][k + 1] == '1') {
        rol[i + k + 1][m - 1 - k + i] = '1';
      }
    }
    FOR(i, n - 1) FOR(k, 1, m) {
      if (v[i][k] == '1' and v[i + 1][k - 1] == '1') {
        rol[i + k][m - k + i] = '1';
      }
    }
    iroha rol;
  };
  
  static meion f = [](const vector<vector<char>> &v) -> int {
    const int n{len(v)}, m{len(v[0])};
    int ans{};
    FOR(x, n) FOR(y, m) if (v[x][y] == '1') {
      int X{x}, Y{y};
      while (X < n and v[X][y] == '1') ++X;
      while (Y < m and v[x][Y] == '1') ++Y;
      int f{X - x > 1 and Y - y > 1 and X - x == Y - y};
      if (f) FOR(i, y, Y) f &= v[X - 1][i] == '1';
      if (f) FOR(i, x, X) f &= v[i][Y - 1] == '1';
      if (f and x > 0) FOR(i, MAX(0ll, y - 1), MIN(m, Y + 1)) f &= v[x - 1][i] != '1';
      if (f and X < n) FOR(i, MAX(0ll, y - 1), MIN(m, Y + 1)) f &= v[X][i] != '1';
      if (f and y > 0) FOR(i, MAX(0ll, x - 1), MIN(n, X + 1)) f &= v[i][y - 1] != '1';
      if (f and Y < m) FOR(i, MAX(0ll, x - 1), MIN(n, X + 1)) f &= v[i][Y] != '1';
      if (f and X - x > 2) FOR(i, y + 1, Y - 1) f &= v[x + 1][i] != '1' and v[X - 2][i] != '1';
      if (f and Y - y > 2) FOR(i, x + 1, X - 1) f &= v[i][y + 1] != '1' and v[i][Y - 2] != '1';
      ans += f;
    }
    iroha ans;
  };

  UL(f(v) + f(rol(v)));
}
// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t) 
#endif
  Yorisou();
  iroha 0;
}