use std::io::{self, BufRead};

fn parse(s: &Vec<char>, idx: &mut usize, ass: i32) -> bool {
    if s.capacity() == *idx {
       return true;
    }
    *idx += 1;
    match s[*idx - 1] {
        'K' => {
            let a = parse(s, idx, ass);
            let b = parse(s, idx, ass);
            return a && b;
        },
        'A' => {
            let a = parse(s, idx, ass);
            let b = parse(s, idx, ass);
            return a || b;
        },
        'N' => {
            return !parse(s, idx, ass);
        },
        'C' => {
            let a = parse(s, idx, ass);
            let b = parse(s, idx, ass);
            return !a || b;
        },
        'E' => {
            let a = parse(s, idx, ass);
            let b = parse(s, idx, ass);
            return a == b;
        },
        'p' => { return (ass & ((1 as i32) << 0)) > 0; }
        'q' => { return (ass & ((1 as i32) << 1)) > 0; }
        'r' => { return (ass & ((1 as i32) << 2)) > 0; }
        's' => { return (ass & ((1 as i32) << 3)) > 0; }
        't' => { return (ass & ((1 as i32) << 4)) > 0; }
        _   => println!("Something wrong!"),
    }
    true
}

fn main() {
    let stdin = io::stdin();
    for line in stdin.lock().lines().map(|l| l.unwrap()) {
        let char_vec: Vec<char> = line.chars().collect();
        let mut idx: usize;
        let mut res: bool = false;
        if char_vec[0] == '0' {
            return;
        }
        for i in 0..(((1 as i32) << 5)-1) {
            idx = 0;
            res = parse(&char_vec, &mut idx, i);
            if !res {
                println!("not");
                break;
            }
        }
        if res {
            println!("tautology")
        }
    }
}
