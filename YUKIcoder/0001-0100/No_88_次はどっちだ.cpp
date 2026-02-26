#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  STR(s);
  map<string, int> mp{{"yukiko", 0}, {"oda", 1}};
  string na[]{"yukiko", "oda"};
  int x = 0, y = 0;
  for (string s; cin >> s; ) {
    for (char c : s) {
      if (c == 'b') ++x;
      if (c == 'w') ++y;
    }
  }
  x &= 1, y &= 1;
  print(na[x ^ y ^ mp[s]]);
}
#include "YRS/aa/main.hpp"