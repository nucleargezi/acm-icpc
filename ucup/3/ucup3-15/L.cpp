#include "YRS/all.hpp"
#include "YRS/ds/fenw/fenw.hpp"
#include "YRS/ds/monoid/add.hpp"

#define tests
void Yorisou() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int &x : a) cin >> x;
  fenw<monoid_add<int>> seg(N + 1);
  int x = N;
  FOR_R(i, N) x -= x == a[i];
  ++x;
  vector<PII> g;
  FOR(i, N) if (a[i] < x) g.emplace_back(a[i], i);
  sort(g, greater());
  vector<PII> ans;
  for (Z [val, i] : g) {
    ans.emplace_back(i + 1 + seg.prod(i + 1),  1);
    seg.multiply(i, -1);
    seg.multiply(0, 1);
  }
  print(len(ans), len(ans));
  for (Z x : ans) print(x);
}
#include "YRS/Z_H/main.hpp"