#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
#include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10000
void Yorisou() {
  INT(N, K);
  VEC(string, s, N);
  int a = 0, b = 0;
  FOR(i, N) FOR(k, N) a += s[i][k] == 'x';
  FOR(i, N) FOR(k, N) b += s[i][k] == 'o';
  if (b > a) {
    FOR(i, N) FOR(k, N) {
      if (s[i][k] == 'x') s[i][k] = 'o';
      else if (s[i][k] == 'o') s[i][k] = 'x';
    }
    swap(a, b);
  }
  if (a > b + 1) return NIE();

  Z g = [&](char c) -> pair<int, vc<PII>> {
    int o = 0;
    vc<PII> wa;
    FOR(i, N) FOR(k, N) if (s[i][k] == c) {
      if (i + K - 1 < N) {
        bool e = 1;
        FOR(j, 1, K) e &= s[i][k] == s[i + j][k];
        if (e) {
          o = 1;
          FOR(j, K) wa.ep(i + j, k);
        }
      }
      if (k + K - 1 < N) {
        bool e = 1;
        FOR(j, 1, K) e &= s[i][k] == s[i][k + j];
        if (e) {
          o = 1;
          FOR(j, K) wa.ep(i, k + j);
        }
      }
      if (i + K - 1 < N and k + K - 1 < N) {
        bool e = 1;
        FOR(j, 1, K) e &= s[i][k] == s[i + j][k + j];
        if (e) {
          o = 1;
          FOR(j, K) wa.ep(i + j, k + j);
        }
      }
      if (i + K - 1 < N and k >= K - 1) {
        bool e = 1;
        FOR(j, 1, K) e &= s[i][k] == s[i + j][k - j];
        if (e) {
          o = 1;
          FOR(j, K) wa.ep(i + j, k - j);
        }
      }
    }
    if (len(wa) > K) {
      int c[6][6]{};
      for (Z [x, y] : wa) ++c[x][y];
      bool o = 0;
      FOR(i, N) FOR(k, N) if (c[i][k] == len(wa) / K) {
        o = 1;
        wa.resize(K);
        FOR(p, K - 1) if (wa[p] == PII{i, k}) swap(wa[p], wa[K - 1]);
        goto fal;
      }
      if (not o) return pair{2, vc<PII>{}};
    }
    fal:
    return pair{o, wa};
  };
  Z [oa, wa] = g('x');
  Z [ob, wb] = g('o');
  
  if (oa and ob) return NIE();
  if (oa == 2 or ob == 2) return NIE();
  if (oa and a == b) {
    FOR(i, N) FOR(k, N) {
      if (s[i][k] == 'x') s[i][k] = 'o';
      else if (s[i][k] == 'o') s[i][k] = 'x';
    }
    swap(oa, ob);
    swap(wa, wb);
  };
  bool cut = 0;
  FOR(i, N) FOR(k, N) if (s[i][k] == '.') cut = 1;
  if (cut) {
    if (not oa and not ob) return NIE();
    if (oa and a != b + 1) return NIE();
    if (ob and a != b) return NIE();
  } else {
    if (oa or ob) {
      if (oa and a < b) return NIE();
      if (ob and a > b) return NIE();
    }
  }
  bool vis[6][6]{};
  for (Z [x, y] : wa) vis[x][y] = 1;
  for (Z [x, y] : wb) vis[x][y] = 1;
  vc<PII> F, G;
  FOR(i, N) FOR(k, N) if (not vis[i][k] and s[i][k] != '.') {
    if (s[i][k] == 'x') F.ep(i, k);
    else G.ep(i, k);
  }
  for (Z [x, y] : wa) F.ep(x, y);
  for (Z [x, y] : wb) G.ep(x, y);
  vc<PII> ans;
  FOR(i, max(len(F), len(G))) {
    if (i < len(F)) ans.ep(F[i]);
    if (i < len(G)) ans.ep(G[i]);
  }
  TAK();
  for (Z [x, y] : ans) print(x + 1, y + 1);
}
#include "YRS/aa/main.hpp"