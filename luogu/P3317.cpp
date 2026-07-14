#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/det.hpp"

using re = ld;
constexpr re eps = 1e-12l;

re matrix_tree(int N, const vc<tuple<int, int, re>> &es) {
  vc<vc<re>> a(N - 1, vc<re>(N - 1));
  Z ins = [&](int f, int t, re w) {
    if (t == 0) return;
    int x = t - (t > 0);
    a[x][x] = a[x][x] + w;
    if (f != 0) {
      int y = f - (f > 0);
      a[x][y] = a[x][y] - w;
    }
  };
  for (var [f, t, w] : es) if (f != t) {
    re c = w;
    ins(f, t, c), ins(t, f, c);
  }
  return det(std::move(a));
}

void Yorisou() {
  INT(N);
  vc<vc<re>> a(N, vc<re>(N));
  IN(a);
  re bs = 1;
  vc<tuple<int, int, re>> es;
  FOR(i, N) {
    FOR(k, i + 1, N) {
      re x = a[i][k];
      x = clamp(x, eps, 1 - eps);
      bs *= (1 - x);
      es.ep(i, k, x / (1 - x));
    }
  }
  print(bs * matrix_tree(N, es));
}

int main() {
  Yorisou();
  return 0;
}