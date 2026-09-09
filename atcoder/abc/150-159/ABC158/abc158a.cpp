#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  STR(s);
  Yes(count(all(s), 'A') and count(all(s), 'B'));
}

int main() { Yorisou(); }