#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M, X);
  int a[12][12], c[12], d[12];
  FOR(i, N) {
    IN(c[i]);
    FOR(k, M) IN(a[i][k]);
  }
  int rs = inf<int>;
  FOR(s, 1 << N) {
    fill_n(d, M, 0);
    int ss = 0;
    FOR(i, N) if (s >> i & 1) {
      ss += c[i];
      FOR(k, M) d[k] += a[i][k];
    }
    FOR(i, M) if (d[i] < X) ss = inf<int>;
    chmin(rs, ss);
  }
  print(rs == inf<int> ? -1 : rs);
}

int main() { Yorisou(); }