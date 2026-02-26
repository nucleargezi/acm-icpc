#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
map<string, string> mp;
int g = []() {
  mp["UUU"] = 'F';
  mp["UUC"] = 'F';

  mp["UUA"] = 'L';
  mp["UUG"] = 'L';
  mp["CUU"] = 'L';
  mp["CUC"] = 'L';
  mp["CUA"] = 'L';
  mp["CUG"] = 'L';

  mp["AUU"] = 'I';
  mp["AUC"] = 'I';
  mp["AUA"] = 'I';

  mp["AUG"] = 'M';

  mp["GUU"] = 'V';
  mp["GUC"] = 'V';
  mp["GUA"] = 'V';
  mp["GUG"] = 'V';

  mp["UCU"] = 'S';
  mp["UCC"] = 'S';
  mp["UCA"] = 'S';
  mp["UCG"] = 'S';
  mp["AGU"] = 'S';
  mp["AGC"] = 'S';

  mp["CCU"] = 'P';
  mp["CCC"] = 'P';
  mp["CCA"] = 'P';
  mp["CCG"] = 'P';

  mp["ACU"] = 'T';
  mp["ACC"] = 'T';
  mp["ACA"] = 'T';
  mp["ACG"] = 'T';

  mp["GCU"] = 'A';
  mp["GCC"] = 'A';
  mp["GCA"] = 'A';
  mp["GCG"] = 'A';

  mp["UAU"] = 'Y';
  mp["UAC"] = 'Y';

  mp["CAU"] = 'H';
  mp["CAC"] = 'H';

  mp["CAA"] = 'Q';
  mp["CAG"] = 'Q';
  mp["AAU"] = 'N';
  mp["AAC"] = 'N';

  mp["AAA"] = 'K';
  mp["AAG"] = 'K';

  mp["GAU"] = 'D';
  mp["GAC"] = 'D';

  mp["GAA"] = 'E';
  mp["GAG"] = 'E';

  mp["UGU"] = 'C';
  mp["UGC"] = 'C';

  mp["UGG"] = 'W';

  mp["CGU"] = 'R';
  mp["CGC"] = 'R';
  mp["CGA"] = 'R';
  mp["CGG"] = 'R';
  mp["AGA"] = 'R';
  mp["AGG"] = 'R';

  mp["GGU"] = 'G';
  mp["GGC"] = 'G';
  mp["GGA"] = 'G';
  mp["GGG"] = 'G';

  mp["UAA"] = "STOP";
  mp["UAG"] = "STOP";
  mp["UGA"] = "STOP";
  return 0;
}();
void Yorisou() {
  STR(s);
  int N = len(s);
  string t;
  FOR(i, 0, N, 3) {
    if (mp[s.substr(i, 3)] == "STOP") break;
    else t += mp[s.substr(i, 3)];
  }
  print(t);
}
#include "YRS/aa/main.hpp"