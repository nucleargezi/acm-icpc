#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, K);
  STR(s);
  for (int i = 0, c = 0; i < N - 1 and K and not(c++ > 1000000 and ~K & 1); --K) {
    while (i + 1 < N and not(s[i] == '4' and s[i + 1] == '7')) ++i;
    if (i + 1 < N) {
      if (i & 1) s[i] = s[i + 1] = '7', i = max(i - 1, 0);
      else s[i] = s[i + 1] = '4', ++i;
    }
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}