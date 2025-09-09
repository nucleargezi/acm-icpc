#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  INT(n);
  VEC(string, s, n);
  ll L = 0;
  for (meion &s : s) L += len(s);
  L /= n / 2;
  CH(c);
  map<int, set<string>> m;
  for (meion &s : s) {
    m[len(s)].emplace(s);
  }
  for (meion &s : s) s += c;
  sort(s);
  for (meion &s : s) pop(s);
  set<string> ex;
  for (meion &s : s) {
    if (not ex.emplace(s).second) continue;
    int i = L - len(s);
    meion &se = m[i];
    string t;
    while (true) {
      t = *se.begin();
      se.extract(se.begin());
      if (ex.emplace(t).second) break;
    }
    UL(s + c + t);
  }
}
#include "YRS/Z_H/main.hpp"