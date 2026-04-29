#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/enum_div_range.hpp"

ll f(ll x) {
  ll s = 0;
  for (var [l, r, q] : enum_div_range(x)) s += q * (r - l);
  return s;
}
void Yorisou() {
  LL(l, r);
  --l;
  print(f(r) - f(l));
}

int main() {
  Yorisou();
  return 0;
}