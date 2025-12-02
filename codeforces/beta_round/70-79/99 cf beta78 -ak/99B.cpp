#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/string/run_length.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  if (N == 2) {
    if (a[0] == a[1]) return print("Exemplary pages.");
    if ((a[0] + a[1]) & 1) return print("Unrecoverable configuration.");
    int x = 0, y = 1;
    if (a[0] > a[1]) swap(x, y);
    return print((a[y] - a[x]) / 2, "ml. from cup #" + to_s(x + 1), "to cup #" + to_s(y + 1) + ".");
  }
  map<int, vc<int>> mp;
  FOR(i, N) mp[a[i]].ep(i);
  if (len(mp) == 1) return print("Exemplary pages.");
  if (len(mp) == 3 and len(mp.begin()->se) == 1 and len(prev(mp.end())->se) == 1) {
    Z [a, v] = *mp.begin();
    Z [b, g] = *prev(mp.end());
    if (a + b != next(mp.begin())->fi * 2) return print("Unrecoverable configuration.");
    print((b - a) / 2, "ml. from cup #" + to_s(v[0] + 1), "to cup #" + to_s(g[0] + 1) + ".");
  } else print("Unrecoverable configuration.");
}
#include "YRS/Z_H/main.hpp"