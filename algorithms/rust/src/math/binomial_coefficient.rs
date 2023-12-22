pub fn binomial_coefficient(n: u64, k: u64) -> u64 {
    let mut result = 1;
    for i in 0..k {
        result *= n - i;
        result /= i + 1;
    }
    result
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn binomial_coefficient_5_2() {
        let result = binomial_coefficient(5, 2);
        assert_eq!(result, 10);
    }

    #[test]
    fn binomial_coefficient_10_5() {
        let result = binomial_coefficient(10, 5);
        assert_eq!(result, 252);
    }

    #[test]
    fn binomial_coefficient_10_0() {
        let result = binomial_coefficient(10, 0);
        assert_eq!(result, 1);
    }

    #[test]
    fn binomial_coefficient_10_10() {
        let result = binomial_coefficient(10, 10);
        assert_eq!(result, 1);
    }

    #[test]
    fn binomial_coefficient_100_0() {
        let result = binomial_coefficient(100, 0);
        assert_eq!(result, 1);
    }
}
