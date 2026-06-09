#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  VEC(int, a, N);
  VEC(int, b, M);
  multiset<int> se(all(b));
  sort(a);
  int s = 0;
  for (int x : a) {
    Z it = se.upper_bound(x << 1);
    if (it == bg(se)) continue;
    se.extract(prev(it));
    ++s;
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}