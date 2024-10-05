#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    
    char sentence[100], word1[15], word2[15];
    int upper, lower;
    upper = lower = 0;
    bool thesame = true;
    
    cout << "enter a sentence > ";
    cin.getline(sentence, 100);
    cout << "enter 2 words > ";
    cin >> word1 >> word2;
    
    //cout << sentence << endl << word1 << word2 << endl;
    
    for(int i = 0; i < strlen(sentence); i++)
    {
        if(isupper(sentence[i]) != 0  )
            upper++;
        
        if(islower(sentence[i]) != 0)
            lower++;
    }
    
    cout << "uppercase = " << upper << endl << "lower = " << lower << endl;
    
    if (strcmp(word1,word2) == 0)
    {
        cout << "same" << endl;
    }
    else
        cout << "different" << endl;
        
    for(int i = 0; i < strlen(word1); i++)
    {
        if(word1[i] != sentence[i])
            thesame = false;
    }

    if(thesame == true)
        cout << word1 << " begins the sentence" << endl;
        

    return 0;
}
