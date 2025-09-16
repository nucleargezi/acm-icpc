#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  static bool vis[1 << 19];
  vector<int> v;
  meion f = [&](int a = -1, int b = -1, int c = -1, int d = -1,
                int e = -1) -> void {
    int f[5]{a, b, c, d, e};
    FOR(i, 5) if (f[i] != -1) FOR(k, i) {
      int msk = 0;
      FOR(j, k, i + 1) msk |= 1 << f[j];
      v.emplace_back(msk);
    }
  };
  f(0, 1, 2);
  f(3, 4, 5, 6);
  f(7, 8, 9, 10, 11);
  f(12, 13, 14, 15);
  f(16, 17, 18);
  f(0, 3, 7);
  f(1, 4, 8, 12);
  f(2, 5, 9, 13, 16);
  f(6, 10, 14, 17);
  f(11, 15, 18);
  f(2, 6, 11);
  f(1, 5, 10, 15);
  f(0, 4, 9, 14, 18);
  f(3, 8, 13, 17);
  f(7, 12, 16);
  FOR(i, 19) v.emplace_back(1 << i);
  FOR(s, 1 << 19) FOR(i, len(v)) 
    if ((s & v[i]) == v[i] and not vis[s ^ v[i]]) vis[s] = 1;
  int s = 0;
  FOR(i, 19) {
    STR(str);
    if (str == "O") s |= 1 << i;
  }
  UL(vis[s] ? "Karlsson" : "Lillebror");
}
#include "YRS/Z_H/main.hpp"