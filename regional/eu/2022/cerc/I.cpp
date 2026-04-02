#define YRSD
#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/g/scc.hpp"
#include "YRS/line/mat.hpp"

using re = ld;
void Yorisou() {
  INT(N, M);
  graph<re, 1> g(N);
  vc<int> in(N);
  vc<tuple<int, int, re>> es;
  FOR(i, N) {
    INT(sz);
    FOR(sz) {
      STR(s);
      int c = s.find(":");
      string a = s.substr(1, c - 1), b = s.substr(c + 1);
      int t = stoi(a);
      --t;
      re p = stold(b) / 100;
      if (s[0] == 'P') t += N;
      es.ep(i, t, p);
      if (t < N) ++in[t], g.add(i, t, p);;
    }
  }
  g.build();
  Z [T, id] = scc(g);
  g = graph<re, 1>(N + M);
  for (Z [f, t, w] : es) g.add(f, t, w);
  g.build();

  vc<vc<int>> v(T);
  FOR(i, N) v[id[i]].ep(i);
  sh(id, N + M);
  fill(all(id), -1);
  retsu<re> dp(N, M);
  FOR_R(i, T) {
    int sz = len(v[i]);
    FOR(k, sz) id[v[i][k]] = k;
    mat<re> to(sz << 1);
    vc<re> ss(sz);
    FOR(k, sz) {
      int f = v[i][k];
      re s = 0;
      for (Z &&e : g[f]) {
        if (id[e.to] != -1) to[k][id[e.to]] = e.w;
        else s += e.w;
      }
      to[k][k + sz] = s;
      ss[k] = s;
    }
    FOR(i, sz) to[i + sz][i + sz] = 1;
    FOR(15) to *= to;
    FOR(k, sz) {
      int f = v[i][k];
      FOR(j, sz) if (ss[j] != 0) {
        int m = v[i][j];
        re st = to[k][j + sz] / ss[j];
        for (Z &&e : g[m]) if (id[e.to] == -1) {
          if (e.to >= N) {
            dp[f][e.to - N] += e.w * st;
          } else {
            FOR(l, M) dp[f][l] += dp[e.to][l] * e.w * st;
          }
        }
      }
    }
    for (int x : v[i]) id[x] = -1;
  }

  setp(6);
  FOR(i, N) FOR(k, M) cout << dp[i][k] << " \n"[k + 1 == M];
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"