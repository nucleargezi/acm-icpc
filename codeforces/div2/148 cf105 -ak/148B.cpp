#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using re = ld;
void Yorisou() {
  LL(v, vv, T, F, C);
  if (v >= vv) return print(0);
  int s = 0;
  for (re t = T + re(v * T) / (vv - v); t < re(C) / v; ++s) {
    t += (2.l * v * t + vv * F) / (vv - v);
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}