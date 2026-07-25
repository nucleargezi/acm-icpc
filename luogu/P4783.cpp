#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/mat.hpp"
#include "YRS/mod/mint_t.hpp"

void Yorisou() {
  LL(N);
  mat<M11> a(N, N);
  IN(a);
  Z [ok, det, inv] = a.inv();
  if (not ok) print("No Solution");
  else print(inv);
}

int main() {
  Yorisou();
  return 0;
}