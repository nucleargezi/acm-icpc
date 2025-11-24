#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
constexpr string err = "errtype", vo = "void";
map<string, string> mp;
string ad(const string &s, int a, int b) {
  string g = string(a, '&') + s + string(b, '*');
  int l = 0, r = len(g) - 1;
  while (l <= r and g[l] == '&' and g[r] == '*') ++l, --r;
  g = g.substr(l, r - l + 1);
  return g[0] == '&' or g[0] == 'e' ? err : g;
}
string f(string &s) {
  int a = 0, b = 0, n = len(s);
  FOR(i, n) if (s[i] == '&') ++a; else break;
  FOR_R(i, n) if (s[i] == '*') ++b; else break;
  if (not mp.contains(s = s.substr(a, n - a - b))) return err;
  return ad(mp[s], a, b);
}
void Yorisou() {
  mp[err] = err;
  mp[vo] = vo;
  INT(N);
  FOR(N) {
    STR(op);
    if (op == "typedef") {
      STR(x, y);
      mp[y] = f(x);
    } else {
      STR(x);
      print(f(x));
    }
  }
}
#include "YRS/Z_H/main.hpp"