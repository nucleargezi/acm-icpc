#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N);
  FOR(N) {
    STR(s);
    const int N = len(s);
    if (N > 10) {
      s = s[0] + to_s(N - 2) + s.back();
    }
    print(s);
  }
}
#include "YRS/Z_H/main.hpp"