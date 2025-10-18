#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N, a, b);
  vector<int> L, R;
  int d = N - 1;
  FOR(i, a - 1) L.ep(d--);
  FOR(i, b - 1) R.ep(d--);
  if (d < 0) return no();
  reverse(L);
  if (a != 1) while (d) L.ep(d--);
  else if (b != 1) {
    reverse(R);
    while (d) R.ep(d--);
    reverse(R);
  } else return no();
  L.ep(N);
  L.insert(L.end(), all(R));
  yes();
  print(L);
}
#include "YRS/Z_H/main.hpp"