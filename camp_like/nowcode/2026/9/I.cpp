#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

i128 ABS(i128 x) { return x < 0 ? -x : x; }

i128 BI(Z f, i128 l, i128 r) {
  while (ABS(l - r) > 1) {
    i128 x = (r + l) >> 1;
    (f(x) ? l : r) = x;
  }
  return l;
}

void Yorisou() {
  LL(N, a, b);
  if (a == 1) return print(ceil(N, b));
  Z ke = [&](i128 ls) -> i128 {
    return BI([&](i128 rs) -> bool {
      i128 dot = ls * a, sm = N - rs * b;
      if (ls) {
        sm -= (a + (ls - 1) * (a - 1) + a) * ls / 2;
      }
      dot -= ls;
      if (dot >= rs) {
        sm -= (dot + dot - rs + 1) * rs / 2;
      } else {
        sm -= (dot + 1) * dot / 2;
      }
      return sm <= 0;
    }, N, -1) + ls;
  };
  int rs = ceil(N, b);
  chmin(rs, ke((int)sqrtl(N)));
  FOR(i, rs) {
    chmin(rs, ke(i));
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}