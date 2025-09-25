#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/hashmap.hpp"

// #define tests
int H(int x, int y, int s) { return x * 2000 + y * 10 + s; }
void Yorisou() {
  INT(x, y, N, d);
  VEC(PII, p, N);
  hash_map<char> mem;
  Z f = [&](Z &f, int x, int y, int s) -> bool {
    if (x * x + y * y > d * d) return true;
    int h = H(x, y, s);
    if (mem.contains(h)) return mem[h];
    for (Z [dx, dy] : p) {
      if (not f(f, x + dx, y + dy, s ^ 1)) {
        return mem[h] = 1, true;
      }
    }
    return mem[h] = 0, false;
  };
  print(f(f, x, y, 0) ? "Anton" : "Dasha");
}
#include "YRS/Z_H/main.hpp"