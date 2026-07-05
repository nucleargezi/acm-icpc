#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/st/range_max.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  range_max<int> st(a);
  FOR(Q) {
    INT(l, r);
    --l;
    print(st.prod(l, r));
  }
}

int main() {
  Yorisou();
  return 0;
}