#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  pair<int, string> max{-inf<int>, {}};
  INT(N);
  FOR(N) {
    STR(s);
    int x = 0;
    INT(sc, fl);
    x += sc * 100 - fl * 50;
    FOR(5) {
      INT(ad);
      x += ad;
    }
    chmax(max, pair{x, s});
  }
  print(max.se);
}
#include "YRS/Z_H/main.hpp"