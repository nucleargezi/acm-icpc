#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  if (N == 1) return print(a[0]);
  vector<int> x, y;
  for (int e : a) (e & 1 ? x : y).emplace_back(e);
  if (y.empty() or x.empty()) return print(QMAX(a));
  print(SUM(a) - len(x) + 1);
}
#include "YRS/Z_H/main.hpp"