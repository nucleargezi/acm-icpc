#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
using re = ld;
void Yorisou() {
  INT(N, K);
  vc<re> a(N * 6 + 1), b(a);
  a[0] = b[0] = 1;
  FOR(N) {
    vc<re> na(6 * N + 1);
    FOR(k, 1, 7) {
      FOR(i, 6 * N + 1 - k) na[i + k] += a[i] / 6.l;
    }
    a.swap(na);
  }
  FOR(N - K) {
    vc<re> nb(6 * N + 1);
    FOR(k, 1, 7) {
      FOR(i, 6 * N + 1 - k) nb[i + k] += b[i] / 6.l;
    }
    b.swap(nb);
  }
  FOR(K) {
    vc<re> nb(6 * N + 1);
    FOR(k, 4, 7) {
      FOR(i, 6 * N + 1 - k) nb[i + k] += b[i] / 3.l;
    }
    b.swap(nb);
  }
  FOR(i, 6 * N) a[i + 1] += a[i];
  ld s = 0;
  FOR(i, 6 * N) s += a[i] * b[i + 1];
  setp(5);
  print(s);
}
#include "YRS/aa/main.hpp"