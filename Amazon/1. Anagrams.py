# You are given set of strings, You have return anagrams subsets from it.
# An anagram set is that one where every string is an anagram of another string.
# If the subset contains only one string, don't include that in the result.

# If i understand correctly -
# String[] str = {"cat","dog","ogd","act","tca","ofg"}; is given
# and the o/p -
# dog ogd
# cat act tca
# ofg
#
# There could be two ways to solve this question-
#
# 1- Create an auxilary array of same strings.
# 2- Sort the words in side the auxaliry array, Hence in our example - auxilary_array after sorting will be like
# {"act","dog","dog","act","act","fgo"}
# 3- create a hashmap with <string,Arraylist>, and put auxilary_array values as key and i/p array value as values.
#
# Hence new result hashmap will be like -
# act -> cat,act,tca
# dog -> dog,ogd
# fgo- > ofg
#
# print all the values from hashmap
#
# Problem with this approach are-
# 1- Extra space for the auxilary array
# 2- Time complxety will be n*klogk , where n is size of array of string and k is the maximum character word in array
#
# Not a good approach
#
# Second approach -
#
# Why not we create a hashmap of the each words and then compare and add to the map for final result, But the problem is that what will you take as key of map.
# words ? Not good , act and cat will be different keys
# ASCII addition/multiplication of character in words ? There might be possible cases when you can get same values for different words. Not good
#
# So if we write our own hasvalue function that will provide always unique values for words, but same for the anagrams , Then our problem can be solved.
#
# Here is the way to write such type of hashfunction -
#
# 1- Create an array of size equals to unique character in i/p string, and assign a prime number for all chars.
# We use english alphabates then there will be 26 char.
#
# public static int[]
# hash = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
# // 26 prime numbers
#
# 'a' will be mapped with first element of the array and 'z' with last. No uppercase
#
# Below is working code
from Mathematics.PrimeNumber.Prime import Prime


def get_hash(word):
    hash = Prime.get_first_n_prime(26)
    result = 1

    for i in range(len(word)):
        result = result * hash[ord(word[i])-97]

    return result


def print_dict(distionaty):
    for v in distionaty:
        for word in distionaty[v]:
            print(word, end=" ")
        print("")


def find_same_anagram(str):
    distionaty = dict()

    for word in str:
        key = get_hash(word)

        if key in distionaty:
            distionaty[key].append(word)
        else:
            distionaty[key] = [word]



    print_dict(distionaty)

str = {"cat","dog","ogd","act","tca","ofg"}
find_same_anagram(str)