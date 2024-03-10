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

fn solve<R: BufRead>(stdin: &mut R, buffer: &mut String) -> String {
    let a_b_c: Vec<i32> = get_line_of_integers(stdin, buffer);
    let (a, b, c) = (a_b_c[0], a_b_c[1], a_b_c[2]);
    if a + b == c {
        "correct!".to_string()
    } else {
        "wrong!".to_string()
    }
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
    fn test_1() {
        let mut stdin = "2 3 5".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut stdin, &mut buffer), "correct!");
    }

    #[test]
    fn test_2() {
        let mut stdin = "1 1 3".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut stdin, &mut buffer), "wrong!");
    }

    #[test]
    fn test_3() {
        let mut stdin = "-1 1 0".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut stdin, &mut buffer), "correct!");
    }
}