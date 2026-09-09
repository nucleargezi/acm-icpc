#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using re = ld;

void Yorisou() {
  INT(N, K);
  vc<re> f(N);
  FOR(i, N) {
    INT(x);
    f[i] = re(x + 1) / 2;
  }
  f = pre_sum(f);
  re s = 0;
  FOR(i, N - K + 1) chmax(s, f[i + K] - f[i]);
  print(s);
}

int main() { Yorisou(); }