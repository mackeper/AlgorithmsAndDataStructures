import Data.List

maxRect :: Num a => [a] -> a
maxRect (a:_:c:_) = a * c
maxRect _ = 0

main :: IO ()
main = interact (show . maxRect . sort . map read . words)