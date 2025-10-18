#include "YRS/all.hpp"

void yorisou() {
  INT(N);
  VEC(int, a, N);
  int ok = QMAX(a), ng = -1;
  print(binary_search([&](int c) -> bool {
    vector<pair<int, int>> ls, need;
    for (int x : a) {
      int cut = binary_search([&](int cc) -> bool {
        int s = cc;
        for (Z [l, r] : ls) {
          if (l > cc) continue;
          chmin(l, cc), chmin(r, cc);
          s += r - l + 1;
        }
        return s >= x;
      }, ok, ng);
      ls.clear();
      if (need.empty()) {
        int d = cut - c;
        if (d > 0) need.ep(c - d + 1, c);
        else if (d < 0) ls.ep(cut + 1, c);
      } else {
        int l = need[0].fi, nd = cut - l + 1;
        if (nd > 0) {
          if (l - nd < 1) return false;
          need.clear();
          need.ep(l - nd, l - 1);
        } else {
          ++cut;
          for (Z [l, r] : need) {
            if (cut <= l - 1) ls.ep(cut, l - 1);
            chmax(cut, r + 1);
          }
          if (cut <= c) ls.ep(cut, c);
          need.clear();
        }
      }
    }
    return need.empty();
  }, ok, ng));
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  yorisou();
  return 0;
}