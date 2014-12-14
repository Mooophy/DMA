--proj03 given num n find 1 + 2 +..+n
sum' :: Integer -> Integer
sum' x 
    | x <  0    = error "input less than 0"
    | x == 0    = 0
    | otherwise = x + sum' (x-1)


main = do print(map sum' [1..10])
--output:
--[1,3,6,10,15,21,28,36,45,55]

