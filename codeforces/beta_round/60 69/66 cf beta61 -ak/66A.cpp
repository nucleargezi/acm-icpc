#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/bigint/big.hpp"

// #define tests
using G = bigint;
void Yorisou() {
  G L[]{G("-128"), G("-32768"), G("-2147483648"), G("-9223372036854775808")};
  G R[]{G("127"), G("32767"), G("2147483647"), G("9223372036854775807")};
  static constexpr string ans[] = {
      "byte", "short", "int", "long", "BigInteger"};
  G N;
  IN(N);
  FOR(i, 4) {
    if (N >= L[i] and N <= R[i]) return print(ans[i]);
  }
  print(ans[4]);
}
#include "YRS/Z_H/main.hpp"