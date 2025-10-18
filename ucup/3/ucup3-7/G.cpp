#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N);
  vector<int> v(N, inf<int>);
  FOR(i, N) FOR(k, N) {
    INT(x);
    chmin(v[i], x);
  }
  print(QMAX(v));
}
#include "YRS/Z_H/main.hpp"