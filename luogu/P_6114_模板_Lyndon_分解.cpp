#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/string/lyndon.hpp"

// #define tests
void Yorisou() {
  STR(s);
  int ans = 0;
  for (int x : lyndon(s)) ans ^= x;
  print(ans);
}
#include "YRS/Z_H/main.hpp"