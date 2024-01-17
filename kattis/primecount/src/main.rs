#![allow(dead_code)]
mod input {
    use std::io::BufRead;

    pub fn get_line_of_integers<R: BufRead>(stdin: &mut R, buffer: &mut String) -> Vec<i32> {
        buffer.clear();
        stdin.read_line(buffer).expect("Failed to read line");
        buffer
            .split_whitespace()
            .map(|x| x.parse::<i32>().expect("Failed to parse integer"))
            .collect()
    }

    pub fn get_line_of_integer<R: BufRead>(stdin: &mut R, buffer: &mut String) -> i32 {
        buffer.clear();
        stdin.read_line(buffer).expect("Failed to read line");
        buffer
            .trim()
            .parse::<i32>()
            .expect("Failed to parse integer")
    }

    pub fn get_line<R: BufRead>(stdin: &mut R, buffer: &mut String) -> String {
        buffer.clear();
        stdin.read_line(buffer).expect("Failed to read line");
        buffer.trim().to_string()
    }
}

use std::io::BufRead;

use input::*;

pub fn sieve_of_eratosthenes(last: u64) -> u64 {
    let is_even = |x: usize| -> bool { x & 1 == 0 };

    let last = last as usize;
    let mut primes = 0;
    let mut sieve = vec![true; last + 1];
    for i in 2..=last {
        if i == 2 {
            primes += 1;
            continue;
        }
        if is_even(i) {
            continue;
        }
        if sieve[i] {
            primes += 1;
            for j in ((i * i)..=last).step_by(i) {
                sieve[j] = false;
            }
        }
    }
    primes
}

fn solve<R: BufRead>(stdin: &mut R, buffer: &mut String) -> String {
    let value = get_line_of_integer(stdin, buffer);
    sieve_of_eratosthenes(value as u64).to_string()
}

fn main() {
    let stdin = std::io::stdin();
    let mut stdin = stdin.lock();
    let mut buffer = String::with_capacity(1024);

    print!("{}", solve(&mut stdin, &mut buffer))
}

#[cfg(test)]
mod tests {
    use std::io::Cursor;

    use super::*;

    #[test]
    fn test_sieve_of_eratosthenes() {
        assert_eq!(sieve_of_eratosthenes(10), 4);
        assert_eq!(sieve_of_eratosthenes(100), 25);
        assert_eq!(sieve_of_eratosthenes(1000), 168);
        assert_eq!(sieve_of_eratosthenes(10000), 1229);
    }

    #[test]
    fn test_solve() {
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut Cursor::new("10\n"), &mut buffer), "4");
        assert_eq!(solve(&mut Cursor::new("100\n"), &mut buffer), "25");
        assert_eq!(solve(&mut Cursor::new("1000\n"), &mut buffer), "168");
        assert_eq!(solve(&mut Cursor::new("10000\n"), &mut buffer), "1229");
    }

    #[test]
    fn test_solve_2() {
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut "10\n".as_bytes(), &mut buffer), "4");
    }
}
