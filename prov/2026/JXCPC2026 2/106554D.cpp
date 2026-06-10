#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> s;
  FOR(d, 1, N) {
    FOR(i, d) {
      vc<int> v{1, N};
      FOR(k, i, N, d) v.ep(k + 1);
      unique(v);
      s.ep(v);
    }
  }
  unique(s);
  print(si(s));
  for (var a : s) print(a);
}

int main() {
  Yorisou();
  return 0;
}