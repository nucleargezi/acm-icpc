#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
string f(string s) {
  for (char &c : s) c = std::tolower(c);
  return s;
}
void Yorisou() {
  INT(N);
  VEC(string, s, N);
  STR(t);
  int sz = len(t);
  CH(c);
  vc<int> a(sz + 1);
  FOR(i, N) FOR(k, sz - len(s[i]) + 1) {
    if (f(s[i]) == f(t.substr(k, len(s[i])))) {
      ++a[k], --a[k + len(s[i])];
    }
  }
  FOR(i, sz) a[i + 1] += a[i];
  string r = t;
  FOR(i, sz) {
    if (a[i]) {
      char cc = std::tolower(c), d = std::tolower(t[i]), go;
      if (d != cc) go = cc;
      else if (d != 'a') go = 'a';
      else go = 'b';
      if (std::isupper(t[i])) go = std::toupper(go);
      r[i] = go;
    }
  }
  print(r);
}
#include "YRS/Z_H/main.hpp"