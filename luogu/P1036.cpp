#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/sps/all_k_subset.hpp"
#include "YRS/pr/ptest.hpp"

void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  int c = 0;
  all_k_subset<uint>((1 << N) - 1, K, [&](int s) {
    int x = 0;
    FOR(i, N) if (s >> i & 1) x += a[i];
    c += ptest(x);
  });
  print(c);
}

int main() { Yorisou(); }