#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/wildcard_match_ntt.hpp"

void Yorisou() {
  STR(s, t);
  Z a = wildcard_match_ntt(s, t);
  for (int &x : a) ++x;
  print(a);
}

int main() {
  Yorisou();
  return 0;
}