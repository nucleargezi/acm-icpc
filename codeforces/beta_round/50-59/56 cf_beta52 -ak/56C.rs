use std::io::{self, Read};
use std::str::FromStr;

fn yorisou() {
  let mut sc = Scanner::new();
  
  let mut ans: usize= 0;
  let mut s = vec![String::new(); 114514];
  let mut t = 0;

  let sin = sc.get_line();

  for c in sin.chars() {
    match c {
      '.' => {
        for i in 0..t {
          if s[i] == s[t] {
            ans += 1;
          }
        }
        s[t].clear();
        if t > 0 {
          t -= 1;
        }
      }
      ':' | ',' => {
        t += 1;
      }
      c if !c.is_whitespace() => {
        s[t].push(c);
      }
      _ => {}
    }
  }
  println!("{}", ans);
}
fn main() {
  yorisou();
}

#[allow(warnings)]
type int = i32;
#[allow(warnings)]
type uint = u32;
#[allow(warnings)]
type ll = i64;
#[allow(warnings)]
type ull = u64;

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
