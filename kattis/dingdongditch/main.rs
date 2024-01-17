#![allow(dead_code)]
mod input {
    use std::io;

    pub fn get_line_of_integer<T>() -> T
    where
        T: std::str::FromStr,
        <T as std::str::FromStr>::Err: std::fmt::Debug,
    {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input
            .trim_start_matches("\u{feff}")
            .trim()
            .parse::<T>()
            .unwrap()
    }

    pub fn get_line_of_integers<T>() -> Vec<T>
    where
        T: std::str::FromStr,
        <T as std::str::FromStr>::Err: std::fmt::Debug,
    {
        let stdin = io::stdin();
        let line = stdin.lines().next().unwrap().unwrap();

        line.split_whitespace()
            .flat_map(|s| s.parse::<T>())
            .collect()
    }
}

use std::io;

fn main() {
    let mut lines = io::stdin()
        .lines()
        .map(|line| {
            line.unwrap()
                .split_whitespace()
                .flat_map(|w| w.parse::<usize>())
                .collect::<Vec<usize>>()
        })
        .collect::<Vec<Vec<usize>>>();

    let _houses = lines[0][0];
    let friends = lines[0][1];

    lines[1].sort();
    let anger_value = &lines[1];
    let friends_bells_to_ring = &lines[2];

    let mut bell_to_anger_value = std::collections::HashMap::new();

    for i in 0..friends {
        let bell = friends_bells_to_ring[i];
        if !bell_to_anger_value.contains_key(&bell) {
            bell_to_anger_value.insert(bell, anger_value[..bell].iter().sum::<usize>());
        }
        println!("{}", bell_to_anger_value.get(&bell).unwrap());
    }
}
