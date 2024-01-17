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

fn evaluate_happines(coefficients: &[i64]) -> i64 {
    coefficients
        .iter()
        .enumerate()
        .fold(0, |acc, (i, c)| acc + *c * (i as i64 + 1))
}

fn solve<R: BufRead>(stdin: &mut R, buffer: &mut String) -> String {
    let n: usize = get_line_of_integer(stdin, buffer);
    let happiness = get_line_of_integers::<i64, R>(stdin, buffer)
        .iter()
        .filter(|x| **x != 0)
        .cloned()
        .collect::<Vec<_>>();

    let mut after_happiness = Vec::with_capacity(n);
    after_happiness.push(0);

    let mut before_happiness = Vec::with_capacity(n);
    before_happiness.push(0);

    for i in 0..n - 1 {
        after_happiness.push(after_happiness[i] + happiness[n - i - 2] * (n - i) as i64);
        before_happiness.push(before_happiness[i] + happiness[i] * (i + 1) as i64);
    }

    let mut max_happiness = i64::min_value();
    let set_max = |x: &mut i64, y: i64| {
        if y > *x {
            *x = y;
        }
    };
    for i in 0..happiness.len() + 1 {
        if i == 0 {
            set_max(&mut max_happiness, after_happiness[happiness.len() - i]);
        } else if i == happiness.len() {
            set_max(&mut max_happiness, before_happiness[i]);
        } else {
            set_max(
                &mut max_happiness,
                before_happiness[i] + after_happiness[happiness.len() - i],
            );
        }
    }

    max_happiness.to_string()
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
        let mut stdin = "3\n1 0 -2".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut stdin, &mut buffer), "-3");
    }

    #[test]
    fn test_2() {
        let mut stdin = "5\n0 -8 1 1 5".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut stdin, &mut buffer), "24");
    }

    #[test]
    fn test_3() {
        let mut stdin = "7\n2 -4 5 -3 0 -1 2".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut stdin, &mut buffer), "7");
    }
}
