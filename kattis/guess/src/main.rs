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

fn get_mid(a: i32, b: i32) -> i32 {
    (a + b) / 2
}

fn solve<R: BufRead>(stdin: &mut R, buffer: &mut String) {
    let mut range = (1, 1000);
    loop {
        println!("{}", get_mid(range.0, range.1).to_string());
        let response = get_line(stdin, buffer);
        match response.as_str() {
            "correct" => return,
            "lower" => range.1 = get_mid(range.0, range.1),
            "higher" => range.0 = get_mid(range.0, range.1) + 1,
            _ => panic!("Invalid response"),
        }
    }
}

fn main() {
    let stdin = std::io::stdin();
    let mut stdin = stdin.lock();
    let mut buffer = String::with_capacity(1024);

    solve(&mut stdin, &mut buffer);
}
