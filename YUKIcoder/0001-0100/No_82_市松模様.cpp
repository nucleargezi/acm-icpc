#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(M, N);
  CH(c);
  vc<string> s(N, string(M, 0));
  FOR(i, N) FOR(k, M) {
    if (i + 1 < N) s[i + 1][k] = s[i][k] ^ 1;
    if (k + 1 < M) s[i][k + 1] = s[i][k] ^ 1;
  }
  FOR(i, N) FOR(k, M) s[i][k] = s[i][k] ? c ^ 'B' ^ 'W' : c;
  FOR(i, N) print(s[i]);
}
#include "YRS/aa/main.hpp"