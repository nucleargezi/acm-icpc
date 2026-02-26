#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/flow/BM.hpp"

#define tests 0
#define fl 0
#define DB 10
TE struct retsu {
  int N, M;
  vc<T> a;
  retsu(int N, int M) : N(N), M(M), a(N * M) {}
  T* operator[](int i) { return a.data() + i * M; }
};
void Yorisou() {
  INT(N, M);
  retsu<int> a(N, N);
  FOR(M) {
    INT(x, y);
    --x, --y;
    a[x][y] = 1;
  }
  Z id = [&](int x, int y) -> int { return x * N + y; };
  Z ck = [&](int x, int y) -> bool { return max(x, y) < N and min(x, y) >= 0; };
  static constexpr int dx[] = {1, 1, -1, -1, 2, 2, -2, -2},
                       dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

  graph g(N * N);
  FOR(i, N) FOR(k, N) {
    if (a[i][k] or not((i + k) & 1)) continue;
    FOR(d, 8) {
      int x = i + dx[d], y = k + dy[d];
      if (ck(x, y) and not a[x][y]) g.add(id(i, k), id(x, y));
    }
  }
  g.build();
  B_matching f(g);
  print(len(f.iset()) - SUM(a.a));
}
#include "YRS/aa/main.hpp"