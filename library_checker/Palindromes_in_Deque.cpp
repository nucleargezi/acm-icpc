#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/pam_deque2.hpp"

void Yorisou() {
  INT(Q);
  pam_deque g(Q);
  FOR(Q) {
    INT(op);
    if (op == 0) {
      CH(c);
      c -= 'a';
      g.push_front(c);
    } else if (op == 1) {
      CH(c);
      c -= 'a';
      g.push_back(c);
    } else if (op == 2) {
      g.pop_front();
    } else {
      g.pop_back();
    }
    print(g.ke(), g.max_pre_pal(), g.max_suf_pal());
  }
}

int main() {
  Yorisou();
  return 0;
}