#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  SV(s, '0');
  int n = len(s);
  vector<int> st;
  PII go = {-1, -1};
  FOR(i, n) {
    FOR(k, i ? 0 : 1, s[i]) {
      bool f = 0;
      if (not st.empty() and st.back() == k) {
        pop(st);
        f = 1;
      } else {
        st += k;
      }
      if (n - i - 1 >= len(st) and ((n - i - 1 - len(st)) & 1) == 0) {
        go = {i, k};
      }
      if (f) st += k;
      else pop(st);
    }
    if (not st.empty() and st.back() == s[i]) {
      pop(st);
    } else {
      st += s[i];
    }
  }
  string ans;
  if (st.empty()) {
    FOR(i, n) ans += s[i];
  } else if (go == PII{-1, -1}) {
    n = n - 2 + (n & 1);
    FOR(i, n) ans += 9;
  } else {
    st.clear();
    meion [a, b] = go;
    FOR(i, a) {
      ans += s[i];
      if (not st.empty() and st.back() == s[i]) {
        pop(st);
      } else {
        st += s[i];
      }
    }
    ans += b;
    if (not st.empty() and st.back() == b) {
      pop(st);
    } else {
      st += b;
    }
    FOR(i, n - len(st) - a - 1) ans += 9;
    for (int x : std::views::reverse(st)) ans += x;
  }
  FOR(i, len(ans)) ans[i] += '0';
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"