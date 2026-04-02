#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  ll s = 0;
  FOR(N) {
    STR(dat);
    int p = dat.find(":");
    int a = stoi(dat.substr(0, p)), b = stoi(dat.substr(p + 1));
    IN(dat);
    p = dat.find(":");
    int c = stoi(dat.substr(0, p)), d = stoi(dat.substr(p + 1));
    ll x = a * 60 + b, y = c * 60 + d;
    if (x > y) y += 1440;
    s += y - x;
  }
  print(s);
}
#include "YRS/aa/main.hpp"