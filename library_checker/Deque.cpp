#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/deque.hpp"

void Yorisou() {
  INT(Q);
  deque<int> q(Q);
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
      print(q[x]);
    }
  }
}
int main() { Yorisou(); }