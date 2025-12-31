#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/string/SA/string_cmp.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  STR(s);
  INT(Q);
  string_cmp sa(s);
  FOR(Q) {
    INT(l, r);
    --l;
    print(sa.max_border(l, r));
  }
}
#include "YRS/aa/main.hpp"