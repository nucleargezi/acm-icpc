#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N, M, K);
  string s;
  IN(s), IN(s);
  int d = s == "head" ? -1 : 1;
  IN(s);
  const int sz = len(s);
  FOR(i, sz) {
    s[i] -= '0';
    K += d;
    if (not K) d = 1, K = 2;
    else if (K == N + 1) d = -1, K = N - 1;
    if (K == M and (M + d == 0 or M + d == N + 1) and s[i] == 0)
      return print("Controller", ++i);
    if (s[i]) {
      if (K == 1) M = N;
      else if (K == N) M = 1;
      else if (d == 1) M = 1;
      else if (d == -1) M = N;
    } else if (K == M) M += d;
  }
  print("Stowaway");
}
#include "YRS/Z_H/main.hpp"