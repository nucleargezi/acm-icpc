#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/string/pam_deque2.hpp"

// #define tests
void Yorisou() {
  INT(Q);
  pam_deque seg(Q);
  FOR(Q) {
    INT(op);
    if (op == 0) {
      CH(c);
      seg.push_front(c);
    } else if (op == 1) {
      CH(c);
      seg.push_back(c);
    } else if (op == 2) {
      seg.pop_front();
    } else {
      seg.pop_back();
    }
    print(seg.keis(), seg.max_pre_pal(), seg.max_suf_pal());
  }
}
#include "YRS/Z_H/main.hpp"