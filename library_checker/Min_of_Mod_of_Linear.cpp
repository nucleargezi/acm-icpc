// https://icpc.bjtu.edu.cn/problem/11381
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/min_line.hpp"

void Yorisou() {
  LL(N, p, a, b);
  print(min_line(0, N, a, b, p).se);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}