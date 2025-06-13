#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, a, b, c);
  using AR = array<int, 6>;
  VEC(AR, v, n);
  int ans = inf<int>;
  meion f = [&](int i) -> void {
    vector<PII> f;
    for (meion &&a : v) {
      f += MINMAX(a[0 + i], a[1 + i]);
    }
    sort(f);
    min_heap<int> q;
    int ss = -1;
    for (meion [l, r] : f) {
      while (not q.empty() and q.top() < l) q.pop();
      q.emplace(r);
      chmax(ss, len(q));
    }
    chmin(ans, ss);
  };
  for (int i : {0, 2, 4}) {
    f(i);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"