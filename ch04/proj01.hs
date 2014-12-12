{-  proj01 part I find the number of r-permutation
 -  by Yue Wang
 - -}
rPermutation :: (Num a, Enum a) => a -> a -> a
rPermutation n r = product (reverse [n-r+1..n])
 
