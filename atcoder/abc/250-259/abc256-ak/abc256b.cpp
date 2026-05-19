#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  vc<int> s;
  int rs = 0;
  FOR(N) {
    INT(x);
    s.insert(bg(s), 0);
    for (int &e : s) e += x;
    while (si(s) and s.back() >= 4) pop(s), ++rs;
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}