#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(a, b, c, d, N);
  vc<int> s(N + 1);
  for (int x : {a, b, c, d}) {
    FOR(i, x, N + 1, x) s[i] = 1;
  }
  print(SUM<int>(s));
}

int main() {
  Yorisou();
  return 0;
}