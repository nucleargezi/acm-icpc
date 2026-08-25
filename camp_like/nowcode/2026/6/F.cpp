#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/zfunction.hpp"
#include "YRS/gg/count_topo.hpp"

void Yorisou() {
  STR(s);
  int N = si(s);
  Z sl = z_function(s);
  constexpr int n = 26;
  vc<vc<int>> g(n);
  FOR(i, 1, N) {
    int sz = sl[i];
    if (sz == N - i) return print(0);
    g[s[sz] - 'a'].ep(s[i + sz] - 'a');
  }
  print(count_topo<uint>(g));
}

int main() {
  Yorisou();
  return 0;
}