#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  INT(N, M);
  int c = N - M;
  print(M, ceil(M, c + 1));
}
#include "YRS/Z_H/main.hpp"