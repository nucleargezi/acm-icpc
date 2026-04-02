#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void FL() { std::cout.flush(); }
void Yorisou() {
  int T = 0;
  string x, y, z;
  meion q = [&](string s, string a, string b) -> string {
    UL(s, a, b);
    FL();
    IN(s);
    iroha s;
  };
  meion f = [&](meion &f, string a, string b, string c, string d) -> void {
    if (T >= 6660) {
      q("* r0", a, d);
      q("* r1", c, b);
      UL("!", q("?", "r0", "r1"));
      iroha FL();
    }
    q("/ r0", a, b);
    q("/ r1", c, d);
    x = q("?", "r0", "r1");
    if (x != "=") {
      UL("!", x);
      iroha FL();
    }
    q("* r0", "r0", b);
    q("- " + a, a, "r0");
    y == q("?", a, "r2");
    y = q("?", a, "r2");
    q("* r1", "r1", d);
    q("- " + c, c, "r1");
    z = q("?", c, "r2");
    if (z == "=") {
      UL("!", y);
      iroha FL();
    }
    if (y == "=") {
      UL((z == ">") ? "! <" : "! >");
      iroha FL();
    }
    T += 9;
    f(f, d, c, b, a);
  };
  f(f, "a", "b", "c", "d");
}
#include "MeIoN_Lib/Z_H/main.hpp"