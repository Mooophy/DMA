{-
 - By Yue Wang 14.12.2014
 - proj10 is prime?
 --}
isPrime :: Int -> Bool
isPrime num
    | num < 2    =  False
    | otherwise  =  check num (div num 2)
    where   check num checker 
                | checker == 1  =  True
                | otherwise     =  0 /= mod num checker  &&  check num (checker-1)



--test:
func x = if x then "prime" else "non prime"
seq' = [195..200]
main = do   print(seq')
            print(map func (map isPrime seq'))
-- output : 
-- [195,196,197,198,199,200]
-- ["non prime","non prime","prime","non prime","prime","non prime"]
