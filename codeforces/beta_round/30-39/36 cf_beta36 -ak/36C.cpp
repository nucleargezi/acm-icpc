#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/file_io.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

void before() {
#ifdef ONLINE_JUDGE
  FR("input.txt");
  FW("output.txt");
#endif
}

// #define tests
using RE = long double;
using P = point<RE>;
void Yorisou() {
  LL(n);
  vector<segment<RE>> seg;
  FOR(n) {
    LL(h, r, R);
    RE x = 0;
    for (meion[a, b] : seg) {
      chmax(x, a.x);
      if (a.y <= r and b.y >= r) {
        chmax(x, a.x + (b.x - a.x) / (b.y - a.y) * (r - a.y));
      }
      if (a.y <= R and b.y >= R) {
        chmax(x, a.x + (b.x - a.x) / (b.y - a.y) * (R - a.y) - h);
      }
      if (b.y < r) {
        chmax(x, b.x);
      }
      if (b.y >= r and b.y <= R) {
        chmax(x, b.x - h * (b.y - r) / (R - r));
      }
    }
    seg.emplace_back(P{x, r}, P{x + h, R});
  }
  RE ans = 0;
  for (meion [a, b] : seg) chmax(ans, b.x);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"