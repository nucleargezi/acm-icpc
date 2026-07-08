#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(a, x, y);
  if (y % a == 0) return print(-1);
  y /= a;
  if (y < 2) {
    x <<= 1;
    if (x > -a and x < a) print(y + 1);
    else print(-1);
  } else {
    y -= 2;
    if (y & 1) {
      x <<= 1;
      if (x > -a and x < a) print(2 + y / 2 * 3 + 3);
      else print(-1);
    } else {
      if (x > -a and x < a and x) print(2 + y / 2 * 3 + (x < 0 ? 1 : 2));
      else print(-1);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}