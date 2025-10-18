#include "YRS/all.hpp"

int N;
string s[10];
bool big(char c) {
  return c >= 'A' and c <= 'Z';
}
int good(char a, char b) {
  if (a == 'O' and b == 'O') return 1;
  if (a == 'M' and b == 'P') return 1;
  if (a == 'P' and b == 'M') return 1;
  return 0;
}
int keis() {
  int r = 0;
  FOR(i, N) FOR(k, N) {
    r += big(s[i][k]);
    if (i + 1 < N) r += good(s[i][k], s[i + 1][k]);
    if (k + 1 < N) r += good(s[i][k], s[i][k + 1]);
    if (i + 1 < N and k + 1 < N) r += good(s[i][k], s[i + 1][k + 1]);
    if (i + 1 < N and k - 1 > -1) r += good(s[i][k], s[i + 1][k - 1]);
  }
  return r;
}
void yorisou() {
  IN(N);
  FOR(i, 0, N) IN(s[i]);
  int sc = keis(), go = 1;
  cout << sc << ' ';
  while (go) {
    go = 0;
    for (int i = 0; i < N and not go; ++i) {
      for (int k = 0; k < N and not go; ++k) {
        if (not big(s[i][k]) and s[i][k] != '.') {
          s[i][k] += 'A' - 'a';
          int nc = keis();
          if (nc - 2 >= sc) sc = nc, go = 1;
          else s[i][k] -= 'A' - 'a';
        }
      }
    }
  }
  print(sc);
  FOR(i, N) print(s[i]);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  while (T--) yorisou();
  return 0;
}