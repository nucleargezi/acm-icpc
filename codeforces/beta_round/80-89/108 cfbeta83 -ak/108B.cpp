#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  unique(a);
  N = si(a);
  FOR_R(i, N - 1) {
    int t = lb(a, (a[i] << 1));
    --t;
    if (t != i) return YES();
  }
  NO();
}

int main() {
  Yorisou();
  return 0;
}