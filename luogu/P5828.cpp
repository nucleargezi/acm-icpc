#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/po/cg/label_bcc_e.hpp"
#include "YRS/po/cg/label_bcc_e.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  FOR(5) {
    INT(x);
    print(count_label_bcc_e_N<mint>(x));
  }
}