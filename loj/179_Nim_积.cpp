#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/nt/nim/nimbase.hpp"

uint SA, SB, SC;
uint rng() {
  SA ^= SA << 16;
  SA ^= SA >> 5;
  SA ^= SA << 1;
  uint t = SA;
  SA = SB;
  SB = SC;
  SC ^= t ^ SA;
  return SC;
}

void Yorisou() {
  INT(T);
  IN(SA, SB, SC);
  uint s = 0;
  FOR(T) {
    uint x = rng() + s, y = rng();
    s = nim.ml(x, y);
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}