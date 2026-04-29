#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/deque.hpp"

void Yorisou() {
  map<int, deque<int>> q;
  INT(Q);
  FOR(Q) {
    STR(op);
    if (op == "push_back") {
      INT(i, x);
      q[i].ep(x);
    } else if (op == "pop_back") {
      INT(i);
      if (not q[i].empty()) q[i].pop_back();
    } else if (op == "push_front") {
      INT(i, x);
      q[i].emplace_front(x);
    } else if (op == "pop_front") {
      INT(i);
      if (not q[i].empty()) q[i].pop_front();
    } else if (op == "size") {
      INT(i);
      print(si(q[i]));
    } else if (op == "front") {
      INT(i);
      if (not q[i].empty()) print(q[i].front());
    } else {
      INT(i);
      if (not q[i].empty()) print(q[i].back());
    }
  }
}

int main() {
  Yorisou();
  return 0;
}