#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(W, N);
  int s = W;
  VEC(int, a, N);
  FOR(i, 1, N) chmin(s, W - a[i] + a[i - 1]);
  chmin(s, a[N - 1] - a[0]);
  print(s);
}

int main() { Yorisou(); }