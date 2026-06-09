#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/divisors.hpp"
#include "YRS/pr/lpf_table.hpp"

const vc<int> lpf = lpf_table(1'00'000);
void Yorisou() {
  INT(N);
  vc<vc<int>> g(1'000'01);
  FOR(i, N) {
    INT(x, y);
    int s = 0;
    for (int e : divisor_by_lpf(x, lpf)) {
      s += lb(g[e], i - y) == si(g[e]);
      g[e].ep(i);
    }
    print(s);
  }
}

int main() {
  Yorisou();
  return 0;
}