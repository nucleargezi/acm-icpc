#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(L, N, M);
  VEC(int, a, N);
  a.ep(L - a.back());
  FOR_R(i, N - 1) a[i + 1] -= a[i];
  print(bina([&](int x) -> bool {
    ll s = 0;
    for (int d : a) if (d) {
      s += ceil(d, x) - 1;
    }
    return s <= M;
  }, inf<int>, 0));
}

int main() {
  Yorisou();
  return 0;
}