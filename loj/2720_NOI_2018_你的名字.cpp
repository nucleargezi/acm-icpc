#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"
#include "YRS/ds/seg/segd.hpp"
#include "YRS/al/m/max.hpp"

using MX = Max<int>;
using DS = segd<MX, 1>;
using np = DS::np;
void Yorisou() {
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
  STR(s);
  for (char &c : s) c -= 'a';
  sam ss(si(s));
  Z sz = ss.build(s), en = move(ss.en);
  Z g = ss.build_dir_g();
  int N = si(g), ti = 0;
  vc<int> L(N), R(N);
  Z f = [&](Z &f, int n) -> void {
    L[n] = ti++;
    for (int x : g[n]) f(f, x);
    R[n] = ti;
  };
  f(f, 0);

  DS seg(0, N);
  vc<np> t(N + 1);
  FOR(i, N) t[i + 1] = seg.set(t[i], L[en[i]], i + 1);

  INT(Q);
  sam tt(si(s));
  FOR(Q) {
    tt.a.clear(), tt.a.ep(), tt.en.clear();
    STR(s);
    for (char &c : s) c -= 'a';
    INT(l, r);
    --l;
    ll rs = 0;
    for (int x = 0, sz = 0, p = 0; int c : s) {
      while (x and ss[x][c] == -1) x = ss[x].fa, sz = ss[x].sz;
      if (ss[x][c] != -1) x = ss[x][c], ++sz;
      while (x) {
        int e = seg.prod(t[r], L[x], R[x]);
        if (e > l + ss[ss[x].fa].sz) {
          chmin(sz, e - l);
          break;
        }
        sz = ss[x = ss[x].fa].sz;
      }
      p = tt.add(p, c);
      rs += max(0, tt[p].sz - max(tt[tt[p].fa].sz, sz));
    }
    print(rs);
  }
}

int main() { Yorisou(); }