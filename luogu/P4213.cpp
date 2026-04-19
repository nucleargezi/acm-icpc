#include "YRS/all.hpp"
#include "YRS/pr/du.hpp"

phi_sum<ll> a;
mu_sum<ll> b;
void Yorisou() {
  INT(N);
  print(a[N], b[N]);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}