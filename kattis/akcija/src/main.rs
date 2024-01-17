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
    let number_of_books: usize = get_line_of_integer(stdin, buffer);
    let mut books = Vec::new();
    for _ in 0..number_of_books {
        books.push(get_line_of_integer(stdin, buffer));
    }
    let mut sum = 0;
    books.sort_unstable();
    books.iter().rev().enumerate().for_each(|(i, book)| {
        if i % 3 != 2 {
            sum += book;
        }
    });
    sum.to_string()
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
        let mut stdin = "4\n3\n2\n3\n2\n".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut stdin, &mut buffer), "8");
    }

    #[test]
    fn test_2() {
        let mut stdin = "6\n6\n4\n5\n5\n5\n5\n".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut stdin, &mut buffer), "21");
    }

    #[test]
    fn test_3() {
        let mut stdin = "1\n1000000000\n".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut stdin, &mut buffer), "1000000000");
    }

    #[test]
    fn test_4() {
        let mut stdin = "3\n1\n1\n1\n".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut stdin, &mut buffer), "2");
    }

    #[test]
    fn test_5() {
        let mut stdin = "3\n1\n1\n2\n".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut stdin, &mut buffer), "3");
    }

    #[test]
    fn test_6() {
        let mut stdin = "2\n2\n2\n".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut stdin, &mut buffer), "4");
    }

    #[test]
    fn test_7() {
        let mut stdin = "1\n1\n".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut stdin, &mut buffer), "1");
    }

    #[test]
    fn test_8() {
        let mut stdin = "10\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut stdin, &mut buffer), "40");
    }
}
