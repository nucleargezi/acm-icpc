#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/pr/floor_root.hpp"

void Yorisou() {
  ULL(a, k);
  print(floor_root(a, k));
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"