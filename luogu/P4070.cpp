#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam_map.hpp"

void Yorisou() {
  INT(N);
  sam_map ss(N);
  int x = 0;
  ll rs = 0;
  FOR(N) {
    INT(c);
    x = ss.add(x, c);
    rs += ss[x].sz - ss[ss[x].fa].sz;
    print(rs);
  }
}

int main() {
  Yorisou();
  return 0;
}