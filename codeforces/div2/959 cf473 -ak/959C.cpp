#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  if (N < 6) {
    print(-1);
  } else {
    vc<PII> es;
    es.ep(0, 1);
    FOR(i, 2, N) es.ep(i & 1, i);
    for (var [a, b] : es) print(a + 1, b + 1);
  }
  FOR(i, 1, N) print(i, i + 1);
}

int main() {
  Yorisou();
  return 0;
}