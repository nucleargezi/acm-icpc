#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  int n = si(s);
  if (n >= 3 and s.substr(n - 3, 3) == "ing") {
    FOR(3) pop(s);
  } else if (n >= 2) {
    if (s.substr(n - 2, 2) == "ly" or s.substr(n - 2, 2) == "er") FOR(2) pop(s);
  }
  print(s);
}

int main() { Yorisou(); }