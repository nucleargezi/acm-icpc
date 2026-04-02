#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  STR(s);
  for (char &c : s) c -= '0';
  reverse(s);
  ll ans = 0;
  for (ll sc = 0, c = 0, pr = 1; int x : s) {
    if (x) {
      if (pr) sc += c << 1;
      else sc += c;
    } else {
      if (pr) sc += c;
      else sc += c << 1;
    }
    ++sc;
    ans += sc;
    ++c;
    if (not x) ans += c;
    pr = x;
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"