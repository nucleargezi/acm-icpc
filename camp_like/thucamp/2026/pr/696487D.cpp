#include "YRS/all.hpp"

void Yorisou() {
  int l = 0, r;
  IN(r);
  ++r;
  while (r - l > 1) {
    int x = (l + r) >> 1;
    print(x);
    int t;
    IN(t);
    if (t == 0) return ;
    (t == 1 ? l : r) = x;
  }
}

int main() {
  // cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(20);
  int T = 1;
  // cin >> T;
  FOR(T) Yorisou();
  return 0;
}