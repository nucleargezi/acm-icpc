#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/lct/lct_base.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  FOR(i, N) --a[i];
  LCT_base lct(N + 2);
  FOR(i, N - 1) lct.link(a[i], a[i + 1]);
  int top = N, bot = N + 1;
  lct.link(top, a[0]), lct.link(a[N - 1], bot);
  Z cut = [&](int i)  {
    int x = lct.jump(i, top, 1), y = lct.jump(i, bot, 1);
    lct.cut(x, i), lct.cut(i, y);
    lct.link(x, y);
  };
  Z link = [&](int a, int b, int c) {
    lct.cut(a, c);
    lct.link(a, b), lct.link(b, c);
  };
  FOR(Q) {
    STR(op);
    if (op[0] == 'T') {
      INT(s);
      --s;
      cut(s);
      int p = lct.jump(top, bot, 1);
      link(top, s, p);
    } else if (op[0] == 'B') {
      INT(s);
      --s;
      cut(s);
      int p = lct.jump(bot, top, 1);
      link(p, s, bot);
    } else if (op[0] == 'I') {
      INT(s, x);
      --s;
      if (x > 0) {
        int u = lct.jump(s, bot, x), d = lct.jump(u, bot, 1);
        cut(s);
        link(u, s, d);
      }
      if (x < 0) {
        int d = lct.jump(s, top, -x), u = lct.jump(d, top, 1);
        cut(s);
        link(u, s, d);
      }
    } else if (op[0] == 'A') {
      INT(s);
      --s;
      print(lct.dist(top, s) - 1);
    } else if (op[0] == 'Q') {
      INT(s);
      print(lct.jump(top, bot, s) + 1);
    }
  }
}
#include "YRS/Z_H/main.hpp"