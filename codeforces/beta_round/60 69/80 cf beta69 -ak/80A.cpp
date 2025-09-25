#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/PR/prims_test.hpp"

// #define tests
void Yorisou() {
  INT(N, M);
  if (primetest(N) and primetest(M)) {
    FOR(i, N + 1, M) if (primetest(i)) return NO();
    YES();
  } else {
    NO();
  }
}
#include "YRS/Z_H/main.hpp"