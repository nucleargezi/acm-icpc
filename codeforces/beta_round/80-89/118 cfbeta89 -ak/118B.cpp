#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  INT(N);
  retsu<int> a(N + N + 1, N + N + 1);
  FOR(i, N + N + 1) FOR(k, N + N + 1) {
    int x = i, y = k;
    chmin(x, N + N - x);
    chmin(y, N + N - y);
    a[i][k] = min(x, y);
  }
  vc<vc<int>> v(N + N + 1);
  FOR(i, N + N + 1) FOR(k, N + N + 1) {
    if ((i + k) & 1) continue;
    v[(i + k) >> 1].ep(a[i][k]);
  }
  FOR(i, N + N + 1) {
    put(string(abs(N - i) * 2, ' '));
    print(v[i]);
  }
}

int main() {
  Yorisou();
  return 0;
}