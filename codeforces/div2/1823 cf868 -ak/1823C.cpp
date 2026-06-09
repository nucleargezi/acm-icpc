#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/lpf_table.hpp"
#include "YRS/pr/factors.hpp"

const vc<int> lpf = lpf_table(1'000'000'0);
int c[1000'000'1];
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<int> f;
  for (int x : a) for (var [a, b] : factor_by_lpf(x, lpf)) c[a] += b, f.ep(a);
  unique(f);
  int s = 0, ls = 0;
  for (int x : f) s += c[x] / 2, ls += c[x] & 1, c[x] = 0;
  print(s + ls / 3);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}