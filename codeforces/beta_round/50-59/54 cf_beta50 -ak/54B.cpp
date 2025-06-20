#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/hash.hpp"

// #define tests
using H = HASH<string>;
using AR = array<PII, 4>;
void Yorisou() {
  LL(n, m);
  VEC(string, s, n);
  int c = 0;
  pair<int, PII> min = inf<pair<int, PII>>;
  FOR(x, 1, n + 1) FOR(y, 1, m + 1) if (n % x == 0 and m % y == 0) {
    set<AR> se;
    FOR(i, 0, n, x) FOR(k, 0, m, y) {
      AR val{};
      string al;
      FOR(o, i, i + x) FOR(p, k, k + y) {
        al += s[o][p];
      }
      val[0] = H(al).get();
      al.clear();
      FOR_R(o, i, i + x) FOR_R(p, k, k + y) {
        al += s[o][p];
      }
      val[2] = H(al).get();
      if (m % x == 0 and n % y == 0) {
        al.clear();
        FOR_R(p, k, k + y) FOR(o, i, i + x) { al += s[o][p]; }
        val[1] = H(al).get();
        al.clear();
        FOR(p, k, k + y) FOR_R(o, i, i + x) { al += s[o][p]; }
        val[3] = H(al).get();
      }
      AR t = val;
      FOR(4) {
        std::rotate(t.begin(), t.begin() + 1, t.end());
        chmin(val, t);
      }
      se.emplace(val);
    }
    if (len(se) == n / x * m / y) {
      ++c;
      chmin(min, pair(int(x * y), PII(x, y)));
    }
  }
  UL(c);
  UL(min.second);
}
#include "MeIoN_Lib/Z_H/main.hpp"