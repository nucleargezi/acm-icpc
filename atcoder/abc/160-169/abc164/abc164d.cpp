#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"

using T = mint_t<2019>;

void Yorisou() {
  STR(a);
  for (char &c : a) c -= '0';
  int N = si(a);
  T hs, bs = 1;
  ll s = 0;
  vc<int> c(2019);
  c[0] = 1;
  FOR_R(i, N) {
    hs += bs * a[i];
    s += c[hs.val()]++;
    bs *= 10;
  }
  print(s);
}

int main() { Yorisou(); }