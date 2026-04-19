#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/pam_deque.hpp"
#include "YRS/ds/un/dsu.hpp"

void Yorisou() {
  INT(N);
  STR(s);
  FOR(i, N) s[i] -= '0';
  dsu g(N);
  vc<pam_deque<2>> pam(N);
  FOR(i, N) pam[i].pb(s[i]);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    a = g[a], b = g[b];
    if (a == b) {
      print(pam[a].ke());
    } else {
      if (g.size(a) > g.size(b)) {
        for (char x : pam[b].s.get_all()) pam[a].pb(x);
        g.set(a, b);
        print(pam[a].ke());
      } else {
        string s = pam[a].s.get_all();
        reverse(s);
        for (char x : s) pam[b].pf(x);
        g.set(b, a);
        print(pam[b].ke());
      }
    }
  }
}

int main() {
  Yorisou();
  return 0;
}