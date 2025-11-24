#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
constexpr string c[]{"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
int f(const string &s) {
  FOR(i, 12) if (c[i] == s) return i;
  return -1;
}
void Yorisou() {
  STR(a, b, c);
  int x = f(a), y = f(b), z = f(c);
  for (int i = 3; i--; swap(x, y), swap(y, z)) 
    for (int i = 2; i--; swap(y, z)) {
      if (y == (x + 4) % 12 and z == (y + 3) % 12) return print("major");
      if (y == (x + 3) % 12 and z == (y + 4) % 12) return print("minor");
    }
  print("strange");
}
#include "YRS/Z_H/main.hpp"