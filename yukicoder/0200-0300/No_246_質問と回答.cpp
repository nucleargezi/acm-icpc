#include "YRS/all.hpp"

#define print(...) print(__VA_ARGS__), cout.flush()
void Yorisou() {
  print("!", bina([&](int x) {
    print("?", x);
    IN(x);
    return !!x;
  }, 0, 1'000'000'001));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"