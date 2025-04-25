#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/file_io.hpp"

void before() {
#ifdef ONLINE_JUDGE
  FR("input.txt");
  FW("output.txt");
#endif
}

// #define tests
using block = vector<string>;
void Yorisou() {
  LL(N, k);
  VEC(string, a, N);
  block black(N, string(N, '*')), org = a;
  ll n = N;
  FOR(k - 1) {
    block go[n][n];
    FOR(i, n) FOR(k, n) {
      go[i][k] = a[i][k] == '*' ? black : org;
    }
    a.assign(n * N, "");
    FOR(i, n) FOR(k, n) {
      FOR(j, N) {
        a[i * N + j] += go[i][k][j];
      }
    }
    n *= N;
  }
  FOR(i, n) UL(a[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"