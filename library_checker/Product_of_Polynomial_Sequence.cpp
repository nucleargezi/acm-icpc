#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/conv_all.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  vc<fps> f(N);
  FOR(i, N) {
    INT(n);
    f[i].resize(n + 1);
    IN(f[i]);
  }
  print(conv_all(f));
}

int main() {
  Yorisou();
  return 0;
}