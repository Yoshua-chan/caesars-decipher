#include <iostream>
#include "header.h"

int main() 
{
    
    std::string word;
    int k=0;
    int key;

    begin();
    loadToTemp(5);
    loadToVector();
    usunTo();
    
    for(int i=0; i<26; i++) //iteracja po kluczu
    {
        k=0;
        for(int j=0; j<firstWords.size(); j++) //iteracja po wektorze
        {
            word=firstWords[j];
            word=shiftWord(word,i);
            if(inDictionary(word)==1)
            {
                k++;
            }
        }
        tab[i]=k;
    }
    
    key=pickGreatest();
    
    std::cout<<"Most probable key: "<<key<<std::endl;
    std::cout<<"English words: "<<greatest<<" out of "<<firstWords.size()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"FINAL OUTPUT: "<<std::endl<<std::endl;

    read.open("input.txt", std::ios::in);
    save.open("output.txt", std::ios::out);
    if(read.good()==1)
    {
        while(!read.eof())
        {
            getline(read,word);
            std::cout<<shiftWord(word, key)<<std::endl;
            save<<shiftWord(word, key)<<std::endl;
        }
    }
    save.close();
    read.close();
    
    return 0;
}
