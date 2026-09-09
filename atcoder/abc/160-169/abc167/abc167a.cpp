#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  STR(s, t);
  pop(t);
  Yes(s == t);
}

int main() { Yorisou(); }