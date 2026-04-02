#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
string s;
void yorisou() {
  const int N = len(s);
  FOR(i, N) s[i] -= '0';
  vector<u8> vis(100);
  int ans = 0;
  Z f = [&](Z &f, int x) -> void {
    if (x >= N) return ++ans, void();
    if (not vis[s[x]]) {
      vis[s[x]] = 1;
      f(f, x + 1);
      vis[s[x]] = 0;
    }
    if (x + 1 < N and s[x] != 0 and not vis[s[x] * 10 + s[x + 1]]) {
      vis[s[x] * 10 + s[x + 1]] = 1;
      f(f, x + 2);
      vis[s[x] * 10 + s[x + 1]] = 0;
    }
  };
  f(f, 0);
  print(ans);
}
void Yorisou() {
  while (IN(s)) yorisou();
}
#include "YRS/Z_H/main.hpp"