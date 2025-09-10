#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/string/pam.hpp"

// #define tests
void Yorisou() {
  STR(s);
  PAM<26> seg(s);
  const int N = len(seg.nodes);
  vector<int> fa(N, -1);
  FOR(i, N) for (int x : seg.nodes[i].TO) {
    if (x != -1) fa[x] = i;
  }
  print(N - 2);
  FOR(i, 2, N) print(fa[i] - 1, seg.nodes[i].link - 1);
  vector<int> ans{seg.path.begin() + 1, seg.path.end()};
  for (int &x : ans) --x;
  print(ans);
}
#include "YRS/Z_H/main.hpp"