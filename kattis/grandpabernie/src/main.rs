#![allow(dead_code)]
mod input {
    use std::io::BufRead;

    pub fn get_line<R: BufRead>(stdin: &mut R, buffer: &mut String) {
        buffer.clear();
        stdin.read_line(buffer).expect("Failed to read line");
    }
}

use std::{
    collections::HashMap,
    io::{BufRead, Write},
};

use input::*;

fn solve<R: BufRead>(stdin: &mut R, buffer: &mut String, stdout: &mut impl Write) {
    get_line(stdin, buffer);
    let n = buffer.trim().parse::<usize>().unwrap();
    let mut visited = HashMap::<String, Vec<usize>>::new();

    for _ in 0..n {
        get_line(stdin, buffer);
        let mut parts = buffer.split_whitespace();
        let country = parts.next().unwrap();
        let year = parts.next().unwrap().parse::<usize>().unwrap();

        if visited.contains_key(country) {
            visited.get_mut(country).unwrap().push(year);
        } else {
            visited.insert(country.to_string(), vec![year]);
        }
    }

    for (_, years) in visited.iter_mut() {
        years.sort_unstable();
    }

    get_line(stdin, buffer);
    let q = buffer.trim().parse::<usize>().unwrap();

    for _ in 0..q {
        get_line(stdin, buffer);
        let mut parts = buffer.split_whitespace();
        let country = parts.next().unwrap();
        let k = parts.next().unwrap().parse::<usize>().unwrap() - 1;

        let year = visited.get(country).unwrap().get(k).unwrap();
        writeln!(stdout, "{}", year).unwrap();
    }
}

fn main() {
    let stdin = std::io::stdin();
    let mut stdin = stdin.lock();
    let mut buffer = String::with_capacity(1024);

    let stdout = std::io::stdout();
    let lock = stdout.lock();
    let mut w = std::io::BufWriter::new(lock);

    solve(&mut stdin, &mut buffer, &mut w);
}
