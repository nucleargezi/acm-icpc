#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  INT(N, M, K);
  RET(char, a, N, M);
  FOR(i, N) FOR(k, M) a[i][k] -= '0';
 
  int rs = N + M - 2, id[10]{};
  retsu<int> c(N, M);
  vc<int> buf(M);

  FOR(s, 1 << (N - 1)) {
    int n = 0;
    FOR(i, N) {
      id[i] = n;
      FOR(k, M) buf[k] += a[i][k];
      if ((s >> i & 1) or i == N - 1) {
        FOR(k, M) c[n][k] = buf[k], buf[k] = 0;
        ++n;
      }
    }
    bool ok = 1;
    FOR(i, n) FOR(k, M) if (c[i][k] > K) ok = 0;
    if (not ok) continue;
    
    int w = n - 1, f[10]{};
    FOR(k, M) {
      bool o = 0;
      FOR(i, n) if ((f[i] += c[i][k]) > K) o = 1;
      if (o) {
        ++w;
        FOR(i, n) f[i] = 0;
        FOR(i, n) f[i] += c[i][k];
      }
    }
    chmin(rs, w);
  }
  print(rs);
}

int main() { Yorisou(); }