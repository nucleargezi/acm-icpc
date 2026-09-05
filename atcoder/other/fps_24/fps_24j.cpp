#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/ofps/online_ctx.hpp"

using mint = M99;
using namespace online;

void Yorisou() {
  INT(n, m, l);
  vc<mint> g(n + 1);
  vc<int> ban(n + 1), suf(n + 2);
  mint in = mint(m).inv();

  FOR(m) {
    INT(x);
    g[x] = in, ++suf[x];
  }
  FOR(l) {
    INT(x);
    ban[x] = 1;
  }
  FOR_R(i, n + 1) suf[i] += suf[i + 1];
  Z f = ofps<mint>([&](Z a) {
    return unary(1 + a * val<mint>(g), 0,
        [&](mint x, int i) { return ban[i] ? mint() : x; });
  });
  mint ans = 0;
  FOR(i, n) ans += f[i] * suf[n - i] * in;
  print(ans);
}

int main() { Yorisou(); }