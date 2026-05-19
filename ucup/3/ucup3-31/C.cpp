#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(string, a, N);
  VEC(string, b,N);
  sort(a);
  sort(b);
  FOR(i, N) if (a[i].substr(0, 4) != b[i].substr(0, 4)) return print("NO");
  print("YES");
  FOR(i, N) print(a[i], b[i]);
}

int main() {
  Yorisou();
  return 0;
}