#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/st/range_max.hpp"
#include "YRS/dp/monge.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  range_max<int> st(a);
  Z f = [&](int l, int r) { return st.prod(l, r) * ll(N - l); };
  print(monge_dp_N<ll>(N, f));
}

int main() {
  Yorisou();
  return 0;
}