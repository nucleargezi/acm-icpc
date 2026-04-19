#include "YRS/all.hpp"
#include "YRS/ds/bit/bitbit.hpp"
#include "YRS/al/m/add.hpp"

using DS = bitbit<monoid_add<ll>>;
void Yorisou() {
  INT(N, M);
  DS seg(N + 1, M + 1);
  int op;
  while (cin >> op) {
    if (op == 1) {
      INT(a, b, c, d, w);
      --a, --b;
      seg.multiply(a, b, w);
      seg.multiply(c, d, w);
      seg.multiply(a, d, -w);
      seg.multiply(c, b, -w);
    } else {
      INT(x, y);
      print(seg.prod(x, y));
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  Yorisou();
  return 0;
}