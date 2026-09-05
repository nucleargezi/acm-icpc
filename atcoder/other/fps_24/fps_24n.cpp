#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/ofps/online_ctx.hpp"

using mint = M99;
using namespace online;

void Yorisou() {
  INT(N);
  vc<T> g(N + 1);
  FOR(i, 1, N + 1) {
    INT(a);
    FOR(k, i, N + 1, i) g[k - 1] += i;
    ll j = ll(i) * (a + 1);
    if (j <= N) FOR(k, j, N + 1, j) g[k - 1] -= j;
  }
  Z f = ofps<T>([&](Z a) { return 1 + integ(a * val<mint>(g)); });
  print(f[N]);
}

int main() { Yorisou(); }