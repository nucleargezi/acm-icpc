#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  vc<char> a(N, 1);
  FOR(N - 1) {
    INT(x);
    --x;
    a[x] = 0;
  }
  FOR(i, N) if (a[i]) print(i + 1);
}

int main() {
  Yorisou();
  return 0;
}