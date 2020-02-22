#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstdio> 
std::fstream read;
std::fstream save;

std::vector < std::string > dictionary;
std::vector < std::string > firstWords;

std::string slowo;

int greatest = 0;
int cl;
int tab[26];
char button;

char shiftLetter(char letter, int shift) {
    if (letter >= 65 && letter < 91) {
        cl = 65;
    } else if (letter >= 97 && letter < 123) {
        cl = 97;
    } else {
        return letter;
    }

    return((letter - cl + shift) % 26) + cl;
}
void begin(void) {
    std::string word;
    read.open("default.dic", std::ios:: in);
    if (read.good() == 1) {
        while (!read.eof()) {
            getline(read, word);
            dictionary.push_back(word);
        }
        read.close();
    }
}
bool inDictionary(std::string word) {
    int size = dictionary.size();
    for (int i = 0; i < size; i ++) {
        if (dictionary[i] == word) {
            return 1;
        }
    }
    return 0;
}
int pickGreatest(void) {
    int igr;
    for (int i = 0; i < 26; i ++) {
        if (tab[i] > greatest) {
            greatest = tab[i];
            igr = i; 
        }
    }
    return igr;
}
std::string format(std::string line) 
{
    int size;
    std::transform(line.begin(), line.end(), line.begin(),::tolower);
    size = line.size();
    for (int i = 0; i < size; i ++) 
        {
            if ((line[i] >= 32 && line[i] < 65) || (line[i] >= 91 && line[i] < 97)) 
            {
                line[i] = ' ';
            } 
            else 
            {
                line[i] = line[i];
            }

    }
    return line;
}
void loadToTemp(int x) 
{
    std::string line;
    int i = 0;
    read.open("input.txt", std::ios:: in);
    save.open("temp.txt", std::ios::out);
    if (read.good() == 1) 
    {
        while (i < x) 
        {
            getline(read, line);
            save << format(line);
            if(i!=x-1)
            {
                save << std::endl;
            }
            i ++;
        }
        read.close();
        save.close();
    }



    int y=1;
    i=0;
    read.open("temp.txt", std::ios::in);
    save.open("temp2.txt", std::ios::out);
    if(read.good()==1)
    {
        while(!read.eof())
        {
            getline(read, line); 
            for(int i=0; i<line.size(); i++)
            {
                if(line[i] != ' ')
                {
                    save<<line[i];
                    y=1;
                }
                else if(y==1)
                {
                    save<<std::endl;
                    y=0;
                }     
            }
            if(i != x-1 && y==1)
            {
            save<<std::endl;
            y=0;
            }
            i++;
        }
    }
    read.close();
    save.close();
}
void loadToVector(void) 
{
    std::string line;
    read.open("temp2.txt", std::ios::in);
    if(read.good()==1)
    {
        while(!read.eof())
        {
            getline(read,line);
            firstWords.push_back(line);     
        }
    }
    read.close();
}
void usunTo()
{
    remove("temp.txt");
    remove("temp2.txt");
}
std::string shiftWord(std::string word, int x) //działa
{
    std::string shiftedWord; 
    shiftedWord=word;
    for(int i=0; i<word.size(); i++)
    {
        shiftedWord[i]=shiftLetter(word[i], x);
    }
    return shiftedWord; 
}
