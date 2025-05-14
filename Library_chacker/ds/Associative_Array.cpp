#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/hashmap.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(q);
  hash_map<ull> m;
  FOR(q) {
    LL(op);
    if (op == 0) {
      LL(x, v);
      m[x] = v;
    } else {
      LL(x);
      UL(m.get(x, 0));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"