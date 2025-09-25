#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N, K, T);
  T = N * K * T / 100;
  vector<int> ans;
  FOR(i, N) {
    int d = std::min(K, T);
    T -= d;
    ans.ep(d);
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"