#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  if (N > M) swap(N, M);
  if (N == 1) return print(M);
  if (N == 2) {
    if (M & 3) {
      if (M & 1) ++M;
      else M = M / 4 * 4 + 4;
    } 
    return print(M);
  }
  print(ceil(N * M, 2));
}

int main() {
  Yorisou();
  return 0;
}