{-
 - By Yue Wang 14.12.2014
 - proj11 encrypt and decrypt using Caesar cipher
 --}
import Data.Char

encrypt :: [Char] -> Int -> [Char]
encrypt msg offset = map enc msg
    where enc c = chr(mod (ord c + offset) 255)

decrypt :: [Char] -> Int -> [Char]
decrypt msg offset = map dec msg
    where dec c = chr(mod (ord c - offset) 255)


--test:
sonnet = "From fairest creatures we desire increase"
e = encrypt sonnet  3
d = decrypt e       3
main = do   print sonnet
            print e
            print d
--output:
--"From fairest creatures we desire increase"
--"Iurp#idluhvw#fuhdwxuhv#zh#ghvluh#lqfuhdvh"
--"From fairest creatures we desire increase"
