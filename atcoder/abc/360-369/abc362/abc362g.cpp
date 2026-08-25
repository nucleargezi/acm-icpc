#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"

void Yorisou() {
  STR(s);
  for (char &c : s) c -= 'a';
  sam ss(si(s));
  Z sz = ss.slv(s).fi;

  INT(Q);
  FOR(Q) {
    STR(s);
    for (char &c : s) c -= 'a';
    print(ss.count(s, sz));
  }
}

int main() { Yorisou(); }