#include <bits/stdc++.h>
using namespace std;

bool o(int x, int y) { return x > -1 and y > -1 and x < 9 and y < 10; }
constexpr int dx[]{2, 2, -2, -2, 1, -1, 1, -1},
              dy[]{1, -1, 1, -1, 2, 2, -2, -2},
              ddx[]{1, 1, -1, -1, 0, 0, 0, 0},
              ddy[]{0, 0, 0, 0, 1, 1, -1, -1};
void sol() {
  int x, y, xx, yy;
  cin >> x >> y >> xx >> yy;
  --x, --y, --xx, --yy;
  bool f = 0;
  for (int i = 8; i--; ) {
    int gx = x + dx[i], gy = y + dy[i];
    if (gx == xx and gy == yy) return cout << "NO\n", void();
  }
  for (int i = 8; i--; ) {
    int gx = x + dx[i], gy = y + dy[i];
    int px = x + ddx[i], py = y + ddy[i];
    if (o(gx, gy) and not(px == xx and py == yy)) {
      if (gx != xx and gy != yy) f = 1;
    }
  }
  cout << (f ? "NO\n" : "YES\n");
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while (T--) sol();
  return 0;
}