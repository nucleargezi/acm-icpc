#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/pow.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  ll K = []() {
    mint s;
    STR(str);
    for (int c : str) s = s * 10 + c - '0';
    return s.val();
  }();
  VEC(mint, f, N);
  print(pow(f, K));
}

int main() {
  Yorisou();
  return 0;
}