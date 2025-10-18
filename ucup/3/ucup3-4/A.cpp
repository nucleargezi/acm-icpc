#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  INT(N);
  STR(s);
  for (char &c : s) {
    if (c == 'U') c = 3;
    if (c == 'T') c = 2;
    if (c == 'P') c = 1;
    if (c == 'C') c = 0;
  }
  vector<int> v[4];
  int sz[4];
  FOR(i, 0, N) v[(int)s[i]].ep(i);
  FOR(i, 0, 4) sz[i] = len(v[i]);

  int p = -1;
  for (int i = 4; i--; ) {
    int t = upper_bound(v[i], p);
    if (t == sz[i]) return print(-1);
    p = v[i][t];
  }

  int ans = 4;
  FOR(i, 1, N - 2) if (s[i] == 2) {
    int p = i;
    int t = lower_bound(v[3], p) - 1;
    if (t < 0) continue;
    t = upper_bound(v[1], p);
    if (t == sz[1]) continue;
    int l = i, r = v[1][t];
    p = v[1][t];
    t = upper_bound(v[0], p);
    if (t == sz[0]) continue;

    bool fail = 1;
    t = lower_bound(v[0], l);
    if (t == sz[0] or v[0][t] > r) fail = 0;
    t = lower_bound(v[3], l);
    if (t == sz[3] or v[3][t] > r) fail = 0;
    if (not fail) chmin(ans, 3);
  }

  FOR(i, 0, N - 1) {
    if (s[i] == 3 and s[i + 1] == 2) {
      int p = i + 1;
      int t = upper_bound(v[1], p);
      if (t == sz[1]) continue;
      int fi = v[1][t];
      t = upper_bound(v[0], p);
      if (t == sz[0]) continue;
      int se = v[0][t];
      if (fi < se) chmin(ans, 2);
    }
  }
  FOR(i, 0, N - 1) {
    if (s[i] == 2 and s[i + 1] == 1) {
      int p = i;
      int t = lower_bound(v[3], p) - 1;
      if (t < 0) continue;
      p = i + 1;
      t = upper_bound(v[0], p);
      if (t == sz[0]) continue;
      chmin(ans, 2);
    }
  }
  FOR(i, 0, N - 1) {
    if (s[i] == 1 and s[i + 1] == 0) {
      int p = i;
      int t = lower_bound(v[2], p) - 1;
      if (t < 0) continue;
      int fi = v[2][t];
      t = lower_bound(v[3], p) - 1;
      if (t < 0) continue;
      int se  = v[3][t];
      if (fi > se) chmin(ans, 2);
    }
  }

  FOR(i, 0, N - 2) {
    if (s[i] == 3 and s[i + 1] == 2 and s[i + 2] == 1) {
      int p = i + 2;
      int t = lower_bound(v[0], p);
      if (t == sz[0]) continue;
      chmin(ans, 1);
    }
  }
  FOR(i, 0, N - 2) {
    if (s[i] == 2 and s[i + 1] == 1 and s[i + 2] == 0) {
      int p = i;
      int t = lower_bound(v[3], p) - 1;
      if (t < 0) continue;
      chmin(ans, 1);
    }
  }

  FOR(i, 0, N - 3) {
    if (s[i] == 3 and s[i + 1] == 2 and s[i + 2] == 1 and s[i + 3] == 0)
      ans = 0;
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"