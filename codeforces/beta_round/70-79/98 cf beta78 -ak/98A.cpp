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
  map<int, int> mp;
  FOR(i, 6) ++mp[s[i]];
  vc<int> g;
  for (Z [x, y] : mp) g.ep(y);
  sort(g);
  map<vc<int>, int> me;
  me[{6}] = 1;
  me[{1, 5}] = 1;
  me[{2, 4}] = 2;
  me[{3, 3}] = 2;
  me[{1, 1, 4}] = 2;
  me[{1, 2, 3}] = 3;
  me[{2, 2, 2}] = 6;
  me[{1, 1, 1, 3}] = 5;
  me[{1, 1, 2, 2}] = 8;
  me[{1, 1, 1, 1, 2}] = 15;
  me[{1, 1, 1, 1, 1, 1}] = 30;
  print(me[g]);
}
#include "YRS/Z_H/main.hpp"