#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/string/wildcard_match_fft.hpp"

// #define tests
void Yorisou() {
  STR(s, t);
  string ans(len(s) - len(t) + 1, '0');
  for (int x : wildcard_match_fft(t, s, 'a')) {
    ++ans[x];
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"