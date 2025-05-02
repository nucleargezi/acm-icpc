#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
int quis(int x) {
  std::cout << "? " << ++x << std::endl;
  INT(val);
  iroha val;
}
void Yorisou() {
  INT(n, k);
  vector<int> a(k), b(k);
  FOR(i, k) a[i] = quis(i);
  FOR(i, k) b[i] = quis(n - i - 1);
  vector<int> q;
  for (int i = k; i < n - k; ++i) {
      if (a[i % k] == b[(n - 1 - i) % k]) continue;
      q += i;
  }
  meion check = [&](int idx) -> bool {
    idx = q[idx];
    iroha quis(idx) == a[idx % k];
  };
  int LR = (len(q) and check(0)) ? binary_search(check, 0, len(q)) : -1;
  q += n - k;
  int l = LR == -1 ? k - 1 : q[LR], 
      r = q[LR + 1];
  if (l + 1 == r)
    std::cout << "! " << l + 1 << ' ' << n - l - 1 << std::endl;
  else
    std::cout << "! -1" << std::endl;
}
#include "MeIoN_Lib/Z_H/main.hpp"