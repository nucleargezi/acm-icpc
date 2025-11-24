#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  STR(s);
  int N = len(s);
  if (N & 1) {
    string r;
    ++N;
    FOR(i, N / 2) r += '4';
    FOR(i, N / 2) r += '7';
    return print(r);
  }
  vc<int> c(10);
  FOR(i, N) ++c[s[i] - '0'];
  if (c[4] == c[7] and c[4] + c[7] == N) return print(s);
  FOR(i, N) s[i] -= '0';
  FOR_R(i, N) {
    --c[s[i]];
    if (c[4] + c[7] != SUM(c)) continue;
    for (int x : {4, 7}) {
      if (x <= s[i]) continue;
      ll a = c[4], b = c[7];
      if (x == 4) ++a;
      if (x == 7) ++b;
      ll aa = N / 2 - a, bb = N / 2 - b;
      if (aa > -1 and bb > -1) {
        string r = s.substr(0, i);
        FOR(x, i) r[x] += '0';
        r += to_s(x);
        FOR(aa) r += '4';
        FOR(bb) r += '7';
        return print(r);
      }
    }
  }
  print(string(N / 2 + 1, '4') + string(N / 2 + 1, '7'));
}
#include "YRS/Z_H/main.hpp"