next :: [Bool] -> [Bool]
next [] = []
next xs         
    | last xs == True   =   next firstPart ++ [False]
    | otherwise         =        firstPart ++ [True]  
    where firstPart = take (length xs - 1) xs
