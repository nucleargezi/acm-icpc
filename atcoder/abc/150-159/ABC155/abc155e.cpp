#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  int N = si(s), a = 0, b = inf<int> / 2;
  FOR(i, N) {
    int aa = inf<int>, bb = inf<int>, y = s[N - i - 1] - '0';
    FOR(x, 10) {
      int ad = x + y, f = ad / 10;
      ad %= 10;
      if (f) chmin(bb, a + ad + x);
      else chmin(aa, a + ad + x);
      ad = x + y + 1, f = ad / 10;
      ad %= 10;
      if (f) chmin(bb, b + ad + x);
      else chmin(aa, b + ad + x);
    }
    a = aa, b = bb;
  }
  print(min(a, b + 1));
}

int main() { Yorisou(); }