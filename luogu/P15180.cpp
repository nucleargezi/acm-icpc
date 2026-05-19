#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_t.hpp"
#include "YRS/ds/wave/wave_mat.hpp"
#include "YRS/al/m/minidx.hpp"
#include "YRS/ds/basic/queue.hpp"

using MX = Minidx<int>;
using DS = seg_t<MX>;
using WM = wave_mat<int, 1, MX, DS>;
void Yorisou() {
  INT(N, s, t);
  --s, --t;
  VEC(int, a, N);
  vc<int> V = argsort(a);
  vc<int> to(N);
  FOR(i, N) to[V[i]] = i;
  a = rearrange(a, V);
  s = to[s], t = to[t];

  WM wm0(N, [&](int i) -> pair<int, PII> {
    return {V[i], {i, i}};
  });
  WM wm1(N, [&](int i) -> pair<int, PII> {
    int idx = V[i];
    return {idx + a[i], {idx - a[i], i}};
  });

  vc<int> dis(N, inf<int>);
  queue<int> q;
  Z upd = [&](int i, int d) {
    dis[i] = d;
    wm0.set(i, MX::unit());
    wm1.set(i, MX::unit());
    q.eb(i);
  };
  upd(s, 0);
  while (si(q)) {
    int i = pop(q), idx = V[i];
    while (1) {
      Z [mn, id] = wm0.prod(i + 1, N, idx - a[i], idx + a[i] + 1);
      if (mn == inf<int>) break;
      upd(id, dis[i] + 1);
    }
    while (1) {
      Z [mn, id] = wm1.prod(0, i, V[i], inf<int>);
      if (mn > V[i]) break;
      upd(id, dis[i] + 1);
    }
  }
  print(dis[t]);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}