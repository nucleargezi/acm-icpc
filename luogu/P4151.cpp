#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/line/01/xor_vector_space.hpp"
#include "YRS/graph/Apck/Basic.hpp"

// #define tests
void Yorisou() {
  INT(N, M);
  graph<ll> g(N);
  g.read_graph<1>(M);
  vector_space<ll> seg;
  vector<ll> dis(N);
  vector<u8> vis(N);
  Z f = [&](Z &f, int n, int fa) -> void {
    vis[n] = 1;
    for (Z &&e : g[n]) if (fa != e.to) {
      if (vis[e.to]) {
        seg.add(e.cost ^ dis[n] ^ dis[e.to]);
      } else {
        dis[e.to] = dis[n] ^ e.cost;
        f(f, e.to, n);
      }
    }
  };
  f(f, 0, -1);
  print(seg.get_max(dis[N - 1]));
}
#include "YRS/Z_H/main.hpp"