#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/hull.hpp"

using P = point<ll>;

bool A(vc<P> a) {
  a = rearrange(a, hull(a));
  if (si(a) != 4) return 0;
  return (a[0] - a[1]).sq() == (a[2] - a[3]).sq() and
         (a[1] - a[2]).sq() == (a[0] - a[3]).sq() and 
         (a[0] - a[2]).sq() == (a[1] - a[3]).sq();
}

bool B(vc<P> a) {
  if (not A(a)) return 0;
  a = rearrange(a, hull(a));
  return (a[0] - a[1]).sq() == (a[2] - a[3]).sq() and
         (a[1] - a[2]).sq() == (a[0] - a[3]).sq() and 
         (a[0] - a[1]).sq() == (a[1] - a[2]).sq() and 
         (a[0] - a[2]).sq() == (a[1] - a[3]).sq();
}

void Yorisou() {
  constexpr int N = 8;
  VEC(P, a, N);
  vc<int> I(N);
  iota(all(I), 0);

  do {
    Z p = rearrange(a, I);
    if (A({p[4], p[5], p[6], p[7]}) and B({p[0], p[1], p[2], p[3]})) {
      YES();
      vc<int> bf{bg(I), bg(I) + 4};
      for (int &x : bf) ++x;
      print(bf);
      bf = {bg(I) + 4, ed(I)};
      for (int &x : bf) ++x;
      print(bf);
      return;
    }
  } while (next_permutation(all(I)));
  NO();
}

int main() {
  Yorisou();
  return 0;
}