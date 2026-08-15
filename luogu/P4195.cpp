#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/discrete_log.hpp"

void Yorisou() {
  int a, p, b, s;
  while (IN(a, p, b), (a or b or p)) {
    s = discrete_log(a, b, p);
    if (s == -1) print("No Solution");
    else print(s);
  }
}

int main() {
  Yorisou();
  return 0;
}