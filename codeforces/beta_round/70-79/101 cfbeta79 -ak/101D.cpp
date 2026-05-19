#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/Basic.hpp"

using re = ld;
struct dat {
  int s;
  ll sz;
  re rs;
};
void Yorisou() {
  INT(N);
  graph g(N);
  g.sc<1>();
  Z f = [&](Z &f, int n, int p) -> dat {
    vc<dat> v;
    for (Z &&e : g[n]) if (e != p) {
      Z x = f(f, e, n);
      x.rs += x.s * e.w;
      x.sz += e.w;
      v.ep(x);
    }
    sort(v, [&](var x, var y) { return x.sz * y.s < y.sz * x.s; });
    dat s{1, 0, 0};
    for (var x : v) {
      s.rs += x.rs + s.sz * 2 * x.s;
      s.s += x.s;
      s.sz += x.sz;
    }
    return s;
  };
  setp(10);
  print(f(f, 0, 0).rs / (N - 1));
}

int main() {
  Yorisou();
  return 0;
}