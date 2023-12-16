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

fn is_flippable(n: usize) -> (bool, String) {
    let mut n = n;
    let mut flipped = Vec::new();
    while n > 0 {
        let digit = n % 10;
        if digit == 3 || digit == 4 || digit == 7 {
            return (false, "".to_string());
        }
        if digit == 6 {
            flipped.push('9');
        } else if digit == 9 {
            flipped.push('6');
        } else if digit == 0 {
            flipped.push('0');
        } else if digit == 1 {
            flipped.push('1');
        } else if digit == 2 {
            flipped.push('5');
        } else if digit == 5 {
            flipped.push('2');
        } else if digit == 8 {
            flipped.push('8');
        }
        n /= 10;
    }
    (true, flipped.iter().collect::<String>())
}

fn main() {
    let mut cache = std::collections::BTreeMap::new();
    let lines = std::io::stdin()
        .lines()
        .map(|x| x.unwrap().parse::<usize>().unwrap());
    for k in lines {
        println!("k: {}", k);
        cache.last_entry();
        if k > cache.len() {
            let mut i = cache.len() + 1;
            while cache.len() < k {
                println!("i: {}", i);
                let (flippable, flipped) = is_flippable(i);
                if flippable {
                    println!("insert: {} {} {}", cache.len(), i, flipped);
                    cache.insert(flipped);
                }
                i += 1;
            }
        }
        println!("cache: {:?}", cache);
        println!("result {}", cache[k - 1]);
    }
}
