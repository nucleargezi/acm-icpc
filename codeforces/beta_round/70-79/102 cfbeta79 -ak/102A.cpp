#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/enum_c3.hpp"

void Yorisou() {
  INT(N, M);
  VEC(int, a, N);
  VEC(PII, es, M);
  for (Z &[a, b] : es) --a, --b;
  int rs = inf<int>;
  enum_c3(N, es, [&](int i, int k, int j) { chmin(rs, a[i] + a[k] + a[j]); });
  print(rs == inf<int> ? -1 : rs);
}

int main() {
  Yorisou();
  return 0;
}