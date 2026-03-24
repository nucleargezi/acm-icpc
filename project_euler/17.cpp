#include "YRS/all.hpp"

string a[] = {"", "one", "two", "three", "four", "five", "six", "seven",
    "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string b[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
    "eighty", "ninety"};
string f(int i) {
  if (i < 20) return a[i];
  else if (i < 100) return b[i / 10] + a[i % 10];
  else if (i == 100) return "onehundred";
  else if (i == 1000) return "onethousand";
  else if (i % 100 == 0) return "hundred" + a[i / 100];
  else return "hundred" + a[i / 100] + "and" + f(i % 100);
}
void Yorisou() {
  string s;
  FOR(i, 1, 1001) s += f(i);
  print(si(s));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"