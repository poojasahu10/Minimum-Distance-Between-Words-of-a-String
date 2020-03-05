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
            map_words.insert(pair<string, list<int>>(word, l) );
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

void main()
{
    string novel = "geeks for geeks contribute practice geeks practice";
    string word1 = "geeks";
    string word2 = "practice";
    int min_dist = INT_MAX;

    /* Store each word in a unordered_map as key and its indexes as list.
    The same unordered_map could be used for min word search iteratively for different 
    word input*/ 
    unordered_map<string, list<int>> map_words = CreateWordMap(novel);
    cin >> word1;
    cin >> word2;
    list<int> list_word1 = map_words.find(word1)->second;
    list<int> list_word2 = map_words.find(word2)->second;
    list<int> ::iterator itr1 = list_word1.begin();
    list<int> ::iterator itr2 = list_word2.begin();


    while ((itr1 != list_word1.end()) && (itr2 != list_word2.end()))
    {
        
        int diff = 0;
        if (*itr1 < *itr2)
        {
            itr1 = GetClosestElement(itr1, list_word1.end(),*itr2);
            diff = (abs(*itr2 - *itr1) - 1);
            ++itr1;
        }
        else
        {
            itr2 = GetClosestElement(itr2, list_word2.end(),*itr1);
            diff = (abs(*itr2 - *itr1) - 1);
            ++itr2;
        }
        if (min_dist > diff)
            min_dist = diff;
    }
    cout << "Word count  : " << min_dist;

}