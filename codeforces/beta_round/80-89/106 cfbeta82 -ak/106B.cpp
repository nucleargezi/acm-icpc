#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using T = array<int, 4>;
void Yorisou() {
  INT(N);
  VEC(T, a, N);
  vc<char> vis(N, 1);
  FOR(i, N) FOR(k, N) if (i != k) {
    bool f = 1;
    FOR(j, 3) f &= a[i][j] < a[k][j];
    if (f) vis[i] = 0;
  }
  int s = inf<int>, id = -1;
  FOR(i, N) if (vis[i] and chmin(s, a[i][3])) id = i + 1;
  print(id);
}

int main() {
  Yorisou();
  return 0;
}