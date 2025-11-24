#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M, X);
  VEC(string, a, N);
  INT(sz);
  STR(s);
  vector<PII> S;
  map<char, vector<PII>> mp;
  FOR(i, N) FOR(k, M) {
    if (a[i][k] == 'S') S.ep(i, k);
    else mp[a[i][k]].ep(i, k);
  }
  map<char, bool> mem;
  Z f = [&](char c) -> bool {
    if (mem.contains(c)) return mem[c];
    for (Z [i, k] : mp[c]) 
      for (Z [x, y] : S) {
        x -= i, y -= k;
        if (x * x + y * y <= X * X) return mem[c] = 0;
      }
    return mem[c] = 1;
  };
  int ans = 0;
  for (char c : s) {
    if (c >= 'a' and c <= 'z') {
      if (not mp.contains(c)) return print(-1);
      continue;
    }
    c -= 'A' - 'a';
    if (S.empty() or not mp.contains(c)) return print(-1);
    ans += f(c);
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"