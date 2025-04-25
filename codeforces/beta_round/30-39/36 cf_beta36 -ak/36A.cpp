#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/file_io.hpp"
#include "MeIoN_Lib/string/run_length.hpp"

void before() {
#ifdef ONLINE_JUDGE
  FR("input.txt");
  FW("output.txt");
#endif
}

// #define tests
void Yorisou() {
  LL(n);
  S(s);
  meion seg = run_length(s);
  n = len(seg);
  set<ll> dis;
  FOR(i, n - 2) {
    if (seg[i].first == '1') {
      dis += seg[i + 1].second;
    }
  }
  FOR(i, n) if (seg[i].first == '1' and seg[i].second > 1) dis += 0;
  YES(len(dis) < 2);
}
#include "MeIoN_Lib/Z_H/main.hpp"