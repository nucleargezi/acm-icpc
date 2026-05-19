#include "YRS/all.hpp"

void Yorisou() {
  string s = "0000000000";
  FOR(i, 10) {
    vc<int> a(10);
    for (char c = '0'; c <= '9'; ++c) {
      s[i] = c;
      print(s);
      INT(x);
      STR(str);
      a[c - '0'] = x;
      if (x == 10) return;
    }
    int mx = QMAX(a);
    FOR(k, 10) if (a[k] == mx) s[i] = '0' + k;
  }
}

int main() {
  Yorisou();
  return 0;
}