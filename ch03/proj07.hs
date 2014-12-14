-- proj0t reverse a list
reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x:xs) = reverse' xs ++ [x]


main = do   print (reverse' "hello world")
            print (reverse' "")
