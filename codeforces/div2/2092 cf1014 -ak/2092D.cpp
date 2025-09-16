#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  INT(N);
  STR(s);
  for (char &c : s) {
    c = c == 'T' ? 0 : c == 'I' ? 1 : 2;
  }
  vector<int> c(3);
  for (int x : s) ++c[x];
  if (QMAX(s) == QMIN(s)) return print(-1);
  vector<int> ans;
  vector I = argsort(c);
  for (int x : {1, 2}) {
    int d = c[I[x]] - c[I[x - 1]];
    if (d) {
      FOR(i, N) if (s[i] == I[x]) {
        if (i and s[i - 1] != s[i]) {
          FOR(k, d << 1) ans.emplace_back(i - 1 + k);
          c[I[x]] = c[I[x - 1]];
          int t = 3 - s[i] - s[i - 1];
          string ad;
          FOR(d) ad += t, ad += s[i - 1];
          s.insert(i, ad);
          break;
        } else if (i + 1 < N and s[i] != s[i + 1]) {
          FOR(k, d << 1) ans.emplace_back(i);
          c[I[x]] = c[I[x - 1]];
          int t = 3 - s[i] - s[i + 1];
          string ad;
          FOR(d) ad += s[i + 1], ad += t;
          s.insert(i + 1, ad);
          break;
        }
      }
    }
  }
  print(len(ans));
  for (int x : ans) print(++x);
}
#include "YRS/Z_H/main.hpp"