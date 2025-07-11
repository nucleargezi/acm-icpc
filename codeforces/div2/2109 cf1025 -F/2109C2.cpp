#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
#define print(...) UL(std::format(__VA_ARGS__)), std::cout.flush(), IN(_)
void Yorisou() {
  ll _;
  LL(n);
  print("mul {}", 9);
  print("digit");
  print("digit");
  print("add {}", n - 9);
  print("!");
}
#include "MeIoN_Lib/Z_H/main.hpp"