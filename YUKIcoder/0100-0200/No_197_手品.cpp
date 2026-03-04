#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

void Yorisou() {
  STR(s);
  INT(N);
  STR(t);
  bool o = 1;
  if ((N & 1) == 0) {
    if (s == t) o = 0;
  } else {
    swap(s[0], s[1]);
    if (s == t) o = 0;
    swap(s[0], s[1]);
    swap(s[2], s[1]);
    if (s == t) o = 0;
    swap(s[2], s[1]);
  }
  if (N >= 2) {
    FOR(i, 3) FOR(k, i + 1, 3) {
      swap(s[i], s[k]);
      if (s == t) o = 0;
      swap(s[i], s[k]);
    }
  }
  print(o ? "SUCCESS" : "FAILURE");
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"