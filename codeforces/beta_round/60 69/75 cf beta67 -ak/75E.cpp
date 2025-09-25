#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ge/all.hpp"
#include "YRS/graph/Apck/dijkstra.hpp"

// #define tests
using RE = long double;
using P = point<RE>;
void Yorisou() {
  P s, t;
  IN(s, t);
  INT(N);
  VEC(P, p, N);
  graph<RE> g(N + 4);
  FOR(i, N) {
    int k = i + 1 < N ? i + 1 : 0;
    g.add(i, k, dist(p[i], p[k]));
  }
  FOR(i, N) FOR(k, i + 1, N) {
    g.add(i, k, dist(p[i], p[k]) * 2);
  }
  
  FOR(i, N) {
    int k = i + 1 < N ? i + 1 : 0;
    if (segment(p[i], p[k]).cross(segment(s, t), true) == 1) {
      P o = segment(p[i], p[k]).cross_point(line(s, t)).se;
      int ido = N + 2;
      g.add(ido, i, dist(o, p[i]));
      g.add(ido, k, dist(o, p[k]));
      FOR(i, N) g.add(ido, i, dist(o, p[i]) * 2);
      FOR(j, i + 1, N) {
        int l = j + 1 < N ? j + 1 : 0;
        if (segment(p[j], p[l]).cross(segment(s, t), true) == 1) {
          P v =segment(p[j], p[l]).cross_point(line(s, t)).se;
          if (dist(o, v) < 1e-12) continue;
          int idv = N + 3;
          g.add(idv, j, dist(v, p[j]));
          g.add(idv, l, dist(v, p[l]));
          FOR(i, N) g.add(idv, i, dist(v, p[i]) * 2);
          if (dist(v, s) < dist(o, s)) swap(v, o), swap(ido, idv);
          g.add(N + 1, idv, dist(v, t));
          g.add(idv, ido, dist(v, o) * 2);
          break;
        }
      }
      g.add(N, ido, dist(o, s));
      break;
    }
  }
  g.build();
  setp(9);
  RE ans = dijkstra<RE>(g, N).fi[N + 1];
  print(ans > inf<int> ? dist(s, t) : ans);
}
#include "YRS/Z_H/main.hpp"