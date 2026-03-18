#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"

#define print(...) print(__VA_ARGS__), cout.flush(), void()
int c = 0;
int Q(int x) {
  print("?", x);
  ++c;
  IN(x);
  return x;
}
void Yorisou() {
  FOR(i, 10, 41) {
    int x = Q(i);
    if (x == 0) return print("!", i + c - 1);
    else if (x == -1) return print("!", i + c - 2);
  }
  print("!", bina([&](int x) { return Q(x - c) >= 0; }, 41, 1'000'000'001));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"