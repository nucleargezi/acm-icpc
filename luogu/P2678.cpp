#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(L, N, M);
  VEC(int, a, N);
  print(bina([&](int x) -> bool {
    int c = 0, pr = 0;
    for (int p : a) {
      if (p - pr < x) ++c;
      else pr = p;
    }
    if (L - pr < x) ++c;
    return c <= M;
  }, 0, L + 1));
}

int main() {
  Yorisou();
  return 0;
}