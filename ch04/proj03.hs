next :: [Bool] -> [Bool]
next [] = []
next xs = if last xs==True then next(init xs) ++ [False] else init xs ++ [True]          
    


