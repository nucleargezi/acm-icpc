#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam_lct.hpp"

void Yorisou() {
  INT(Q);
  sam_lct ss(2'000'000);
  STR(s);
  for (char &c : s) c -= 'A';
  int x = 0;
  for (int c : s) x = ss.add(x, c);

  int rs = 0;
  FOR(Q) {
    STR(op, s);
    int n = si(s), k = rs;
    for (char &c : s) c -= 'A';
    FOR(i, n) k = (k * 131 + i) % n, swap(s[i], s[k]);
    if (op[0] == 'A') {
      for (int c : s) x = ss.add(x, c);
    } else {
      int c = ss.count(s);
      print(c);
      rs ^= c;
    }
  }
}

int main() {
  Yorisou();
  return 0;
}