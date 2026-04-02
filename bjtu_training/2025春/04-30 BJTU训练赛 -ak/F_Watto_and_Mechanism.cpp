#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/hash.hpp"

void before() {}

// #define tests
using H = HASH<string>;
void Yorisou() {
  LL(n, q);
  vector<set<pair<PII, char>>> se(6'000'01);
  FOR(n) {
    S(s);
    ll n = len(s);
    H h(s);
    FOR(i, n) {
      se[i] += pair(h.merge_hash(0, i, i + 1, n), s[i]);
    }
  }
  FOR(q) {
    S(s);
    ll n = len(s);
    H h(s);
    FOR(i, n) {
      meion hs = h.merge_hash(0, i, i + 1, n);
      FOR(c, 'a', 'z' + 1) {
        if (c != s[i] and se[i].contains(pair<PII, char>(hs, c))) {
          goto MyGO;
        }
      }
    }
    if (0) MyGO: YES();
    else NO();
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"