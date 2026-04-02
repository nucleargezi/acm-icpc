#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  S(s);
  vector<int> t(n, -1), st;
  FOR(i, n) {
    if (s[i] == '(') {
      st += i;
    } else if (s[i] == ')') {
      t[st.back()] = i;
      st.pop_back();
    }
  }
  vector<int> ans;
  meion f = [&](meion &f, int l, int r) -> void {
    FOR(i, l, r) {
      if (s[i] == '(') {
        f(f, i + 1, t[i] + 1);
        ans += i + 1;
        i = t[i];
      } else {
        ans += i + 1;
      }
    }
  };
  f(f, 0, n);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"