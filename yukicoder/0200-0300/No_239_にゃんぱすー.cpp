#include "YRS/all.hpp"

void Yorisou() {
  INT(N);
  vc<int> c(N);
  FOR(i, N) FOR(k, N) {
    STR(s);
    c[k] += s == "nyanpass";
  }
  int s = 0;
  FOR(i, N) s += c[i] == N - 1;
  if (s != 1) return print(-1);
  FOR(i, N) if (c[i] == N - 1) print(i + 1);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"