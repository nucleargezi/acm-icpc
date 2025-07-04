use std::io::{self, Read};
use std::str::FromStr;

struct Scanner {
  buffer: Vec<String>,
}
#[allow(dead_code)]
impl Scanner {
  fn new() -> Self {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let buffer = input
      .split_whitespace()
      .map(str::to_string)
      .collect::<Vec<_>>();
    Self { buffer }
  }

  fn next<T: FromStr>(&mut self) -> T {
    self
      .buffer
      .remove(0)
      .parse::<T>()
      .ok()
      .expect("Failed parse")
  }

  fn get_vec<T: FromStr>(&mut self, n: usize) -> Vec<T> {
    (0..n).map(|_| self.next()).collect()
  }

  fn get_line(&mut self) -> String {
    self.buffer.remove(0).to_string()
  }

  fn get_char(&mut self) -> char {
    self.next::<String>().chars().next().unwrap()
  }

  fn get_pair<T: FromStr, U: FromStr>(&mut self) -> (T, U) {
    (self.next(), self.next())
  }
}

#[allow(warnings)]
type int = i32;
#[allow(warnings)]
type ll = i64;
use std::collections::HashSet;
fn yorisou() {
  let mut sc = Scanner::new();

  let n: int = sc.next();
  let se: HashSet<&str> = [
    "ABSINTH",
    "BEER",
    "BRANDY",
    "CHAMPAGNE",
    "GIN",
    "RUM",
    "SAKE",
    "TEQUILA",
    "VODKA",
    "WHISKEY",
    "WINE",
  ]
  .iter()
  .cloned()
  .collect();

  let mut ans:int = 0;

  for _ in 0..n {
    let s = sc.get_line();
    let s = s.trim();
    if s.chars().next().unwrap().is_ascii_digit() {
      if let Ok(age) = s.parse::<int>() {
        ans += (age < 18) as int;
      }
    } else {
      ans += se.contains(s) as int;
    }
  }
  println!("{}", ans);
}
fn main() {
  yorisou();
}
