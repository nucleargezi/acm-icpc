#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/SA/SA.hpp"

void Yorisou() {
  STR(s);
  SA sa(s);
  sa.lcp.insert(bg(sa.lcp), 0);
  print(sa.sa);
  print(sa.lcp);
}

int main() { Yorisou(); }