#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(PII, a, N);
  sort(a);
  vc<PII> s;
  for (var [l, r] : a) {
    if (s.empty() or s.back().se < l) s.ep(l, r);
    else chmax(s.back().se, r);
  }
  for (var [l, r] : s) print(l, r);
}

int main() {
  Yorisou();
  return 0;
}