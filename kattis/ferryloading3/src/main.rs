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

#[derive(PartialEq, Debug)]
enum Side {
    Left,
    Right,
}

#[derive(Debug)]
struct Car {
    pub side: Side,
    pub arrival_time: usize,
    pub destination_time: usize,
}

#[derive(Debug)]
struct Ferry {
    pub side: Side,
    pub travel_time: usize,
    pub capacity: usize,
}

impl Ferry {
    pub fn new(capacity: usize, travel_time: usize) -> Self {
        Self {
            side: Side::Left,
            travel_time,
            capacity,
        }
    }
}

fn ferry_loading(ferry: &mut Ferry, cars: &mut Vec<Car>, time: usize, cars_left: usize) {
    if cars_left <= 0 {
        return;
    }
    let cars_ready_to_load = cars
        .iter()
        .enumerate()
        .filter(|(_, x)| x.side == ferry.side && x.arrival_time <= time && x.destination_time == 0)
        .take(ferry.capacity)
        .map(|(i, _)| i)
        .collect::<Vec<usize>>();

    if cars_ready_to_load.is_empty() {
        // if there are cars on the other side, and the ferry is empty, go to the other side
        if cars
            .iter()
            .any(|x| x.side != ferry.side && x.arrival_time <= time && x.destination_time == 0)
        {
            ferry.side = match ferry.side {
                Side::Left => Side::Right,
                Side::Right => Side::Left,
            };
            ferry_loading(ferry, cars, time + ferry.travel_time, cars_left);
            return;
        }

        // if there are cars on the same side, and the ferry is empty, wait for the next car
        let next_car = cars
            .iter()
            .filter(|x| x.destination_time == 0)
            .min_by_key(|x| x.arrival_time)
            .unwrap();

        let new_time = if next_car.side == ferry.side {
            next_car.arrival_time
        } else {
            next_car.arrival_time + ferry.travel_time
        };

        match next_car.side {
            Side::Left => ferry.side = Side::Left,
            Side::Right => ferry.side = Side::Right,
        };

        ferry_loading(ferry, cars, new_time, cars_left);
    } else {
        for i in &cars_ready_to_load {
            cars[*i].destination_time = time + ferry.travel_time;
        }
        ferry.side = match ferry.side {
            Side::Left => Side::Right,
            Side::Right => Side::Left,
        };
        ferry_loading(
            ferry,
            cars,
            time + ferry.travel_time,
            cars_left - cars_ready_to_load.len(),
        );
    }
}

fn solve_case<R: BufRead>(stdin: &mut R, buffer: &mut String) -> String {
    let n_t_m = get_line_of_integers(stdin, buffer);
    let (n, t, m) = (n_t_m[0], n_t_m[1], n_t_m[2]);

    let mut ferry = Ferry::new(n, t);
    let mut cars = vec![];

    for _ in 0..m {
        let car_input = get_line(stdin, buffer);
        let side = if car_input.ends_with("left") {
            Side::Left
        } else {
            Side::Right
        };
        let arrival_time = car_input
            .split_whitespace()
            .next()
            .unwrap()
            .parse::<usize>()
            .unwrap();

        cars.push(Car {
            side,
            arrival_time,
            destination_time: 0,
        });
    }

    let car_len = cars.len();
    ferry_loading(&mut ferry, &mut cars, 0, car_len);

    cars.iter()
        .map(|x| x.destination_time.to_string())
        .collect::<Vec<String>>()
        .join("\n")
}

fn solve<R: BufRead>(stdin: &mut R, buffer: &mut String) -> String {
    let cases: usize = get_line_of_integer(stdin, buffer);
    let mut result = vec![];
    for _ in 0..cases {
        result.push(solve_case(stdin, buffer));
    }

    result.join("\n\n")
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
        let mut stdin = "2\n2 10 10\n0 left\n10 left\n20 left\n30 left\n40 left\n50 left\n60 left\n70 left\n80 left\n90 left\n2 10 3\n10 right\n25 left\n40 left\n".as_bytes();
        let mut buffer = String::with_capacity(1024);
        assert_eq!(
            solve(&mut stdin, &mut buffer),
            "10\n30\n30\n50\n50\n70\n70\n90\n90\n110\n\n30\n40\n60"
        );
    }
}
