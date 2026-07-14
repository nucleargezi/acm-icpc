#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/line_prog.hpp"

using re = double;
void Yorisou() {
  INT(M, N);
  VEC(re, c, M);
  vc<vc<re>> a(N, vc<re>(M));
  vc<re> b(N);
  FOR(i, N) IN(a[i], b[i]);
  Z [op, s, x] = line_prog(a, b, c);
  if (op < 0) return print("Infeasible");
  if (op > 0) return print("Unbounded");
  setp(12);
  print(s);
  print(x);
}

int main() {
  Yorisou();
  return 0;
}