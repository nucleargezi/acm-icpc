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
  int ans = stoi(s), N = len(s);
  FOR(i, N) FOR(k, i + 1, N) {
    swap(s[i], s[k]);
    chmax(ans, stoi(s));
    swap(s[i], s[k]);
  }
  print(ans);
}
#include "YRS/aa/main.hpp"