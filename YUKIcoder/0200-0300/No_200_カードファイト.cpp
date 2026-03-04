#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/flow/max_flow.hpp"

void Yorisou() {
  INT(T);
  INT(N);
  VEC(int, a, N);
  INT(M);
  VEC(int, b, M);
  sort(a);
  sort(b);
  multiset<int> l(all(a)), r(all(b));
  int s = 0;
  FOR(T) {
    bool o = 0;
    for (Z it = rbegin(r); it != rend(r); ++it) {
      int x = *it;
      Z ii = l.upper_bound(x);
      if (ii != end(l)) {
        ++s;
        o = 1;
        r.extract(x);
        l.extract(ii);
        break;
      }
    }
    if (not o) {
      r.extract(prev(end(r)));
      l.extract(begin(l));
    }
    if (l.empty()) l = {all(a)};
    if (r.empty()) r = {all(b)};
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"