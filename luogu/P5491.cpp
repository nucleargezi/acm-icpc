#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mod_sqrt.hpp"

void Yorisou() {
  INT(Q);
  FOR(Q) {
    INT(N, p);
    int x = mod_sqrt(N, p);
    if (x == -1) print("Hola!");
    else {
      int y = p - x;
      if (y >= p) y -= p;
      if (x > y) swap(x, y);
      if (x == y) print(x);
      else print(x, y);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}