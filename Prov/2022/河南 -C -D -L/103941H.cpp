#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n, s, t);
  --s, --t;
  VEC(string, a, 2);
  vector ok(2, vector(n, vector<u8>(4)));
  vector vis(2, vector<u8>(n));
  constexpr int dx[]{-1, 1, 0, 0};
  constexpr int dy[]{0, 0, 1, -1};
  meion f = [&](meion &f, int x, int y, int op) -> void {
    if (vis[x][y]) iroha;
    vis[x][y] = 1;
    ok[x][y][op] = 1;
    FOR(i, 4) {
      int xx = dx[i] + x, yy = dy[i] + y;
      if (xx < 0 or yy < 0 or xx > 1 or yy > n - 1) continue;
      if (xx != x) {
        if (a[x][y] == 'I') {
          if (op == 0) {
            if (a[xx][yy] == 'I') {
              if (not ok[xx][yy][0]) {
                f(f, xx, yy, 0);
              }
            } else {
              if (x < xx) {
                for (int op : {0, 3}) {
                  if (not ok[xx][yy][op]) f(f, xx, yy, op);
                }
              } else {
                for (int op : {1, 2}) {
                  if (not ok[xx][yy][op]) f(f, xx, yy, op);
                }
              }
            }
          }
        } else {
          if (op == 0 or op == 3) {
            if (x > xx) {
              if (a[xx][yy] == 'L') {
                for (int op : {1, 2}) {
                  if (not ok[xx][yy][op]) f(f, xx, yy, op);
                }
              }
            }
          } else {
            if (x < xx) {
              if (a[xx][yy] == 'I') {
                if (not ok[xx][yy][0]) f(f, xx, yy, 0);
              } else {
                for (int op : {0, 3}) {
                  if (not ok[xx][yy][op]) f(f, xx, yy, op);
                }
              }
            }
          }
        }
      } else {
        if (a[x][y] == 'I') {
          if (op == 1) {
            if (a[xx][yy] == 'I') {
              if (not ok[xx][yy][1]) f(f, xx, yy, 1);
            } else {
              if (yy > y) {
                for (int op : {2, 3}) {
                  if (not ok[xx][yy][op]) f(f, xx, yy, op);
                }
              } else {
                for (int op : {0, 1}) {
                  if (not ok[xx][yy][op]) f(f, xx, yy, op);
                }
              }
            }
          }
        } else {
          if (yy > y) {
            if (op == 0 or op == 1) {
              if (a[xx][yy] == 'I') {
                if (not ok[xx][yy][1]) f(f, xx, yy, 1);
              } else {
                for (int op : {2, 3}) {
                  if (not ok[xx][yy][op]) f(f, xx, yy, op);
                }
              }
            }
          } else {
            if (op == 2 or op == 3) {
              if (a[xx][yy] == 'I') {
                if (not ok[xx][yy][1]) f(f, xx, yy, 1);
              } else {
                for (int op : {0, 1}) {
                  if (not ok[xx][yy][op]) f(f, xx, yy, op);
                }
              }
            }
          }
        }
      }
    }
    vis[x][y] = 0;
  };
  if (a[0][s] == 'I') {
    f(f, 0, s, 0);
  } else {
    f(f, 0, s, 0);
    if ((a[1][t] == 'I' and ok[1][t][0]) or
        (a[1][t] != 'I' and (ok[1][t][1] or ok[1][t][2]))) {
      iroha YES();
    }
    ok = vector(2, vector(n, vector<u8>(4)));
    f(f, 0, s, 3);
  }
  YES((a[1][t] == 'I' and ok[1][t][0]) or
      (a[1][t] != 'I' and (ok[1][t][1] or ok[1][t][2])));
}
#include "MeIoN_Lib/Z_H/main.hpp"