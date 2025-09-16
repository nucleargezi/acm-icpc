#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

#define tests
void Yorisou() {
  INT(N, K);
  ++K;
  VEC(int, a, N);
  min_heap<ll> q;
  int sz = 0;
  FOR_R(i, N) {
    if ((N - i) % K == 0) ++sz;
    q.emplace(a[i]);
    if (len(q) > sz) pop(q);
  }
  ll ans = 0;
  while (not q.empty()) ans += pop(q);
  print(ans);
}
#include "YRS/Z_H/main.hpp"