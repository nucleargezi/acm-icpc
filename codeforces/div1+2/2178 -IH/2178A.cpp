#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  STR(s);
  YES(std::count(all(s), 'Y') <= 1);
}
#include "YRS/aa/main.hpp"