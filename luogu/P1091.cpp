#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/seq/lis.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<int> L = lis_dp(a).se;
  reverse(a);
  vc<int> R = lis_dp(a).se;
  reverse(R);
  int s = 0;
  FOR(i, N) chmax(s, L[i] + R[i] - 1);
  print(N - s);
}

int main() {
  Yorisou();
  return 0;
}