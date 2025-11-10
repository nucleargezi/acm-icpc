#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/PR/primtable.hpp"

// #define tests
Z t = primtable(3'000'00);
void Yorisou() {
  INT(N, K);
  vector<int> ans{1};
  for (int e : t) {
    if (e > N or len(ans) == K) break;
    ans.ep(e);
  }
  if (len(ans) == K) YES(), print(ans);
  else NO();
}
#include "YRS/Z_H/main.hpp"