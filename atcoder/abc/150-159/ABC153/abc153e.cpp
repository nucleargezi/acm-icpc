#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(W, N);
  vc<int> f(W + 1, inf<int>);
  f[0] = 0;
  FOR(N) {
    INT(a, b);
    FOR(i, W + 1) if (f[i] != inf<int>) {
      chmin(f[min(i + a, W)], f[i] + b);
    }
  }
  print(f[W]);
}

int main() { Yorisou(); }