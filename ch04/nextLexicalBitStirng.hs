{-  for ch04 DMA
 -  by Yue Wang
 - -}
nextLexicalBitStirng :: (Num a, Eq a) =>  [a] -> [a]
nextLexicalBitStirng []     =   []
nextLexicalBitStirng xs     =   if head rxs==0  then reverse(1:(tail rxs))  else nextLexicalBitStirng(take (length xs - 1) xs) ++ [0]
                                where rxs = reverse xs
