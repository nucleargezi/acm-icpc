#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/f/factorials.hpp"
#include "YRS/mod/modint_d.hpp"

#define tests 1
#define fl 0
#define DB 10
using mint = dmint;
void Yorisou() {
  INT(N, P);
  mint::set_mod(P);
  for (mint x : factorials<mint>({N})) print(x);
  
}
#include "YRS/aa/main.hpp"