#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/string/wildcard_match_ntt.hpp"
#include "YRS/IO/fast_io.hpp"

// #define tests
void Yorisou() {
  INT(N, M);
  STR(s, t);
  Z ans = wildcard_match_ntt(s, t);
  for (int &x : ans) ++x;
  print(len(ans));
  print(ans);
}
#include "YRS/Z_H/main.hpp"