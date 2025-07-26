#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  S(s);
  string a, b;
  for (char c : s) {
    if (c == 'T') a += c;
    else b += c;
  }
  UL(a + b);
}
#include "MeIoN_Lib/Z_H/main.hpp"