#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using T = pair<string, int>;
void Yorisou() {
  INT(N);
  VEC(T, a, N);
  sort(a, [&](var a, var b) { return a.se < b.se; });
  vc<int> b;
  FOR(i, N) {
    if (a[i].se > i) return print(-1);
    b.insert(bg(b) + i - a[i].se, i);
  }
  FOR(i, N) a[b[i]].se = i + 1;
  for (var [s, n] : a) print(s, n);
}

int main() {
  Yorisou();
  return 0;
}