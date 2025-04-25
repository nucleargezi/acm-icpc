#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/file_io.hpp"

void before() {
#ifdef ONLINE_JUDGE
  FR("input.txt");
  FW("output.txt");
#endif
}

// #define tests
void Yorisou() {
  LL(n, m, k);
  bool v[n][m]{};
  map<string, PLL> M;
  FOR(k) {
    S(op);
    if (op == "+1") {
      LL(x, y);
      --x, --y;
      S(s);
      while (x < n and y < m and v[x][y]) {
        x += ++y / m;
        y %= m;
      }
      if (x == n) continue;
      v[x][y] = 1;
      M[s] = {x, y};
    } else {
      S(s);
      if (M.contains(s)) {
        meion [x, y] = M[s];
        v[x][y] = 0;
        UL(++x, ++y);
        M.extract(s);
      } else {
        UL(-1, -1);
      }
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"