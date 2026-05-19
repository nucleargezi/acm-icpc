#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/tr/hld_st.hpp"
#include "YRS/flow/max_flow.hpp"
#include "YRS/al/m/min.hpp"

using MX = Min<int>;
void Yorisou() {
  INT(N, M);
  ++N;
  max_flow<int> g(N, 0, N - 1);
  FOR(M) {
    INT(f, t, w);
    g.add(f, t, w, w);
  }

  graph ng(N);
  vector es = g.gomory_hu();
  for (var [f, t, w] : es) ng.add(f, t);
  ng.build();
  hld v(ng);
  hld_st<int, MX, 1> seg(v, [&](int i) { return get<2>(es[i]); });
  
  INT(Q);
  FOR(Q) {
    INT(f, t);
    print(seg.prod(f, t));
  }
}

int main() {
  Yorisou();
  return 0;
}