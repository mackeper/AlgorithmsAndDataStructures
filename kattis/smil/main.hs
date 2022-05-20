solve :: [Int] -> Int -> [Char] -> [Int]
solve result index [] = result
solve result index (':' : ')' : rest) = solve (index:result) (index+2) rest
solve result index (';' : ')' : rest) = solve (index:result) (index+2) rest
solve result index (':' : '-' : ')' : rest) = solve (index:result) (index+3) rest
solve result index (';' : '-' : ')' : rest) = solve (index:result) (index+3) rest
solve result index (_:rest) = solve result (index+1) rest

main :: IO ()
main = interact (unlines . map show . reverse . solve [] 0)