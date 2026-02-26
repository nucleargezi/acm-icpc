#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  if ((N * M) & 1) return NO();
  bool o = 0;
  if (N > M) swap(N, M), o = 1;

  using bs = bitset<1000>;
  vc<bs> a(N);
  vc<char> now{1};
  int c = 0;
  Z f = [&](Z &f, int p) -> void {
    if (c == (M + 1) >> 1) return;
    if (p >= N) {
      ++c;
      FOR(i, N) a[i][c - 1] = now[i];
      return;
    }
    now.ep(0);
    f(f, p + 1);
    now.back() = 1;
    f(f, p + 1);
    now.pop_back();
  };
  f(f, 1);

  int lm = (M + 1) >> 1;
  if (c != lm) return NO();
  
  Z same = [&](int i) -> bool {
    FOR(k, N) if (a[k][i] != now[k]) return 0;
    return 1;
  };
  Z fil = [&](int i) -> void {
    FOR(k, N) a[k][i] = now[k];
  };
  Z cp = [&](int i, int k) -> void {
    FOR(j, N) a[j][i] = not a[j][k];
  };

  now.resize(N);
  set<int> se;
  int jj = -1;
  for (int l = 1; l < N; l <<= 1) {
    FOR(j, N) now[j] = not((j / l) & 1);
    int gg = -1;
    FOR(i, lm) if (same(i)) {
      gg = i;
      break;
    }
    if (gg == -1) {
      FOR(i, lm) if (not se.contains(i)) {
        gg = i;
        break;
      }
      fil(gg);
    }
    se.eb(gg);
    if (l == 1) jj = gg;
  }

  if (M & 1) {
    int tt = lm;
    FOR(i, lm) if (i != jj) cp(tt++, i);
  } else {
    FOR(i, lm) cp(lm + i, i);
  }
  YES();
  if (o) {
    vc<bs> t(M);
    FOR(i, N) FOR(k, M) t[k][i] = a[i][k];
    a.swap(t);
    swap(N, M);
  }
  FOR(i, N) {
    FOR(k, M) cout << a[i][k];
    print();
  }
}
#include "YRS/aa/main.hpp"