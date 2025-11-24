#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  STR(s, t);
  for (Z &c : s) c -= 'a';
  for (Z &c : t) c -= 'a';
  int a[26]{};
  for (int c : t) a[c] = 1;
  for (int c : s) a[c] = 0;
  FOR(i, 26) if (a[i]) return print(-1);
  int ans = 1;
  vector<int> v[26];
  for (int i = 0; int c : s) v[c].ep(i++);
  for (int i = 0; int c : t) {
    int nx = lower_bound(v[c], i);
    if (nx == len(v[c])) ++ans, i = 0, nx = lower_bound(v[c], i);
    i = v[c][nx] + 1;
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"