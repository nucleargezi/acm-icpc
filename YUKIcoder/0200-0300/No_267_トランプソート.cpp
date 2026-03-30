#include "YRS/all.hpp"

void Yorisou() {
  INT(N);
  vc<int> a[4];
  string ls = "DCHS";
  string rs = "A23456789TJQK";
  FOR(N) {
    STR(s);
    FOR(i, 4) FOR(k, 14) if (s[0] == ls[i] and s[1] == rs[k]) a[i].ep(k);
  }
  vc<string> s;
  FOR(i, 4) for (sort(a[i]); int x : a[i]) s.ep(string() + ls[i] + rs[x]);
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"