sodaCount a b
    | a < b   = 0
    | otherwise = (sodaCount ((a `mod` b) + (a `div` b)) b) + (a `div` b)

starter [a, b, c] = sodaCount (a+b) c

main = do
    i <- getLine
    let t = (fmap read (words i)) :: [Int]
    print (starter t)
