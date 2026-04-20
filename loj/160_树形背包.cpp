#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/dp/knapsack_tree.hpp"

void Yorisou() {
  INT(N, W);
  VEC(int, f, N);
  VEC(int, w, N);
  VEC(int, v, N);
  for (int &x : f) --x;
  print(knapsack_tree(f, w, v)(W));
}

int main() {
  Yorisou();
  return 0;
}