#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  FOR(Q) {
    INT(n, x, m);
    ll ls = x, z = 0;
    FOR(i, N) {
      ll w = ceil(n - i - 1, N);
      ls += a[i] % m * w;
      if (a[i] % m == 0) z += w;
    }
    print(n - 1 - ls / m + x / m - z);
  }
}

int main() { Yorisou(); }