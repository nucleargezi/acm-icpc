#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  INT(N);
  STR(s);
  vector<int> I;
  FOR(i, N - 1) if (s[i] != s[i + 1]) I.ep(i);
  const int M = len(I);
  vector<int> d(M + 1);
  FOR(i, 1, N + 1) {
    int l = 0, r = 0;
    while (l + i < M + 1) {
      ++d[l + i];
      if (r + i + 1 < M + 1) --d[r + i + 1];
      l += i + 1, r += i + 1;
      if (I[l - 1] - I[l - 2] > 1) --l;
    }
  }
  FOR(i, 1, M + 1) d[i] += d[i - 1];
  vector<int> ans;
  for (int k = 0, i = 0; i < N; ++i) {
    if (i and s[i] != s[i - 1]) ++k;
    ans.ep(d[k] + i + 1 - k);
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"