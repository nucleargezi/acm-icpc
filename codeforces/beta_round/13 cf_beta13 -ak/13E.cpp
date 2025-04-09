#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/LCT.hpp"

void before() {}

// #define tests
using node = LCT_Node_Base;
using LCT = Link_Cut_Tree<node>;
void Yorisou() {
  INT(n, q);
  LCT lct(n + 1);
  VEC(int, a, n);
  FOR(i, n) {
    lct.link(i, MIN<ll>(i + a[i], n));
  }
  FOR(q) {
    INT(op);
    if (op == 0) {
      INT(x, k);
      --x;
      lct.cut(x, MIN<ll>(x + a[x], n));
      a[x] = k;
      lct.link(x, MIN<ll>(x + a[x], n));
    } else {
      INT(x);
      --x;
      lct.evert(x);
      lct.expose(n);
      UL(lct.jump(lct[n], lct[x], 1)->idx + 1, lct[n]->size - 1);
    }
  }
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}