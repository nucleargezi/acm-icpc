#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N);
  cin.ignore();
  string s;
  std::getline(cin, s);
  const int sz = len(s);
  int ls = N, ans = 1;
  FOR(i, sz) {
    int sz = 1;
    while (not(s[i] == '!' or s[i] == '?' or s[i] == '.')) ++sz, ++i;
    if (ls == N) ls -= sz;
    else if (ls >= sz) ls -= sz;
    else ls = N - sz + 1, ++ans;
    if (ls < 0) return Impossible();
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"