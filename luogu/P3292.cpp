#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/hld_st.hpp"
#include "YRS/al/m/sp.hpp"

void Yorisou() {
  INT(N, Q);
  vc<sp<ll>> dat(N);
  FOR(i, N) {
    LL(x);
    dat[i].ins(x);
  }
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  hld_st<int, Sp<ll>> v(g, dat);
  FOR(Q) {
    INT(a, b);
    --a, --b;
    print(v.prod(a, b).max());
  }
}

int main() { Yorisou(); }