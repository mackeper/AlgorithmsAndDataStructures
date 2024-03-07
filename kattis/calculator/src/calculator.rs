#[derive(Debug, PartialEq)]
enum Operator {
    Add,
    Subtract,
    Multiply,
    Divide,
}

#[derive(Debug, PartialEq)]
enum Token {
    Number(i64),
    Operator(Operator),
    ClosingParenthesis,
    OpeningParenthesis,
}

fn parse_expression(expression: &str) -> Vec<Token> {
    let mut tokens = Vec::new();
    let mut number = String::new();

    let push_number = |tokens: &mut Vec<Token>, number: &mut String| {
        if !number.is_empty() {
            tokens.push(Token::Number(number.parse().unwrap()));
            number.clear();
        }
    };

    for c in expression.chars() {
        match c {
            '0'..='9' => number.push(c),
            '+' => {
                push_number(&mut tokens, &mut number);
                tokens.push(Token::Operator(Operator::Add));
            }
            '-' => {
                if number.is_empty() {
                    // Negative number
                    number.push(c);
                } else {
                    push_number(&mut tokens, &mut number);
                    tokens.push(Token::Operator(Operator::Subtract));
                }
            }
            '*' => {
                push_number(&mut tokens, &mut number);
                tokens.push(Token::Operator(Operator::Multiply));
            }
            '/' => {
                push_number(&mut tokens, &mut number);
                tokens.push(Token::Operator(Operator::Divide));
            }
            '(' => {
                push_number(&mut tokens, &mut number);
                tokens.push(Token::OpeningParenthesis);
            }
            ')' => {
                push_number(&mut tokens, &mut number);
                tokens.push(Token::ClosingParenthesis);
            }
            _ => {}
        }
    }
    push_number(&mut tokens, &mut number);
    tokens
}

fn evaluate_tokens(tokens: &[Token]) -> i64 {
    let mut stack = Vec::new();
    for (i, token) in tokens.iter().enumerate() {
        match token {
            Token::Number(n) => stack.push(*n),
            Token::Operator(op) => {
                let right = stack.pop().unwrap();
                let left = stack.pop().unwrap();
                let result = match op {
                    Operator::Add => left + right,
                    Operator::Subtract => left - right,
                    Operator::Multiply => left * right,
                    Operator::Divide => left / right,
                };
                stack.push(result);
            }
            Token::OpeningParenthesis => {
                stack.push(evaluate_tokens(&tokens[i + 1..]));
            }
            Token::ClosingParenthesis => break,
        }
    }
    stack.pop().unwrap()
}

/** Evaluate an expression and return the result.
 *  The expression is a string containing numbers, +, -, *, /, (, )
 *  Whitespace is ignored.
 */
pub fn evaluate_expression(expression: &str) -> i64 {
    let tokens = parse_expression(expression);
    evaluate_tokens(&tokens)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_parse_expression() {
        let expression = "(1+ 2)     * 3";
        let tokens = parse_expression(expression);
        assert_eq!(
            tokens,
            vec![
                Token::OpeningParenthesis,
                Token::Number(1),
                Token::Operator(Operator::Add),
                Token::Number(2),
                Token::ClosingParenthesis,
                Token::Operator(Operator::Multiply),
                Token::Number(3)
            ]
        );
    }
}
