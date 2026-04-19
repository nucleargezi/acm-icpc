#include "YRS/all.hpp"
#include "YRS/ds/bit/bitbit.hpp"
#include "YRS/al/m/add.hpp"

using DS = bitbit<monoid_add<ll>>;
void Yorisou() {
  INT(N, M);
  DS seg(N, M);
  int op;
  while (cin >> op) {
    if (op == 1) {
      INT(x, y, c);
      --x, --y;
      seg.multiply(x, y, c);
    } else {
      INT(a, c, b, d);
      --a, --c;
      print(seg.prod(a, b, c, d));
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  Yorisou();
  return 0;
}