#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  vc<array<int, 2>> tr(N * N, {-1, -1});
  vc<int> c(N * N);
  int t = 0;
  STR(s);
  for (char &c : s) c -= '0';
  FOR(i, N) {
    int x = 0;
    FOR(k, i, N) {
      int ch = s[k], &to = tr[x][ch];
      if (to == -1) to = ++t;
      x = to;
      ++c[x];
    }
  }
  Z f = [&](Z &f, int n) -> void {
    if (n == -1) return;
    if (c[n] > 1) print(c[n]);
    f(f, tr[n][0]), f(f, tr[n][1]);
  };
  f(f, 0);
}

int main() { Yorisou(); }