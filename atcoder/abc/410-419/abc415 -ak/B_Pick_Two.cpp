#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
void Yorisou() {
  S(s);
  vector<int> ans;
  FOR(i, len(s)) {
    if (s[i] == '#') ans += i + 1;
  }
  FOR(i, 0, len(ans), 2) std::cout << ans[i] << "," << ans[i + 1] << '\n';
}
#include "MeIoN_Lib/Z_H/main.hpp"