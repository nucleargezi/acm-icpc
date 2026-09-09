#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  LL(x);
  for (ll i = -200; i < 200; ++i) {
    for (ll k = -200; k < 200; ++k) {
      if (i * i * i * i * i - k * k * k * k * k == x) return print(i, k);
    }
  }
}

int main() { Yorisou(); }