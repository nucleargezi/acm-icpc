#include "YRS/all.hpp"
#include "YRS/ds/seg/range_min_add.hpp"

void Yorisou() {
  cin.tie(0)->sync_with_stdio(0);
  INT(N);
  VEC(ll, a, N);
  range_min_add<ll> seg(move(a));
  
  INT(Q);
  string s;
  cin.ignore();
  FOR(Q) {
    getline(cin, s);
    int c = count(all(s), ' '), l, r, x;
    stringstream ss(s);
    ss >> l >> r;
    if (c == 2) {
      ss >> x;
      if (l <= r) {
        seg.apply(l, r + 1, x);
      } else {
        seg.apply(0, r + 1, x);
        seg.apply(l, N, x);
      }
    } else {
      if (l <= r) {
        print(seg.prod(l, r + 1));
      } else {
        print(min(seg.prod(0, r + 1), seg.prod(l, N)));
      }
    }
  }
}

int main() { Yorisou(); }