catalan 0 = 1
catalan x = sum [(catalan i) * (catalan (x - 1 - i)) | i <- [0..x-1] ]

catalan' 0 = 1
catalan' n =
    let prevcatalans = take n catalans
    in sum $ zipWith (*) prevcatalans (reverse prevcatalans)
catalans = map catalan' [0..]

fibs :: [Integer]
fibs = 0 : 1 : zipWith (+) fibs (tail fibs)
fib :: Int -> Integer
fib n = fibs !! n 

main = do
    i <- getContents
    let t1 = (fmap read (lines i)) :: [Int]
    let out = fmap (catalans !!) (tail t1) :: [Integer]
    mapM_ print out
