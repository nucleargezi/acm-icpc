#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, x, y);
  --x, --y;
  set<PII> se{{N / 2, N / 2}, {N / 2 - 1, N / 2}, {N / 2, N / 2 - 1}, {N / 2 - 1, N / 2 - 1}};
  YES(not se.contains({x, y}));
}

int main() {
  Yorisou();
  return 0;
}