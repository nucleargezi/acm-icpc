#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/others/date_time.hpp"

void Yorisou() {
  INT(N);
  int rs = 0;
  FOR(i, 1, 13) {
    datetime g(N, i, 1);
    ++rs;
    for (bool ok = 0; g.m == i; ok = 1, ++g) {
      if (ok and g.wk() == 1) ++rs;
    }
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}