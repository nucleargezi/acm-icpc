#include "YRS/all.hpp"
#include "YRS/nt/pell.hpp"

void Yorisou() {
  LL(D);
  print(pell<i128>{}(D, 1, inf<i128>));
  print(pell<i128>{}(D, 0, inf<i128>));
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"