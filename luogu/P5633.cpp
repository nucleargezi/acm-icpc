#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/dsu.hpp"

struct E {
  int f, t, w;
  operator int() const { return w; }
};
void Yorisou() {
  INT(N, M, s, K);
  --s;
  vc<E> ea, es;
  FOR(M) {
    INT(a, b, c);
    --a, --b;
    if (a == s or b == s) es.ep(E{a, b, c});
    else ea.ep(E{a, b, c});
  }
  sort(ea);
  sort(es);
  int A = si(ea), B = si(es);
  
  dsu g(N);
  Z f = [&](ll x) -> tuple<bool, ll, int> {
    int i = 0, k = 0, c = 0;
    ll s = 0;
    g.reset();
    while (i < A and k < B) {
      if (ea[i].w < es[k].w + x) {
        if (g.merge(ea[i].f, ea[i].t)) s += ea[i].w;
        ++i;
      } else {
        if (g.merge(es[k].f, es[k].t)) s += es[k].w + x, ++c;
        ++k;
      }
    }
    for (; i < A; ++i) if (g.merge(ea[i].f, ea[i].t)) s += ea[i].w;
    for (; k < B; ++k) if (g.merge(es[k].f, es[k].t)) s += es[k].w + x, ++c;
    return {g.c == 1, s, c};
  };

  const ll lm = inf<ll> / (2 * N);

  Z [o, _a, L] = f(lm);
  Z [k, _b, R] = f(-lm);
  if (not o or not k or K < L or K > R) return print("Impossible");

  ll x = bina<0>([&](ll x) { return get<int>(f(x)) >= K; }, -lm, lm);

  Z [ok, w, c] = f(x);
  print(w - x * K);
}

int main() {
  Yorisou();
  return 0;
}