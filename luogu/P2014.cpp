#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/dp/knapsack_tree.hpp"

void Yorisou() {
  INT(N, W);
  vc<int> f(N), w(N, 1), v(N);
  FOR(i, N) {
    INT(fa, x);
    --fa;
    f[i] = fa, v[i] = x;
  }
  print(knapsack_tree(f, w, v)(W));
}

int main() {
  Yorisou();
  return 0;
}