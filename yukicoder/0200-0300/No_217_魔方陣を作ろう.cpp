#include "YRS/all.hpp"
#include "YRS/jen/magic_square.hpp"

void Yorisou() {
  INT(N);
  print(magic_square{}.run(N));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"