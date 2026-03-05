#define YRSD
#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ge/basic/point.hpp"

using P = point<ll>;
void Yorisou() {
  INT(N);
  vc<P> sv;
  FOR(N) {
    P x;
    IN(x);
    bool ok = 1;
    for (P e : sv) {
      if ((x - e).square() < 400) {
        ok = 0;
        break;
      }
    }
    if (ok) sv.ep(x);
  }
  print(len(sv));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"