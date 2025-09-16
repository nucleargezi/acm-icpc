#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  INT(N);
  vector<tuple<int, int, string>> s;
  map<string, int> mp;
  mp["rat"] = 0;
  mp["woman"] = 1;
  mp["child"] = 1;
  mp["man"] = 2;
  mp["captain"] = 3;
  FOR(i, N) {
    STR(a, b);
    s.emplace_back(mp[b], i, a);
  }
  sort(s);
  for (Z [a, b, s] : s) UL(s);
}
#include "YRS/Z_H/main.hpp"