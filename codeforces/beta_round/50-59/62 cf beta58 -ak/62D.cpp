#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/graph/Apck/Basic.hpp"
#include "YRS/graph/Apck/euler_walk.hpp"

// #define tests
void Yorisou() {
  INT(N, M);
  VEC(int, a, M + 1);
  for (int &x : a) --x;
  vector<PII> e;
  FOR(i, M) {
    int x = a[i], y = a[i + 1];
    if (x > y) swap(x, y);
    e.emplace_back(x, y);
  }
  FOR_R(i, M) {
    FOR(st, a[i] + 1, N) {
      graph g(N + 1);
      map<PII, int> es;
      FOR(k, std::max(0, i - 1), M) {
        Z [x, y] = e[k];
        ++es[{x, y}];
      }
      if (i) {
        int x = a[i - 1], y = st;
        if (x > y) swap(x, y);
        if (es.contains({x, y})) --es[{x, y}];
        else continue;
      }
      for (Z [e, c] : es) {
        while (c--) g.add(e.first, e.second);
      }
      g.add(N, st);
      g.add(a[M], N);
      g.build();
      vector vs = euler_walk(g, N).first;
      if (vs.empty()) continue;
      if (vs[1] != st) reverse(vs);
      pop(vs);
      vs.erase(vs.begin());
      if (vs.empty()) continue;
      a.resize(i);
      a.insert(a.end(), all(vs));
      for (int &x : a) ++x;
      return UL(a);
    }
  }
  UL("No solution");
}
#include "YRS/Z_H/main.hpp"