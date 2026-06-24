#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"
#include "YRS/ds/seg/segd_t.hpp"
#include "YRS/al/m/max.hpp"

using MX = Max<int>;
using DS = segd_t<MX, 1>;
using np = DS::np;
void Yorisou() {
  STR(s);
  for (char &c : s) c -= 'a';
  sam ss(si(s));
  vc<int> sz = ss.build(s), en = std::move(ss.en);
  vc<vc<int>> g = ss.build_dir_g();
  int N = si(g), tt = 0;
  vc<int> L(N), R(N);
  Z f = [&](Z &f, int n) -> void {
    L[n] = tt++;
    for (int x : g[n]) f(f, x);
    R[n] = tt;
  };
  f(f, 0);
  
  DS seg(0, N);
  vc<np> t(N + 1);
  FOR(i, N) t[i + 1] = seg.set(t[i], L[en[i]], i + 1);

  INT(Q);
  FOR(Q) {
    STR(s);
    for (char &c : s) c -= 'a';
    INT(l, r);
    --l;
    sam tt(si(s));
    ll rs = 0;
    for (int x = 0, sz = 0, p = 0; int c : s) {
      while (x and ss[x][c] == -1) sz = ss[x = ss[x].fa].sz;
      if (ss[x][c] != -1) x = ss[x][c], ++sz;
      for (; x; sz = ss[x = ss[x].fa].sz) {
        int e = seg.prod(t[r], L[x], R[x]);
        if (e - ss[ss[x].fa].sz > l) {
          chmin(sz, e - l);
          break;
        }
      }
      p = tt.add(p, c);
      rs += max(0, tt[p].sz - max(tt[tt[p].fa].sz, sz));
    }
    print(rs);
  }
}

int main() {
  Yorisou();
  return 0;
}