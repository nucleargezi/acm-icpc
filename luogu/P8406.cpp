#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/string/pam_deque.hpp"
#include "YRS/ds/dsu.hpp"

// #define tests
struct dat {
  fast_deque<char> s;
  pam_deque<2> pam;
};
void Yorisou() {
  INT(n);
  S(s);
  dsu g(n);
  vector<dat> pam(n);
  for (int i = 0; i < n; ++i) {
    pam[i].pam.push_back(pam[i].s, s[i]);
  }
  for (int i = 1; i < n; ++i) {
    INT(a, b);
    --a, --b;
    int fa = g[a], fb = g[b];
    if (fa == fb) {
      UL(pam[fa].pam.keis());
      continue;
    }
    if (pam[fa].s.size() >= pam[fb].s.size()) {
      for (char c : pam[fb].s.enumerate()) {
        pam[fa].pam.push_back(pam[fa].s, c);
      }
      g.merge_f(fa, fb);
      UL(pam[fa].pam.keis());
    } else {
      for (char c : reversed(pam[fa].s.enumerate())) {
        pam[fb].pam.push_front(pam[fb].s, c);
      }
      g.merge_f(fb, fa);
      UL(pam[fb].pam.keis());
    }
  }
}
#include "YRS/Z_H/main.hpp"