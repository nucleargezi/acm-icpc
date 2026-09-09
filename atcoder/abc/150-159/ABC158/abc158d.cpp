#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  deque<char> q;
  STR(s);
  for (char c : s) q.ep(c);
  bool f = 0;

  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) f ^= 1;
    else {
      INT(op);
      CH(c);
      if (f ^ (op - 1)) q.ep(c);
      else q.emplace_front(c);
    }
  }
  s.clear();
  for (char c : q) s += c;
  if (f) reverse(s);
  print(s);
}

int main() { Yorisou(); }