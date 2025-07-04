#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

// #define tests
using mint = M17;
void Yorisou() {
  int n, m;
  while (IN(n, m)) {
    vector<mint> a(n), b(n);
    FOR(i, n) IN(a[i], b[i]);
    graph<int, 1> g(n);
    g.read_graph(m);
    vector in = g.deg_array_inout().first;
    queue<int> q;
    FOR(i, n) if (not in[i]) q.emplace_back(i);
    mint ans;
    FOR(i, n) ans -= a[i] * b[i];
    while (not q.empty()) {
      meion n = q.pop();
      ans += a[n] * b[n];
      for (meion &&e : g[n]) {
        a[e.to] += a[n];
        if (not --in[e.to]) {
          q.emplace_back(e.to);
        }
      }
    }
    UL(ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"