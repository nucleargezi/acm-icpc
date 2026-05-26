#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  FOR(i, N + 1) if (i * 4 <= N) {
    int l = N - i * 4;
    if (l % 7) continue;
    return print(string(i, '4') + string(l / 7, '7'));
  }
  print(-1);
}

int main() {
  Yorisou();
  return 0;
}