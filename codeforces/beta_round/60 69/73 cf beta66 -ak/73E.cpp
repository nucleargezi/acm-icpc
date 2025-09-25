#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/PR/primtable.hpp"
#include "YRS/ds/basic/hashmap.hpp"

// #define tests
void Yorisou() {
  INT(N, x);
  vector pr = primtable(2'000'000'0);
  VEC(int, a, N);
  hash_map<char> vis;
  for (Z x : a) vis[x] = 1;
  if (x == 2) return print(0);
  if (vis[1]) return print(1);
  if (x > pr.back()) return print(-1);
  int ans = 0;
  for (Z s : pr) {
    if (s >= x) break;
    if (vis[s]) ++ans;
    else return print(-1);
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"