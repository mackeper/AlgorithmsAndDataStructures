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
    let mut result = Vec::new();
    let cases: u64 = get_line_of_integer(stdin, buffer);
    for case in 1..=cases {
        let rows_cols: Vec<usize> = get_line_of_integers(stdin, buffer);
        let (rows, cols) = (rows_cols[0], rows_cols[1]);
        let mut grid = vec![vec!['.'; cols as usize]; rows as usize];
        for row in 0..rows {
            let line = get_line(stdin, buffer);
            for (col, ch) in line.chars().enumerate() {
                grid[rows - row - 1][cols - col - 1] = ch;
            }
        }
        result.push(format!("Test {}\n", case));
        for row in 0..rows {
            for col in 0..cols {
                result.push(format!("{}", grid[row as usize][col as usize]));
            }
            result.push("\n".to_string());
        }
    }
    result.join("").to_string()
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
    fn test_mirror_01() {
        let mut stdin = "2\n2 2\n.*\n..\n4 4\n***.\n**..\n....\n....".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(
            solve(&mut stdin, &mut buffer),
            "Test 1\n..\n*.\nTest 2\n....\n....\n..**\n.***"
        );
    }
}

