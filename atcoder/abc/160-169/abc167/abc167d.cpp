#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/func.hpp"

void Yorisou() {
  LL(N, K);
  VEC(int, to, N);
  for (int &x : to) --x;
  func_g v(to);
  print(v.jump(0, K) + 1);
}

int main() { Yorisou(); }