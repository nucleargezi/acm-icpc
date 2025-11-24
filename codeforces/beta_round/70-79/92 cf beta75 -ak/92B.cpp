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
  vector<int> q;
  for (char c : s) q.ep(c - '0');
  int ans = 0;
  while (len(q) > 1) {
    if (q.back() == 0) {
      q.pop_back(), ++ans;
      continue;
    }
    ++ans;
    while (not q.empty() and q.back() == 1) q.pop_back(), ++ans;
    if (q.empty()) q.ep(1);
    else q.back() = 1;
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"