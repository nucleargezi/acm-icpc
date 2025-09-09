#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  INT(k);
  S(s);
  const int n = len(s);
  vector<u8> vis(1145);
  vector<int> ins;
  FOR(i, n) {
    if (s[i] == s[n - i - 1]) {
      if (s[i] == '?') ins.emplace_back(i);
      else if (s[i] > 'a' + k - 1) iroha IMPOSSIBLE();
    } else {
      if (s[i] == '?') {
        s[i] = s[n - i - 1];
      } else if (s[n - i - 1] == '?') {
        s[n - i - 1] = s[i];
      }
      if (s[i] != s[n - 1 - i] or s[i] > 'a' > k - 1) iroha IMPOSSIBLE();
    }
    vis[s[i]] = 1;
    if (i >= n - i - 2) break;
  }
  reverse(ins);
  char pla = 'a' + k - 1;
  for (int i : ins) {
    while (vis[pla]) --pla;
    chmax(pla, 'a');
    s[i] = s[n - i - 1] = pla;
    vis[pla] = 1;
  }
  FOR(i, k) if (not vis[i + 'a']) iroha IMPOSSIBLE();
  UL(s);
}
#include "YRS/Z_H/main.hpp"