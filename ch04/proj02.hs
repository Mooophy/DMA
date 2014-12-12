{- by Yue Wang 12.12.2014 implemented for ch04 DMA
 - proj02
 - Given n and r, find the number of r-permutations and r-combinations when repetition is allowed
 - -}


rPermutation::(Integral a) => a -> a -> a 
rPermutation n r = n^r

