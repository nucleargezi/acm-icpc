#include "YRS/all.hpp"

bool ck(char c) { return c == '4' or c == '7'; }
void Yorisou() {
  STR(a, b);
  if (si(a) != si(b)) return print(si(a) > si(b) ? a : b);
  int n = si(a);
  vc<int> I(10);
  iota(all(I), 0);
  swap(I[4], I[7]);
  FOR(i, n) if (a[i] != b[i]) {
    return print(
        ((ck(a[i]) and ck(b[i])) ? I[a[i] - '0'] > I[b[i] - '0'] : a[i] > b[i])
            ? a
            : b);
  }
  print(a);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"