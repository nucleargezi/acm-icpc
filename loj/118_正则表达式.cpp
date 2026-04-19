#include <regex>
#include "YRS/all.hpp"

void Yorisou() {
  string a, b;
  while (cin >> a >> b) {
    Yes(regex_match(b, regex(a, regex_constants::__polynomial)));
  }
}

int main() {
  Yorisou();
  return 0;
}