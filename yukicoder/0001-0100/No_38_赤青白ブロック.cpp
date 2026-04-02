#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(kr, kb);
  STR(s);
  int N = len(s);
  vc<int> p;
  bool vis[30]{};
  FOR(i, N) {
    if (s[i] != 'W') p.ep(i);
    else vis[i] = 1;
  }
  Z ck = [&](const string &s) -> bool {
    int N = len(s);
    FOR(i, N) {
      if (s[i] == 'R' and i + kr < N and s[i + kr] == 'R') return 0;
      if (s[i] == 'B' and i + kb < N and s[i + kb] == 'B') return 0;
    }
    return 1;
  };
  int ans = 0;
  FOR(msk, 1 << 20) {
    for (int x : p) vis[x] = 0;
    FOR(i, 20) if (msk >> i & 1) vis[p[i]] = 1;
    string go;
    FOR(i, 30) if (vis[i]) go += s[i];
    if (ck(go)) chmax(ans, len(go));
  }
  print(ans);
}
#include "YRS/aa/main.hpp"