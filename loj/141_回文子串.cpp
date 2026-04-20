#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/pam_deque.hpp"

void Yorisou() {
  STR(s);
  for (char &c : s) c -= 'a';
  pam_deque<26> g;
  ll rs = 0;
  for (char c : s) g.pb(c), rs += g.a[g.lb].d;
  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      STR(s);
      for (char &c : s) c -= 'a';
      for (char c : s) g.pb(c), rs += g.a[g.lb].d;
    } else if (op == 2) {
      STR(s);
      for (char &c : s) c -= 'a';
      for (char c : s) g.pf(c), rs += g.a[g.lf].d;
    } else {
      print(rs);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}