mod input {
    pub fn get_line_of_integer() -> i32 {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input
            .trim_start_matches("\u{feff}")
            .trim()
            .parse::<i32>()
            .unwrap()
    }

    pub fn get_line_of_integers() -> Vec<i32> {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input
            .trim_start_matches("\u{feff}")
            .split_whitespace()
            .map(|x| x.parse::<i32>().unwrap())
            .collect()
    }
}

use input::*;

fn main() {
    let line = get_line_of_integers();
    let rooms: i32 = line[0];
    let bottles: i32 = line[1];

    let mut rooms_sum: i32 = 0;
    for _ in 0..rooms {
        rooms_sum += get_line_of_integer();
    }

    println!("{}", if rooms_sum > bottles { "Neibb" } else { "Jebb" });
}
