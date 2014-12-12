{- by Yue Wang 12.12.2014 implemented for ch04 DMA
 - proj02
 - Given n and r, find the number of r-permutations and r-combinations when repetition is allowed
 - -}


rPermutationsRepetition::(Integral a) => a -> a -> a 
rPermutationsRepetition n r = n^r


--theorem 2 : C(n+r-1,r)    i.e. (n+r-1)!/r!*(n-1)!
rCombinations :: (Fractional a, Eq a) =>  a -> a -> a
rCombinations n r = fac(n+r-1)/((fac r) * fac (n-1))
    where fac x = if x==0 then 1 else x * fac(x-1)
