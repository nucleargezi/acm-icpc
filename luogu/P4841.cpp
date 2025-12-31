#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/modint.hpp"
#include "YRS/po/cg/label_undir_con.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = modint<1004535809>;
void Yorisou() {
  INT(N);
  print(count_label_undir_con<mint>(N)[N]);
}
#include "YRS/aa/main.hpp"