#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  SV(s, '0');
  const int n = len(s);
  vector<PII> ans;
  vector<int> L(n);
  vector<int> st;
  vector<vector<int>> go(n + 1);
  FOR(i, n) {
    if (st.empty() or s[st.back()] == s[i]) {
      st += i;
    } else {
      int x = pop(st);
      L[x] = i;
      L[i] = x;
      if (st.empty()) go[n] += i;
      else go[st.back()] += i;
    }
  }
  if (not st.empty()) iroha UL(-1);
  int sc = 1;
  meion f = [&](meion &f, int y) -> void {
    int x = L[y];
    ans += PII(sc, s[x] + 1);
    for (int v : go[x]) {
      f(f, v);
    }
    ++sc;
  };
  for (int l : go[n]) f(f, l);
  UL(len(ans));
  FOR(i, len(ans)) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"