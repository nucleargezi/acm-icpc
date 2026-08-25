#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void slv() {
  INT(N);
  STR(s);
  int c[10]{}, cc[10]{};
  for (int x : s) cc[x - '0'] += 1;
  print(bina([&](int n) -> bool {
    copy_n(cc, 10, c);
    if (c[0] >= n) {
      c[0] -= n;
      int s = 0, ss = 0;
      FOR(i, 6, 10) s += c[i];
      FOR(i, 6) ss += c[i];
      int nd = 3 * n;
      nd -= min(s, n * 2);
      return nd <= ss;
    } else {
      int fi = n;
      fi -= c[0];
      c[0] = 0;
      c[1] -= fi * 2;
      if (c[1] < 0) return 0;
      int lm = n * 2 - fi, s = 0, ss = 0;
      FOR(i, 6, 10) s += c[i];
      FOR(i, 6) ss += c[i];
      int nd = 3 * n - fi;
      nd -= min(lm, s);
      return nd <= ss;
    }
  }, 0, N / 4 + 1));
}

int main() {
  INT(T);
  FOR(T) slv();
}