#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  const string B = "ROYGBIV";
  string s;
  FOR(i, N) s += B[i % 4];
  FOR(3) pop(s);
  FOR(i, 3) s += B[i + 4];
  print(s);
}
#include "YRS/Z_H/main.hpp"