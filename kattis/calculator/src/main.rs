#![allow(dead_code)]
mod input {
    use std::{io::BufRead, str::FromStr};

    pub fn get_line_of_integers<T, R>(stdin: &mut R, buffer: &mut String) -> Vec<T>
    where
        T: FromStr,
        <T as FromStr>::Err: std::fmt::Debug,
        R: BufRead,
    {
        buffer.clear();
        stdin.read_line(buffer).expect("Failed to read line");
        buffer
            .split_whitespace()
            .map(|x| x.parse::<T>().expect("Failed to parse integer"))
            .collect()
    }

    pub fn get_line_of_integer<T, R>(stdin: &mut R, buffer: &mut String) -> T
    where
        T: FromStr,
        <T as FromStr>::Err: std::fmt::Debug,
        R: BufRead,
    {
        buffer.clear();
        stdin.read_line(buffer).expect("Failed to read line");
        buffer.trim().parse::<T>().expect("Failed to parse integer")
    }

    pub fn get_line<R: BufRead>(stdin: &mut R, buffer: &mut String) -> String {
        buffer.clear();
        stdin.read_line(buffer).expect("Failed to read line");
        buffer.trim().to_string()
    }
}

use std::io::BufRead;

use input::*;

mod calculator;
use calculator::*;

fn solve<R: BufRead>(stdin: &mut R, buffer: &mut String) -> String {
    let value: u64 = get_line_of_integer(stdin, buffer);
    let side = (value as f64).sqrt();
    let fence = side * 4.0;
    fence.to_string()
}

fn main() {
    let stdin = std::io::stdin();
    let mut stdin = stdin.lock();
    let mut buffer = String::with_capacity(1024);

    println!("{}", solve(&mut stdin, &mut buffer));
}

#[cfg(test)]
mod tests {
    use super::*;

    fn within_epsilon(a: f64, b: f64) -> bool {
        (a - b).abs() < 1e-6
    }

    #[test]
    fn test_calculator_sample_1() {
        let mut stdin = "5 - 3-2\n5- (3-2)\n5 / 3 / 2\n5 / (3 / 2)\n1/3+1\n1/(3+1)\n-4--2\n(1-3)/(5+4)\n2*3*5*7*11*13*17*19\n-5/-5".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(
            solve(&mut stdin, &mut buffer),
            "0.00\n4.00\n0.83\n3.33\n1.33\n0.25\n-2.00\n-0.22\n9699690.00\n1.00"
        );
    }
}

