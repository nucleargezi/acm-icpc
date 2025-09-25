#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
pair<int, int> read() {
  STR(s);
  FOR(i, 5) s[i] -= '0';
  return {s[0] * 10 + s[1], s[3] * 10 + s[4]};
}
void Yorisou() {
  Z [h, m] = read();
  print(360.L * (h % 12) / 12 + 30.L * m / 60, 360.L * m / 60);
}
#include "YRS/Z_H/main.hpp"