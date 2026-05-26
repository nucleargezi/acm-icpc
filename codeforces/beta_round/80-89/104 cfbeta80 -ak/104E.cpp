#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

constexpr int B = 1 << 8;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<vc<PII>> q(B);
  vc<T3<int>> big;
  INT(Q);
  FOR(t, Q) {
    INT(i, d);
    --i;
    if (d <= B) q[d - 1].ep(t, i);
    else big.ep(t, i, d);
  }

  vc<vc<int>> v(N);
  vc<ll> f(N), rs(Q);
  FOR(d, B) if (si(q[d])) {
    for (var [id, i] : q[d]) v[i].ep(id);
    fill(all(f), 0);
    FOR_R(i, N) {
      f[i] = ((i + d + 1 >= N) ? 0 : f[i + d + 1]) + a[i];
      while (si(v[i])) rs[pop(v[i])] = f[i];
    }
  }

  for (Z [id, i, d] : big) {
    ll s = 0;
    for (; i < N; i += d) s += a[i];
    rs[id] = s;
  }
  for (ll x : rs) print(x);
}

int main() {
  Yorisou();
  return 0;
}