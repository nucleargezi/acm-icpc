#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N);
  if (N == 1) return print(1);
  if (N == 2) return print(-1);
  vector<int> ans{12, 20, 45};
  while (len(ans) < N) ans.ep(ans.back() + 45);
  for (int x : ans) print(x);
}
#include "YRS/Z_H/main.hpp"