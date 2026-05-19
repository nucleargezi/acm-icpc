#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void yorisou() {
  INT(N);
  VEC(int, a, N);
  int s = 0;
  for (int l = 0, r; l < N; l = r) {
    r = l + 1;
    ll d;
    while (r < N) {
      if (r - 1 == l) {
        d = a[r] - a[l];
        ++r;
      } else if (r - 2 == l) {
        d = a[r] - a[r - 1] - d;
        ++r;
      } else {
        ll g = a[r] - a[r - 1] - (a[r - 1] - a[r - 2]);
        if (g != d) break;
        ++r;
      }
    }
    ++s;
  }
  print(s);
}

int main() {
  INT(T);
  FOR(T) yorisou();
  return 0;
}