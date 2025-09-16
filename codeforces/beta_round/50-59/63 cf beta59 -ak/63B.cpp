#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  vector<int> na(a);
  int ans = 0;
  while (a != vector<int>(N, K)) {
    std::copy(all(a), na.begin());
    FOR_R(i, N) {
      if (i == N - 1 and a[i] < K) ++na[i];
      else if (a[i] != a[i + 1] and a[i] < K) ++na[i];
    }
    swap(a, na);
    ++ans;
  }
  UL(ans);
}
#include "YRS/Z_H/main.hpp"