#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/f/k_pre_sum.hpp"

using mint = mint_t<1004535809>;
void Yorisou() {
  INT(N);
  STR(s);
  INT(t);
  VEC(mint, f, N);
  mint k;
  for (char c : s) k = k * 10 + c - '0';
  if (t) k = -k;
  print(k_pre_sum(f, k));
}

int main() { Yorisou(); }