#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/graph/Tree/centroid_dec.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  graph<ll> g(n);
  g.read_tree<1>();
  vector<u8> ans(q);
  VEC(int, quis, q);
  meion f = [&](vector<int> &fa, vector<int> &v, int l1, int r1, int l2,
                int r2) -> void {
    ll N = len(fa);
    vector<ll> dis(N);
    FOR(i, 1, N) {
      dis[i] = dis[fa[i]] + g.edges[g.get_eid(v[i], v[fa[i]])].cost;
    }
    hash_map<u8> in;
    FOR(i, l1, r1) {
      in[dis[i]] = 1;
      FOR(k, q) if (not ans[k]) {
        if (dis[i] == quis[k]) ans[k] = 1;
      }
    }
    FOR(i, l2, r2) {
      FOR(k, q) if (not ans[k]) {
        if (in.contains(quis[k] - dis[i])) ans[k] = 1;
      }
    }
  };
  centroid_decomposition<1>(g, f);
  FOR(i, q) Yes(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"