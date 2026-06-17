#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(d, t);
  FOR(i, 24) {
    if ((t >= 6 and t <= 17) and not((t + d) % 24 >= 6 and (t + d) % 24 <= 17))
      return print(i);
    t = (t + 1) % 24;
  }
  print(-1);
}

int main() {
  Yorisou();
  return 0;
}