#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/hashmap.hpp"
#include "YRS/ds/heap/erase_heap.hpp"

// #define tests
void Yorisou() {
  INT(N, K);
  hash_map<int> m;
  VEC(int, a, N);
  vector<string> ans;
  max_erase_heap<int> q;
  FOR(i, N) {
    if (not m[a[i]]++) q.eb(a[i]);
    else if (m[a[i]] == 2) q.pop(a[i]);
    if (i >= K - 1) {
      if (not q.empty()) ans.ep(to_str(q.top()));
      else ans.ep("Nothing");
      if (not --m[a[i - K + 1]]) q.pop(a[i - K + 1]);
      else if (m[a[i - K + 1]] == 1) q.eb(a[i - K + 1]);
    }
  }
  for (Z &x : ans) print(x);
}
#include "YRS/Z_H/main.hpp"