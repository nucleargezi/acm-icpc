#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void slv() {
  INT(N);
  int ls = 0, rs = 0;
  ll s = 0;
  FOR(i, N) {
    INT(x);
    x %= 5;
    if (x == 3) ++ls;
    if (x == 4) ++rs;
    if (x < 3) s += x;
  }
  int d = min(ls, rs);
  s += d << 1;
  ls -= d, rs -= d;
  s += ls / 2;
  if (ls & 1) s -= 2;
  s += rs / 3 * 2;
  rs %= 3;
  if (rs) s -= rs; 
  print(s);
}

int main() { slv(); }