#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  INT(n, q);
  int l = -1, r = n;
  while (q--) {
    VEC(string, s, 5);
    int x = std::stoll(s[4]) - 1;
    if (s[2] == "left") chmin(r, x);
    else chmax(l, x);
  }
  UL(r - l > 1 ? r - l - 1 : -1);
}
#include "YRS/Z_H/main.hpp"