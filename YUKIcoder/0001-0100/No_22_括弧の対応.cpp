#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, K);
  STR(s);
  vc<int> st, re(N);
  FOR(i, N) {
    if (s[i] == '(') {
      st.ep(i);
    } else {
      int f = pop(st);
      re[f] = i;
      re[i] = f;
    }
  }
  print(re[K - 1] + 1);
}
#include "YRS/aa/main.hpp"