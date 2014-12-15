--
--merge sort in Haskell 
--by Yue Wang 15.12.2014
--
mergeSort :: (Ord a) => [a] -> [a]
mergeSort [] = []
mergeSort [x]= [x] -- <--the termination condition!
mergeSort xs = merge (mergeSort(fst pair)) (mergeSort(snd pair)) 
    where  pair = splitAt ( (length xs) `div` 2 ) xs
           merge ls []         = ls
           merge [] rs         = rs
           merge ls@(l:lt) rs@(r:rt)
             | l <= r          = l : merge lt rs
             | otherwise       = r : merge ls rt 




li = [100,99..90]
main = do print li
          print (mergeSort li)
--output:	
--[100,99,98,97,96,95,94,93,92,91,90]
--[90,91,92,93,94,95,96,97,98,99,100]
