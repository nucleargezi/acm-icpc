#include "YRS/all.hpp"
#include "YRS/nt/bigint/big.hpp"
#include "YRS/string/hs.hpp"
#include "YRS/ds/basic/hashmap.hpp"
#include "YRS/ds/basic/queue.hpp"

using H = hash_t;
using X = H::X;
ull h(X x) { return x.fi * hsh_pw.b.val() + x.se.val(); }
void Yorisou() {
  using ll = bigint;
  INT(K, N);
  hashmap<u8> mp;
  queue<T3<ll>> q;
  q.eb(1, K, K * K + K);
  while (1) {
    Z [a, b, c] = pop(q);
    if (min({a.op, b.op, c.op}) < 0) break;
    ull ha = h(H::hs(a.a)), hb = h(H::hs(b.a)), hc = h(H::hs(c.a));
    if (not mp.contains(ha) and not mp.contains(hb) and not mp.contains(hc)) {
      print(a, b, c);
      mp[ha], mp[hb], mp[hc];
      if (not --N) break;
    }
    q.eb(b, c, (b + c) * K - a);
    q.eb(a, c, (a + c) * K - b);
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"