#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/heap/minmax_heap.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  minmax_heap<int> heap;
  FOR(i, n) {
    INT(x);
    heap.emplace(x);
  }
  FOR(q) {
    LL(op);
    if (op == 0) {
      INT(x);
      heap.emplace(x);
    } else if (op == 1) {
      UL(heap.pop_min());
    } else {
      UL(heap.pop_max());
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"