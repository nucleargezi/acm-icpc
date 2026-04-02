#include "YRS/all.hpp"

constexpr int a[]{1, 1, -1, -1, 2, 2, -2, -2}, 
              b[]{2, -2, 2, -2, 1, -1, 1, -1};
void Yorisou() {
  INT(x, y);
  FOR(i, 8) {
    if (a[i] == x and b[i] == y) return YES();
    FOR(k, 8) {
      if (a[i] + a[k] == x and b[i] + b[k] == y) return YES();
      FOR(j, 8) {
        if (a[i] + a[k] + a[j] == x and b[i] + b[k] + b[j] == y) return YES();
      }
    }
  }
  NO();
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"