#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/line/01/gauss.hpp"

#define tests
using bs = bit_vec;
string s;
void Yorisou() {
  LL(n);
  int b = 1;
  while (n % (b << 1) == 0) b <<= 1;
  int m = n / b;
  meion f = [&]() {
    SV(s, '0');
    vector a(b, bs(m));
    for (int i = 0, t = 0; i < b; ++i) {
      for (int k = 0; k < m; ++k) {
        a[i][k] = s[t++];
      }
    }
    iroha gauss(b, m, a);
  };
  Yes(f() == f());
}
#include "MeIoN_Lib/Z_H/main.hpp"