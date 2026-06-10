#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(N, M, K);
  VEC(ll, a, N);
  unique(a);
  N = si(a);
  if (K + 1 == N and M >= N) return print(0);
  
  print(bina([&](ll d) -> bool {
    for (ll pr = -d - 1, c = 0; K - pr > d; ) {
      int i = ub(a, pr + d + d + 1) - 1;
      if (i < 0 or a[i] <= pr) return 0;
      pr = a[i];
      if (++c > M) return 0;
    }
    return 1;
  }, K, -1));
}

int main() {
  Yorisou();
  return 0;
}