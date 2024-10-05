/***************************************************************************************************************************

Name: Barrett Bobilin
Assignment: word checker aka stringstats
Due Date: 4/11/2024
About this project: enters a sentence and a word, then checks to see if word is in sentence
Assumptions: the sentence the user enters will have only exactly one whitespace between each word
             anytime the user is prompted to enter only one word, that they will do so

All work below was performed by Barrett Bobilin


***************************************************************************************************************************/
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>

using namespace std;



bool isWordInSentence(const char * sentence, const char * word);
void analyzeSentence(const char * sentence, const char * word);
int countPunctuation(const char * sentence);
int countVowels(const char * sentence);

int main()
{
    char sentence[100];
    char word[20];
    string repeat;

    do {
        cout << "Enter a sentence: ";
        cin.getline(sentence, sizeof(sentence));

        cout << "Enter a word: ";
        cin >> word;
        cin.ignore(); 

        analyzeSentence(sentence, word);

        cout << "\nEnter another sentence/word for analysis (yes/no): ";
        cin >> repeat;
        cin.ignore(); 

        //convert variable "repeat" to lowercase so i dont have to check a bunch of different cases
        for (int i = 0; i < repeat.length(); i++)
        {
            repeat[i] = tolower(repeat.at(i));
        }

        //repeat until the user inputs no
    } while (repeat == "yes");

    return 0;
}



bool isWordInSentence(const char * sentence, const char * word) 
{
    while (*sentence) 
    {
        const char * s = sentence;
        const char * w = word;
        while (* s && * w && *s == * w) 
        {
            s++;
            w++;
        }
        if (!*w) return true; //if (*w) return false;
        sentence++;
    }
    return false;
}

void analyzeSentence(const char * sentence, const char * word)
{
    int wordLengths[21] = {0}; 
    int wordCount = 0;
    
    
    for (int i = 0; sentence[i] != '\0'; i++) 
    {
        if((isspace(sentence[i]) == 0)) // && (isspace(sentence[i + 1]) || sentence[i + 1] == '\0'))) 
        {
            wordCount++;
        }

        
        int length = 0;
        while (!isspace(sentence[i]) && sentence[i] != '\0') 
        {
            length++;
            i++;
        }
       
        if (length <= 20)
            wordLengths[length]++;
    }

    
    cout << "\nSENTENCE ANALYSIS:\n";
    cout << "Punctuation Characters: " << countPunctuation(sentence) << endl;
    cout << "Vowels: " << countVowels(sentence) << endl;
    cout << "Words: " << wordCount << endl << endl;

    cout << "Word Length: \n";
    for (int i = 1; i < 21; ++i) 
    {
        if (wordLengths[i] > 0) 
        {
            cout << i << " character(s) long word: " << wordLengths[i] << " word" << endl;
        }
    }

    if (isWordInSentence(sentence, word)) 
    {
        cout << "\nThe word: " << word << " IS a part of the sentence you entered.\n";
    } 
    else 
    {
        cout << "\nThe word: " << word << " IS NOT part of the sentence you entered.\n";
    }
}


int countPunctuation(const char* sentence) 
{
    int punctuation = 0;
    for(int i = 0; sentence[i] != '\0'; i++)
    {
        if(ispunct(sentence[i]))
        {
            punctuation++;
        }
    }
    return punctuation;
}

int countVowels(const char * sentence) 
{
    int vowel = 0;
    for(int i = 0; sentence[i] != '\0'; i++)
    {
        // im so sorry...but this is the vowel counter
        if(sentence[i] == 'A' || sentence[i] == 'a' || sentence[i] == 'E' || sentence[i] == 'e' || sentence[i] == 'I' || sentence[i] == 'i' || sentence[i] == 'O' || sentence[i] == 'o' || sentence[i] == 'U' || sentence[i] == 'u' || sentence[i] == 'Y' || sentence[i] == 'y')
        {
            vowel++;
        }
    }
    return vowel;
}



