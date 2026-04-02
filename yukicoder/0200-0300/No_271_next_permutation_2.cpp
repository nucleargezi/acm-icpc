#include "YRS/all.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/nt/counting/count_inv_of_permutation.hpp"

using mint = M11;
void Yorisou() {
  LL(N, K);
  VEC(int, p ,N);
  print(count_inv_of_permutation<mint>(p, K));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"