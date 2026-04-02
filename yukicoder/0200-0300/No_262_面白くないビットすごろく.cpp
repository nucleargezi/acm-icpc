#include "YRS/all.hpp"
#include "YRS/nt/step_of_add_pc.hpp"

void Yorisou() {
  LL(N);
  N = step_of_add_pc{}.run(N);
  print(N == -1 ? N : N + 1);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"