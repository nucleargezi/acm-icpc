#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  STR(s);
  Yes(s[2] == s[3] and s[4] == s[5]);
}

int main() { Yorisou(); }