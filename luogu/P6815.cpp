#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/enumerate_c3.hpp"

void Yorisou() {
  INT(N, M);
  VEC(int, a, N);
  graph g(N);
  g.sc(M);
  ll s = 0;
  enum_c3(g, [&](int i, int k, int j) -> void {
    s += max({a[i], a[k], a[j]});
  });
  print(s);
}

int main() {
  Yorisou();
  return 0;
}