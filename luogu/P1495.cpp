#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/crt.hpp"

void Yorisou() {
  INT(N);
  vc<ll> a(N), p(N);
  FOR(i, N) IN(p[i], a[i]);
  print(crt(a, p));
}

int main() {
  Yorisou();
  return 0;
}