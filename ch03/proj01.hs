--proj01 sum and product
sum' :: (Num a) => [a] -> a
sum' [] = 0
sum' (x:xs) = x + sum' xs


product' :: (Num a) => [a] -> a
product' [] = 1
product' (x:xs) = x * product' xs


--test:
li = [1,2,3,4,5]
main = do   print li
            print (sum' li)
            print (product' li) 
--output:
--[1,2,3,4,5]
--15
--120
