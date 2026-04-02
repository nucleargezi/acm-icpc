#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  FOR(i, N) a[i] %= 4;
  vector<int> v[4];
  FOR(i, N) v[a[i]].ep(i);
  vector<int> ans;

  while (len(v[0])) ans.ep(pop(v[0]));
  while (len(v[1]) and len(v[3])) {
    ans.ep(pop(v[3]));
    ans.ep(pop(v[1]));
  }
  while (len(v[1]) > 1 and len(v[2])) {
    ans.ep(pop(v[2]));
    ans.ep(pop(v[1]));
    ans.ep(pop(v[1]));
  }
  int f = 0;
  if (len(v[1]) and len(v[2])) {
    ans.ep(pop(v[2]));
    ans.ep(pop(v[1]));
    f = 3;
  }
  int nd = len(v[3]) / 2;
  while (len(v[2]) - nd > 1) {
    ans.ep(pop(v[2]));
    ans.ep(pop(v[2]));
  }
  while (len(v[3])) {
    ans.ep(pop(v[3]));
    f += 3;
    f %= 4;
    if (f == 2 and len(v[2])) {
      f = 0;
      ans.ep(pop(v[2]));
    }
  }
  FOR(i, 4) while (len(v[i])) ans.ep(pop(v[i]));
  for (int s = 0; int x : ans) {
    s += a[x];
    if (s % 4 == 1) return print(-1);
  }

  for (int &x : ans) ++x;
  print(ans);
}
#include "YRS/Z_H/main.hpp"