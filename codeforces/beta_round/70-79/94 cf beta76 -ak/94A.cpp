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
  map<string, string> mp;
  FOR(i, 10) {
    STR(s);
    mp[s] = to_s(i);
  }
  string a;
  FOR(i, 8) a += mp[s.substr(i * 10, 10)];
  print(a);
}
#include "YRS/Z_H/main.hpp"