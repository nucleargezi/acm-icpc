// #define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
struct bs {
  int N;
  vector<ull> a;

  bs(int N) : N(N), a(N / 64 + 1) {};

  void set(int x) { a[x / 64] |= 1ull << (x & 63); }
  void reset(int x) { a[x / 64] &= ~(1ull << (x & 63)); }
  void reset() { fill(all(a), 0); }

  int prev(int i) {
    int k = i >> 6;
    if ((i & 63) < 63) {
      ull x = a[k];
      x &= (1ull << ((i & 63) + 1)) - 1;
      if (x) return k << 6 | topbit(x);
      --k;
    }
    FOR_R(i, k + 1) if (a[i]) return i << 6 | topbit(a[i]);
    return -1;
  }
  int next(int i) {
    int k = i >> 6;
    ull x = a[k];
    int s = i & 63;
    x = (x >> s) << s;
    if (x) return k << 6 | lowbit(x);
    FOR(i, k + 1, N / 64 + 1) if (a[i]) return i << 6 | lowbit(a[i]);
    return N;
  }
};
void Yorisou() {
  INT(N, M);
  VEC(string, s, N);
  vector v(N, bs(M)), g(M, bs(N));
  Z set = [&]() -> void {
    FOR(i, N) v[i].reset();
    FOR(i, M) g[i].reset();
    FOR(i, N) FOR(k, M) if (s[i][k] != '.') v[i].set(k);
    FOR(i, N) FOR(k, M) if (s[i][k] != '.') g[k].set(i);
  };
  Z upd = [&](int &x, int &y) -> bool {
    if (s[x][y] == 'L') {
      int n = v[x].prev(y);
      return n != -1 ? y = n, 1 : 0;
    } else if (s[x][y] == 'R') {
      int n = v[x].next(y);
      return n != M ? y = n, 1 : 0;
    } else if (s[x][y] == 'U') {
      int n = g[y].prev(x);
      return n != -1 ? x = n, 1 : 0;
    } else {
      int n = g[y].next(x);
      return n != N ? x = n, 1 : 0;
    }
  };
  int mx = 0, c = 1;
  FOR(i, N) FOR(k, M) if (s[i][k] != '.') {
    set();
    int w = 1, x = i, y = k;
    v[x].reset(y), g[y].reset(x);
    for (; upd(x, y); ++w, v[x].reset(y), g[y].reset(x));
    if (chmax(mx, w)) c = 1;
    else if (mx == w) ++c;
  }
  print(mx, c);
}
#include "YRS/Z_H/main.hpp"