#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"

using mint = M11;
void Yorisou() {
  INT(N, M);
  string str;
  vc<set<int>> se(M);
  FOR(N) {
    IN(str);
    FOR(i, M) se[i].eb(str[i]);
  }
  mint s = 1;
  FOR(i, M) s *= si(se[i]);
  print(s);
}

int main() {
  Yorisou();
  return 0;
}