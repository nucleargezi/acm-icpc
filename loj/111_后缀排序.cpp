#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/SA/SA.hpp"

void Yorisou() {
  STR(s);
  SA sa(s);
  vc<int> rs = sa.sa;
  for (int &x : rs) ++x;
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}