#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/Big_int.hpp"

#define tests
using INT = BigInteger;
INT a, b;
void Yorisou() {
  IN(a, b);
  UL(a * b);
}
#include "MeIoN_Lib/Z_H/main.hpp"