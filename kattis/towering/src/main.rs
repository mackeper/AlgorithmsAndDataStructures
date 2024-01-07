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

use std::{cmp::Reverse, io::BufRead};

use input::*;

fn solve<R: BufRead>(stdin: &mut R, buffer: &mut String) -> String {
    let values: Vec<i64> = get_line_of_integers(stdin, buffer);
    let mut boxes = values.iter().take(6).copied().collect::<Vec<_>>();
    boxes.sort_by_key(|w| Reverse(*w));
    let (h1, _h2) = (values[6], values[7]);

    for i in 0..6 {
        for j in (i + 1)..6 {
            for k in (j + 1)..6 {
                let (a, b, c) = (boxes[i], boxes[j], boxes[k]);
                if a + b + c == h1 {
                    let t2 = boxes
                        .iter()
                        .filter(|&&x| x != a && x != b && x != c)
                        .copied()
                        .collect::<Vec<_>>();

                    return format!("{} {} {} {} {} {}", a, b, c, t2[0], t2[1], t2[2]);
                }
            }
        }
    }
    "".to_string()
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
    fn test_001() {
        let mut stdin = "12 8 2 4 10 3 25 14".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut stdin, &mut buffer), "12 10 3 8 4 2");
    }

    #[test]
    fn test_002() {
        let mut stdin = "12 17 36 37 51 63 92 124".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(solve(&mut stdin, &mut buffer), "63 17 12 51 37 36");
    }
}

