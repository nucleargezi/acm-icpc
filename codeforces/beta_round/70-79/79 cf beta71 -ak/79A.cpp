#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
int N, M;
bool f() {
  int nd = 220;
  while (N and nd > 99) --N, nd -= 100;
  while (M and nd > 9) --M, nd -= 10;
  return not nd;
}
bool ff() {
  if (M > 21) return M -= 22, 1;
  if (M > 11 and N) return --N, M -= 12, 1;
  if (M > 1 and N > 1) return N -= 2, M -= 2, 1;
  return 0;
}
void Yorisou() {
  IN(N, M);
  while (1) {
    if (not f()) return print("Hanako");
    if (not ff()) return print("Ciel");
  }
}
#include "YRS/Z_H/main.hpp"