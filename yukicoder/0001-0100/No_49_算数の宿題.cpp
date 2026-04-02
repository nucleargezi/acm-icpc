#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
vc<int> spl(const string &s) {
  vc<int> rs{-1};
  string bf;
  for (char c : s) {
    if (c == '*') {
      rs.ep(stoi(bf));
      bf.clear();
      rs.ep(-1);
    } else if (c == '+') {
      rs.ep(stoi(bf));
      bf.clear();
      rs.ep(-2);
    } else {
      bf += c;
    }
  }
  rs.ep(stoi(bf));
  return rs;
}
void Yorisou() {
  STR(s);
  Z f = spl(s);
  int N = len(f), ans = 0;
  FOR(i, 0, N, 2) {
    if (f[i] == -1) ans += f[i + 1];
    else ans *= f[i + 1];
  }
  print(ans);
}
#include "YRS/aa/main.hpp"