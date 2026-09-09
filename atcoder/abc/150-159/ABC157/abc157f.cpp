#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/circle.hpp"

using re = ld;
using P = point<re>;
using C = circle<re>;
constexpr re eps = 1e-12l;

void Yorisou() {
  INT(N, K);
  vc<P> a(N);
  vc<ll> w(N);
  FOR(i, N) IN(a[i], w[i]);
  vc<C> c(N);

  Z ck = [&](P p) -> bool {
    int s = 0;
    FOR(i, N) if ((s += c[i].contains(p, eps)) >= K) return 1;
    return 0;
  };

  print(bina_real<re>([&](re t) -> bool {
    FOR(i, N) c[i] = {a[i], t / w[i]};
    FOR(i, N) if (ck(a[i])) return 1;
    FOR(i, N) FOR(k, i + 1, N) {
      Z [ok, p, q] = c[i].cross_point(c[k]);
      if (not ok) continue;
      if (ck(p) or ck(q)) return 1;
    }
    return 0;
  }, 1'000'000'000, 0));
}

int main() { Yorisou(); }