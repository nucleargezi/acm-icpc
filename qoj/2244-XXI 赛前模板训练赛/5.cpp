#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/string/SAM_EX.hpp"

// #define tests
void Yorisou() {
  LL(n);
  SAM sam;
  FOR(i, n) {
    S(s);
    for (int p = 0; char c : s) {
      p = sam.ext(p, c - 'a');
    }
  }
  ll ans = 0;
  FOR(i, 1, len(sam)) {
    ans += sam[i].len - sam[sam[i].link].len;
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"