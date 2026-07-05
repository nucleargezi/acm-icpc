#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  STR(s);
  map<int, int> a, b;
  FOR(i, si(s)) {
    (i & 1 ? a : b)[s[i]] += 1;
  }
  if (si(s) & 1) {
    int c = 0, d = 0;
    for (var [a, b] : b) if (b & 1) ++c;
    for (var [a, b] : a) if (b & 1) ++d;
    YES(min(c, d) == 0 and max(c, d) == 1 and
        ((d == 1 and ((si(s) / 2) & 1)) or (c == 1 and (~(si(s) / 2) & 1))));
  } else {
    YES(a == b);
  }
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}