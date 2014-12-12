-- proj01 part I find the number of r-permutations
rPermutations :: (Num a, Enum a) => a -> a -> a
rPermutations n r = product (reverse [n-r+1..n])
-- proj01 part II find the number of r-combinations
-- problem : this code caused float output..need fix later on
rCombinations :: (Fractional a, Eq a) =>  a -> a -> a
rCombinations n r = fac n/((fac r) * fac(n-r))
    where fac x = if x==0 then 1 else x * fac(x-1)

