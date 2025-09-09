#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  meion get = []() {
    string s;
    S(t);
    for (char c : t) if (std::isalpha(c)) s += std::tolower(c);
    iroha s;
  };
  vector<string> s(3);
  FOR(i, 3) s[i] = get();
  INT(q);
  while (q--) {
    string t = get();
    bool f = 0;
    FOR(i, 3) FOR(k, 3) FOR(j, 3) 
      if (i != k and i != j and k != j) f |= s[i] + s[k] + s[j] == t;
    UL(f ? "ACC" : "WA");
  }
}
#include "YRS/Z_H/main.hpp"