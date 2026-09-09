#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M, sx, sy, tx, ty);
  int op = (sx + sy) & 1, po = (tx + ty) & 1;
  print(op != po ? N * M / 2 * 2 : (N * M + 1 - op) / 2 * 2 - 1);

  bool tr = (N & 1) and not(M & 1);
  if (tr) swap(N, M), swap(sx, sy), swap(tx, ty);
  bool re = sy > ty;
  if (re) sy = M + 1 - sy, ty = M + 1 - ty;

  Z f = [&](int x, int y, int a, int b, bool t) {
    int h = abs(a - x) + 1, w = abs(b - y) + 1;
    Z ad = [&](int p, int q) {
      p = x + (a < x ? -p : p), q = y + (b < y ? -q : q);
      if (re) q = M + 1 - q;
      if (tr) swap(p, q);
      print(p, q);
    };
    Z g = [&](int p, int q, int h, int w, bool f = 0) {
      FOR(i, abs(h)) FOR(k, abs(w)) {
        int a = h < 0 ? -i : i, b = (i & 1) ? abs(w) - 1 - k : k;
        if (w < 0) b = -b;
        if (f) swap(a, b);
        ad(p + a, q + b);
      }
    };
    if (t and (h & 1)) g(0, 0, h, w);
    else if ((w & 1) == t) g(0, 0, w, h, 1);
    else if (t) g(0, 0, h - 2, w), g(h - 2, 0, w - 1, 2, 1), ad(h - 1, w - 1);
    else {
      g(0, 0, h - not(h & 1), 1);
      if (h & 1) g(h - 1, 1, -h, w - 1);
      else g(h - 2, 1, w - 1, 2, 1), g(h - 3, w - 1, 2 - h, 1 - w);
    }
  };
  
  int i = not(sx & 1), k = not(tx & 1), d = ty - sy - 1;
  if (d < 2) k = i ^ d;
  int a = i ? 1 : N, b = k ? 1 : N;

  f(sx, sy, N + 1 - a, 1, 0);
  f(sx + 1 - 2 * i, 1, a, sy, 1);
  if (d) f(a, sy + 1, N + 1 - a, ty - 1, i != k);
  f(b, ty, tx + 1 - 2 * k, M, 1);
  f(tx, M, N + 1 - b, ty, 0);
}

int main() { Yorisou(); }