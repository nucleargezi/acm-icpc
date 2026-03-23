#include "YRS/all.hpp"

bool ck(string s) {
  string rs = s;
  reverse(rs);
  return s == rs;
}

void Yorisou() {
  int ans = 0;
  FOR(i, 100, 1000) FOR(k, 100, 1000) {
    string s = to_string(i * k);
    if (ck(s)) chmax(ans, i * k);
  }
  print(ans);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"