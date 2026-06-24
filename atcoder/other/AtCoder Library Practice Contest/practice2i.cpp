#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"

void Yorisou() {
  STR(s);
  for (char &c : s) c -= 'a';
  sam ss(si(s));
  ss.build(s);
  print(ss.count());
}

int main() {
  Yorisou();
  return 0;
}