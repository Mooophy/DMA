-- by Yue Wang 12.12.2014 coded for ch04 DMA
-- proj01  find the number of r-permutations and of r-combinations
rPermutations :: (Num a, Enum a) => a -> a -> a
rPermutations n r = product (reverse [n-r+1..n])

rCombinations :: (Fractional a, Eq a) =>  a -> a -> a   -- this output float number, need to fix later on
rCombinations n r = fac n/((fac r) * fac(n-r))
    where fac x = if x==0 then 1 else x * fac(x-1)

