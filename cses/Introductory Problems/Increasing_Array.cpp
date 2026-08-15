#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, s);
  ll c = 0;
  FOR(N - 1) {
    INT(x);
    c += max(0, s - x);
    chmax(s, x);
  } 
  print(c);
}

int main() {
  Yorisou();
  return 0;
}