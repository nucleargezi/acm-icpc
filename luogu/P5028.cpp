#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/string/SA/string_cmp.hpp"
#include "YRS/ds/basic/retsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  string s;
  vc<int> c;
  FOR(i, N) {
    STR(str);
    s += str;
    s += 'z' + i + 1;
    FOR(len(str)) c.ep(i);
    c.ep(-1);
  }
  s += char('z' + 20);
  c.ep(-1);
  SA sa(s);
  retsu<int> re(N, N);
  int sz = len(s);
  vc<int> f(N);
  FOR(i, 1, sz) {
    int w = sa.sa[i], x = c[w];
    if (x == -1) continue;
    FOR(k, N) {
      chmin(f[k], sa.lcp[i - 1]);
      if (k != x) {
        chmax(re[k][x], f[k]);
        chmax(re[x][k], f[k]);
      }
    }
    f[x] = inf<int>;
  }
  FOR(i, N) {
    vc<int> o;
    FOR(k, N) if (i != k) o.ep(re[i][k]);
    print(o);
  }
}
#include "YRS/aa/main.hpp"