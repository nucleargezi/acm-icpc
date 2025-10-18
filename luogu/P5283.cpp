#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/trie01.hpp"

void before() {}

// #define tests
using trie = trie01<33, 1, 5'00'000 * 33>;
using np = trie::np;
void Yorisou() {
  LL(n, K);
  VEC(ull, a, n);
  vector<ull> c(n + 1);
  FOR(i, n) c[i + 1] = c[i] ^ a[i];
  trie tr;
  vector<np> rt(n + 1);
  rt[0] = tr.new_root();
  FOR(i, n + 1) {
    rt[i] = tr.add(rt[i ? i - 1 : 0], c[i]);
  }
  priority_queue<tuple<ull, int, int>> q;
  FOR(i, n) {
    q.emplace(tr.max(rt[i], c[i + 1]), i, rt[i]->cnt - 1);
  }
  ull ans = 0;
  while (K--) {
    meion [val, i, rk] = pop(q);
    ans += val;
    if (not rk) continue;
    --rk;
    q.emplace(tr.kth(rt[i], rk, c[i + 1]), i, rk);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"