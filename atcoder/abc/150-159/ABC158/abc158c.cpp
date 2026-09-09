#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  INT(a, b);
  int x = bina([&](int x) {
    return x * 8 / 100 >= a and x / 10 >= b;
  }, 1'000'000'0, 0);
  if (x * 8 / 100 != a or x / 10 != b) print(-1);
  else print(x);
}

int main() { Yorisou(); }