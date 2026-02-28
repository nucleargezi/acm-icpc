#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"

void Yorisou() {
  STR(s);
  sort(s);
  set<string> se;
  do {
    se.eb(s);
  } while (next_permutation(all(s)));
  print(len(se) - 1);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"