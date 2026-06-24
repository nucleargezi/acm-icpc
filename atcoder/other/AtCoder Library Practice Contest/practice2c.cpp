#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/floor_sum_line.hpp"

void Yorisou() {
  INT(Q);
  FOR(Q) {
    INT(N, P, a, b);
    print(floor_sum_line<ll, ll>(0, N, a, b, P));
  }
}

int main() {
  Yorisou();
  return 0;
}