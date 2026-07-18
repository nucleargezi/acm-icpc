#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/SA/SA.hpp"

void Yorisou() {
  STR(s);
  SA sa(s);
  for (int &x : sa.sa) ++x;
  print(sa.sa);
}

int main() {
  Yorisou();
  return 0;
}