#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  vc<int> a(N), b(N);
  FOR(i, N) IN(a[i], b[i]);
  sort(a), sort(b);
  if (N & 1) print(b[N / 2] - a[N / 2] + 1);
  else print(b[N / 2] + b[N / 2 - 1] - a[N / 2] - a[N / 2 - 1] + 1);
}

int main() { Yorisou(); }