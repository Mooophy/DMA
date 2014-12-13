{-  
 -  By Yue Wang 13.12.2014
 -
 -  proj01 find the largest in a list of integers
 -
 - -}

maximum' :: (Ord a) => [a] -> a
maximum' [x]    =   x
maximum' (x:xs) =   if x > rest  then x else rest 
                    where rest = maximum' xs
