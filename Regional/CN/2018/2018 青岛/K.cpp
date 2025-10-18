#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  int ans = 0;
  FOR(i, 30) {
    int c = 0;
    for (int x : a) c += topbit(x) == i;
    chmax(ans, c);
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"