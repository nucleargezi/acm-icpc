#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam_ex.hpp"
#include "YRS/ttr/hld.hpp"

void Yorisou() {
  STR(A, B);
  for (char &c : A) c -= 'A';
  for (char &c : B) c -= 'A';
  reverse(A);
  reverse(B);
  sam_ex ss((si(B) + si(A)) * 2);
  vc<int> en;
  for (int x = 0; int c : B) x = ss.add(x, c), en.ep(x);
  vc<int> ls((si(B) + si(A)) * 2, inf<int> / 2);
  for (int x = 0, i = si(A); int c : A) x = ss.add(x, c), ls[x] = --i;

  vc<vc<int>> g(ss.build_dir_g());
  Z f = [&](Z &f, int n) -> void {
    for (int x : g[n]) f(f, x), chmin(ls[n], ls[x]);
  };
  f(f, 0);
  hld v(g, 0);

  INT(Q);
  vc<int> rs(Q);
  FOR(i, Q) {
    INT(pr, su);
    int x = en[su - 1];
    if (ls[x] + ss[x].sz <= pr) {
      rs[i] = ss[x].sz;
    } else {
      int t = v.max_hi(x, [&](int x) { return ls[x] + ss[x].sz > pr; });
      rs[i] = max(ss[v.fa[t]].sz, pr - ls[t]);
    }
  }
  print(rs);
}

int main() {
  INT(T);
  FOR(i, T) {
    put("Case #", i + 1, ": ");
    Yorisou();
  }
  return 0;
}