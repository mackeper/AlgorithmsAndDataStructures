use regex::Regex;

#[allow(dead_code)]
fn get_first_and_last_digit_part1(line: &str) -> u32 {
    let mut first = Option::None;
    let mut last = Option::None;

    for c in line.chars() {
        if c.is_digit(10) {
            if first.is_none() {
                first = Some(c.to_digit(10).unwrap());
            }
            last = Some(c.to_digit(10).unwrap());
        }
    }

    match (first, last) {
        (Some(first), Some(last)) => first * 10 + last,
        _ => panic!("No digits found in line: {}", line),
    }
}

fn get_first_and_last_digit_part2(line: &str) -> u32 {
    let regex = Regex::new(r"(\d|one|two|three|four|five|six|seven|eight|nine)").unwrap();
    let matches = regex
        .find_iter(line)
        .map(|m| m.as_str())
        .collect::<Vec<&str>>();

    println!("line: {}", line);
    println!("matches: {:?}", matches);

    let first_match = matches.first().unwrap();
    let last_match = matches.last().unwrap();

    fn get_digit_from_match(m: &str) -> u32 {
        match m {
            "one" => 1,
            "two" => 2,
            "three" => 3,
            "four" => 4,
            "five" => 5,
            "six" => 6,
            "seven" => 7,
            "eight" => 8,
            "nine" => 9,
            _ => m.parse::<u32>().unwrap(),
        }
    }

    let first = Some(get_digit_from_match(first_match));
    let last = Some(get_digit_from_match(last_match));

    println!("first: {:?}", first);
    println!("last: {:?}", last);
    println!();

    match (first, last) {
        (Some(first), Some(last)) => first * 10 + last,
        _ => panic!("No digits found in line: {}", line),
    }
}

fn main() {
    let lines = std::io::stdin()
        .lines()
        .map(|line| get_first_and_last_digit_part2(&line.unwrap()))
        .collect::<Vec<u32>>();

    println!("{}", lines.iter().sum::<u32>());
}
