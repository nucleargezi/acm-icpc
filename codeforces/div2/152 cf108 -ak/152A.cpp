#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  VEC(string, a, N);
  vc<int> s;
  FOR(k, M) {
    int mx = 0;
    FOR(i, N) chmax(mx, a[i][k]);
    FOR(i, N) if (a[i][k] == mx) s.ep(i);
  }
  unique(s);
  print(si(s));
}

int main() {
  Yorisou();
  return 0;
}