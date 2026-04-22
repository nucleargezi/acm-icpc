#include "YRS/all.hpp"
#include"interaction.h"

void Yorisou() {
  int N = get_num();
  vc<int> s;
  FOR(i, N) s.ep(bina([&](int x) { return guess(i, x) <= 0; }, 0, 1'000'001));
  submit(s);
}

int main() {
  Yorisou();
  return 0;
}