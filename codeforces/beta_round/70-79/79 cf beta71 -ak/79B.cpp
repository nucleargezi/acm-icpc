#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M, k, Q);
  vector<ll> g;
  FOR(k) {
    INT(x, y);
    --x, --y;
    g.ep(x * M + y);
  }
  sort(g);
  FOR(Q) {
    INT(x, y);
    --x, --y;
    ll t = x * M + y;
    if (std::binary_search(all(g), t)) {
      print("Waste");
    } else {
      ll a = (t - lower_bound(g, t)) % 3;
      print(a == 0 ? "Carrots" : a == 1 ? "Kiwis" : "Grapes");
    }
  }
}
#include "YRS/Z_H/main.hpp"