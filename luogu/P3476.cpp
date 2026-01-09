#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ge/basic/angle_sort.hpp"
#include "YRS/ds/basic/queue.hpp"

#define tests 0
#define fl 0
#define DB 10
using P = point<ll>;
void Yorisou() {
  INT(N);
  VEC(P, a, N);
  ll ar = 0;
  FOR(i, N) {
    vc<P> s;
    FOR(k, i + 1, N) s.ep(a[i] - a[k]);
    s = rearrange(s, angle_sort(s));
    P al;
    int k = 0, sz = len(s);
    s.insert(s.end(), all(s));
    queue<int> q;
    FOR(i, sz) {
      while (k < i + sz) {
        ll de = s[i].det(s[k]);
        if (de > 0) {
          al += s[k];
          q.eb(k);
          ++k;
        } else if (de == 0 and s[i].dot(s[k]) > 0) {
          ++k;
        } else {
          break;
        }
      }
      while (not q.empty() and q.front() <= i) al -= s[q.pop()];
      ar += s[i].det(al);
    }
  }
  setp(1);
  print(ar * 0.5l);
}
#include "YRS/aa/main.hpp"