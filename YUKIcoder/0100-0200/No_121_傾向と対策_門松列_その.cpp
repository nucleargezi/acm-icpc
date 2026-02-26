#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/mod/mint.hpp"
#include "YRS/ds/fenw/fenw.hpp"
#include "YRS/al/m/add.hpp"

#define tests 0
#define fl 0
#define DB 10
using MX = monoid_add<ll>;
using BIT = fenw<MX>;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<int> f(a);
  unique(f);
  for (int &x : a) x = lb(f, x);

  BIT l(N), r(N), c(N);
  for (int x : a) r.multiply(x, 1);
  ll s = 0;
  for (int x : a) {
    s += l.prod(x) * r.prod(x);
    s += l.prod(x + 1, N) * r.prod(x + 1, N);
    s -= c.prod_all() - c.prod(x, x + 1);
    ll lx = l.prod(x, x + 1), rx = r.prod(x, x + 1);
    c.multiply(x, -lx * rx);
    c.multiply(x, (lx + 1) * (rx - 1));
    r.multiply(x, -1);
    l.multiply(x, 1);
  }
  print(s);
}
#include "YRS/aa/main.hpp"