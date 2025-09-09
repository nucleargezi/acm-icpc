#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/IO/fmt.hpp"

// #define tests
void Yorisou() {
  int h, c;
  while (IN(h, c)) {
    print("{}", std::max(h, c + 1));
  }
}
#include "YRS/Z_H/main.hpp"