#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  vc<int> a(N);
  if (N & 1) {
    a[N / 2] = 1;
    FOR(i, N / 2, N) if (a[i] and i + 3 < N) a[i + 3] = 1;
    FOR_R(i, N / 2 + 1) if (a[i] and i - 3 > -1) a[i - 3] = 1;
  } else {
    a[N / 2] = a[N / 2 - 1] = 1;
    FOR(i, N / 2, N) if (a[i] and i + 3 < N) a[i + 3] = 1;
    FOR_R(i, N / 2) if (a[i] and i - 3 > -1) a[i - 3] = 1;
  }
  print(SUM<int>(a), N);
}

int main() {
  Yorisou();
  return 0;
}