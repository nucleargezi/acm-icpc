#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  set<char> se{'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
  string t;
  for (char c : s) if (not se.contains(c)) t += '.', t += tolower(c);
  print(t);
}

int main() {
  Yorisou();
  return 0;
}