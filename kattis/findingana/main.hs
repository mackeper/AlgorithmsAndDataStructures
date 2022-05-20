findA :: [Char] -> [Char]
findA [] = []
findA (x:xs)
    | x == 'a' = x:xs 
    | otherwise = findA xs

main :: IO ()
main = interact findA