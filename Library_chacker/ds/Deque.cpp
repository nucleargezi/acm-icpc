#include "YRS/Z_H/MeioN.hpp"
#include "YRS/MeIoN_all.hpp"
#include "YRS/ds/basic/deque.hpp"

// #define tests
void Yorisou() {
  fast_deque<int> q;
  INT(Q);
  while (Q--) {
    INT(op);
    if (op == 0) {
      INT(x);
      q.emplace_front(x);
    } else if (op == 1) {
      INT(x);
      q.emplace_back(x);
    } else if (op == 2) {
      q.pop_front();
    } else if (op == 3) {
      q.pop_back();
    } else {
      INT(x);
      UL(q[x]);
    }
  }
}
#include "YRS/Z_H/main.hpp"