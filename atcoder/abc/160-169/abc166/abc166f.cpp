#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  INT(N);
  VEC(int, f, 3);
  vc<PII> g(N + 1);
  FOR(i, N) {
    STR(s);
    if (s == "AB") g[i] = {0, 1};
    if (s == "AC") g[i] = {0, 2};
    if (s == "BC") g[i] = {1, 2};
  }
  g[N] = {0, 1};
  string s;
  Z go = [&](int a, int b) {
    ++f[a], --f[b];
    s += 'A' + a;
  };
  FOR(i, N) {
    var [a, b] = g[i];
    if (max(f[a], f[b]) == 0) return No();
    if (f[a] == 0) go(a, b);
    else if (f[b] == 0) go(b, a);
    else {
      var [aa, bb] = g[i + 1];
      if (a == aa or a == bb) go(a, b);
      else go(b, a);
    }
  }
  Yes();
  FOR(i, N) print(s[i]);
}

int main() { Yorisou(); }