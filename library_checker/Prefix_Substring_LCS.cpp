#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/string/prefix_substring_lcs.hpp"

// #define tests
void Yorisou() {
  INT(Q);
  STR(S, T);
  prefix_substring_lcs seg(S, T);
  FOR(Q) {
    INT(n, l, r);
    print(seg.keis(n, l, r));
  }
}
#include "YRS/Z_H/main.hpp"