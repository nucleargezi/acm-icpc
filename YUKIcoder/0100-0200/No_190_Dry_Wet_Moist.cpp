#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

int A(const vc<int> &a, bool g) {
  min_heap<int> l, r;
  int c = 0;
  for (int x : a) {
    if (x == 0) ++c;
    else (((x < 0) ^ g) ? l : r).eb(abs(x));
  }
  int s = 0;
  vc<int> f;
  while (not r.empty() and not l.empty()) {
    int x = pop(r), y = pop(l);
    if (y > x) ++s;
    else f.ep(y), r.eb(x);
  }
  while (not l.empty()) f.ep(pop(l));
  while (c and not f.empty()) ++s, --c, pop(f);
  s += len(f) >> 1;
  return s;
}
int B(const vc<int> &a) {
  map<int, int> A, B;
  int c = 0;
  for (int x : a) {
    if (x == 0) ++c;
    else (x < 0 ? A : B)[abs(x)] += 1;
  }
  c >>= 1;
  for (Z [x, y] : A) c += min(y, B[x]);
  return c;
}
void Yorisou() {
  INT(N);
  VEC(int, a, N << 1);
  print(A(a, 0), A(a, 1), B(a));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"