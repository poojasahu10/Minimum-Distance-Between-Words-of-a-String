#include<iostream>
#include<string>
#include<sstream>
#include<climits>
#include <unordered_map>
#include<list>
#include<iterator>
using namespace std;
 
unordered_map<string, list<int>> CreateWordMap(string novel)
{
    unordered_map<string, list<int>> map_words;
    stringstream buff(novel);
    string word;
    int count = 0;
    while (buff >> word)
    {
        unordered_map < string, list<int> >::iterator itr = map_words.find(word);
        if (itr != map_words.end())
        {
            itr->second.push_back(count);
        }
        else
        {
            list<int> l;
            l.push_back(count);
            map_words.insert(pair<string, list<int>>(word, l));
        }
        count = count + 1;
    }
    return map_words;
}
 
list<int> ::iterator GetClosestElement(list<int> ::iterator begin, list<int> ::iterator end, int word_index)
{
 
    while ((begin != end) && (*begin < word_index))
    {
        ++begin;
 
    }
    return --begin;
}
 
int main()
{
 
   // Given the string, all the characters are lower cased without punctuation mark for extracting words from a string buffer
    string novel = "paragraphs are the building blocks of papers \
    many students define paragraphs in terms of length \
    a paragraph is a group of at least five sentences \
    a paragraph is half a page long etc In reality though the \
    unity and coherence of ideas among sentences is what constitutes a paragraph."
 
    // w1 and w2, between which the minimum count has to be calculated
    string word1 = "";
    string word2 = "";
 
    // Minimum value of the variable is initialized to MAX int value for 32 bit 
    int min_dist = INT_MAX;
    char choice = 'n';
 
     
    /* Store each word in a unordered_map as key and its indexes as list.
    The same unordered_map could be used for min word search iteratively for different
    word input*/
    unordered_map<string, list<int>> map_words = CreateWordMap(novel);
    do
    {
       // Input the words to calculate the minimum distance
        cout << "Enter the words" << endl;
        cin >> word1;
        cin >> word2;
 
        // Check if both the words exist in the map
        if ( (map_words.find(word1)!= map_words.end()) &&(map_words.find(word2)!= map_words.end()))
        {
            // Stores the list of indices of w1
            list<int> list_word1 = map_words.find(word1)->second;
            // Stores the list of indices of w2
            list<int> list_word2 = map_words.find(word2)->second;
            list<int> ::iterator itr1 = list_word1.begin();
            list<int> ::iterator itr2 = list_word2.begin();
 
 
            while ((itr1 != list_word1.end()) && (itr2 != list_word2.end()))
            {
 
                int diff = 0;
 
                // This is true when w1 occurs first and we need the next occurrence of w1 closest to w2 index
                if (*itr1 < *itr2)
                {
                    itr1 = GetClosestElement(itr1, list_word1.end(), *itr2);
                    diff = (abs(*itr2 - *itr1) - 1);
                    ++itr1;
                }
                else
                {
                    itr2 = GetClosestElement(itr2, list_word2.end(), *itr1);
                    diff = (abs(*itr2 - *itr1) - 1);
                    ++itr2;
                }
                if (min_dist > diff)
                    min_dist = diff;
            }
            cout << "Word count : " << min_dist<<endl;
        }
        else
        {
            cout << "Either of words not in the list" << endl;
        }
        cout << "Continue for next set of words?" << endl << "Press Y or y for yes" << endl;
        cin >> choice;
        min_dist = INT_MAX;
    } while ((choice == 'Y') || (choice == 'y'));
 
    return 0;
 
 
}