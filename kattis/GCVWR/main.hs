solve (g:t:n:ns) = (round ((fromIntegral (g - t)) * 0.9)) - (sum ns)

main = interact (show . solve . map read . words)