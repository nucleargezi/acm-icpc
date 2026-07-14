#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam_ex.hpp"

void Yorisou() {
  STR(s);
  int N = si(s);
  for (char &c : s) c -= 'A';
  sam_ex<27> ss;
  vc<int> pr(si(s) << 2, inf<int>), su(pr);
  int p = 0;
  FOR(i, N) {
    p = ss.add(p, s[i]);
    pr[p] = i;
  }
  p = 0;
  FOR(i, N) {
    p = ss.add(p, s[N - i - 1]);
    su[p] = i;
  }
  Z g = ss.build_dir_g();
  Z f = [&](Z &f, int n) -> void {
    for (int x : g[n]) {
      f(f, x);
      chmin(pr[n], pr[x]);
      chmin(su[n], su[x]);
    }
  };
  f(f, 0);

  int ans = 0;
  INT(Q);
  FOR(Q) {
    STR(s);
    int n = si(s);
    if (n < 2) continue;
    for (char &c : s) c -= 'A';
    vc<int> ls(n, -1), rs(n, -1);
    int p = 0;
    FOR(i, n) {
      int x = s[i];
      p = ss[p][x];
      if (p == -1) break;
      ls[i] = p;
    }
    p = 0;
    FOR_R(i, n) {
      int x = s[i];
      p = ss[p][x];
      if (p == -1) break;
      rs[i] = p;
    }
    FOR(i, n - 1) if (ls[i] != -1 and rs[i + 1] != -1) {
      int l = pr[ls[i]], r = su[rs[i + 1]];
      if (l == inf<int> or r == inf<int>) continue;
      r = N - 1 - r;
      if (l < r) {
        ++ans;
        break;
      }
    }
  }
  print(ans);
}

int main() {
  Yorisou();
  return 0;
}