#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/trie01.hpp"
#include "MeIoN_Lib/ds/hashmap.hpp"

// #define tests
using TR = trie01<30, false, 2'000'000, uint>;
void Yorisou() {
  TR tr;
  meion rt = tr.new_root();
  LL(q);
  hash_map<int> mp;
  FOR(q) {
    LL(op, x);
    if (op == 0) {
      if (mp[x]) continue;
      mp[x] = 1;
      rt = tr.add(rt, x, 1);
    } else if (op == 1) {
      if (not mp.contains(x) or mp[x] == 0) continue;
      mp[x] = 0;
      rt = tr.add(rt, x, -1);
    } else {
      UL(tr.min(rt, x));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"