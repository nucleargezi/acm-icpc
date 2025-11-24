#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  char a[5][5]{};
  INT(N);
  FOR(N) {
    INT(x, y);
    --x, --y;
    a[x][y] = a[y][x] = 1;
  }
  FOR(s, 1 << 5) if (pc(s) == 3) {
    int v[3], t = 0;
    FOR(i, 5) if (s >> i & 1) v[t++] = i;
    Z [x, y, z] = v;
    if (a[x][y] and a[x][z] and a[y][z]) return print("WIN");
    if (not(a[x][y] + a[x][z] + a[y][z])) return print("WIN");
  }
  print("FAIL");
}
#include "YRS/Z_H/main.hpp"