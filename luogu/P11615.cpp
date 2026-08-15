#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/hashmap.hpp"

void Yorisou() {
  INT(Q);
  hashmap<ull> mp(Q);
  ull s = 0;
  FOR(i, Q) {
    ULL(a, b);
    Z &f = mp[a];
    s += f * (i + 1);
    f = b;
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}