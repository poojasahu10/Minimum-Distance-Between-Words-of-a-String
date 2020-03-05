Given a big chunk of string data or a book stored in s , the task is to count the the minimum count of words between two given words(w1 and w2).
Chunk of data : Paragraphs are the building blocks of papers

Input : s = “Paragraphs are the building blocks of papers” w1 = “are”, w2 = “the”
Output : 0
There is no word between “are” and “the”. They both occur together.

Input s = “Paragraphs are the building blocks of papers” w1 = “Paragraphs”, w2 = “the”
Output : 1
There is a word “are” in between “Paragraphs” and “the”

An approach to the above problem statement when count search is to be done recursively on the same chunk of string instead of going through the entire string every time is to organise the strings into data structure. Create a map of words in the string as key and store the indices of the words into the list in sorted way.

Explanation :
s = “Paragraphs are building blocks of papers. Paragraphs are formed of multiple sentences”
The above string shall be arranged in a map with words as key and list of indices of the word.
{
Paragraphs : [0,6]
are : [1,7]
building : [2]
blocks : [3]
of : [4,9]
papers : [5]
formed : [8]
multiple : [10]
sentences : [11]
}

We will use the above map to find the count of minimum number of words :
For example : w1=”Paragraphs”, w2=”of”, minimum count is 2. We will get the list of indices for “Paragraphs” and “of” and get the minimum difference of the indices.

The below example gets minimum count without going through the whole string in each iteration.

Example :

Enter the words
terms
length
Word count : 1
Continue for next set of words?
Press Y or y for yes
Y
Enter the words
geeks
practice
Either of words not in the list
Continue for next set of words?
Press Y or y for yes
Y
Enter the words
least
sentences
Word count : 1
Continue for next set of words?
Press Y or y for yes
n or N for no