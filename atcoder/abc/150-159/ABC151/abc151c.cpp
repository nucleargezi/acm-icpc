#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  INT(N, M);
  map<int, int> mp;
  int c = 0, s = 0;
  FOR(M) {
    INT(x);
    STR(op);
    int &v = mp[x];
    if (op == "AC") {
      if (v != -1) s += v, v = -1, ++c;
    } else {
      if (v != -1) v += 1;
    }
  }
  print(c, s);
}

int main() { Yorisou(); }