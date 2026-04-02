#include "YRS/all.hpp"
#include "YRS/ds/bit/bit.hpp"
#include "YRS/al/m/add.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/jen/magic_square.hpp"

using DS = bit_t<monoid_add<ll>>;
using A = retsu<int>;
A make(int N, int t) {
  A a(N, N);
  int c = ceil(N, 2);
  FOR(i, N) FOR(k, N) {
    int x = (i + k + c) % N, y = (2 * i + k + t) % N;
    a[i][k] = N * x + y + 1;
  }
  return a;
}
void Yorisou() {
  INT(N);
  A a(N, N);
  IN(a);
  if (N == 1) return possible(), print(1);
  if (N == 2) return impossible();
  Z f = [&](const A &a, int w) -> bool {
    vc<int> v;
    int t = -1;
    FOR(i, N) FOR(k, N) {
      if (a[i][k] == w) t = i;
      else v.ep(a[i][k]);
    }
    DS bit(N * N + 2);
    int in = 0, se = 0;
    for (int x : v) {
      x %= N * N;
      int g = se - bit.prod(x);
      in ^= g & 1;
      bit.multiply(x, 1);
      ++se;
    }
    if (N & 1) return in;
    return in ^ ((N - t) & 1);
  };
  int st = f(a, 0);
  vc<A> c;
  if (N & 1) {
    if (N == 3) {
      A a = make(3, 1);
      c.ep(a);
      a.reverse();
      c.ep(a);
    } else {
      c.ep(make(N, 1));
      c.ep(make(N, 1 + gcd(N, 3)));
    }
  } else {
    A a = magic_square{}.run(N);
    c.ep(a);
    a.reverse();
    c.ep(a);
  }

  for (Z &a : c) {
    int in = f(a, N * N);
    if (in == st) {
      possible();
      print(a);
      return;
    }
  }
  impossible();
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"