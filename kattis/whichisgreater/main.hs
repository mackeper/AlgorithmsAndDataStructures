comp :: [Int] -> Int
comp (a:b:_)
    | a > b = 1
    | otherwise = 0

main :: IO ()
main = interact (show . comp . map read . words)