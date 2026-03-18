#include "YRS/all.hpp"
#include "YRS/ge/basic/line.hpp"
#include "YRS/ge/basic/segment.hpp"

using P = point<int>;
void Yorisou() {
  INT(N);
  vc<segment<int>> a;
  vc<P> e;
  FOR(i, N) {
    P f, t;
    IN(f, t);
    a.ep(f, t);
    e.ep(f);
    e.ep(t);
  }
  int s = 0;
  Z f = [&](line<int> l) -> int {
    int s = 0;
    FOR(i, N) s += a[i].cross_point(l).fi;
    return s;
  };
  for (P x : e) for (P y : e) if (x != y) chmax(s, f(line(x, y)));
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"