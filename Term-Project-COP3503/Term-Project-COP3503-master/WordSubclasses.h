/*
 * This is the declaration of the subclasses of word:  noun, verb, adjective, adverb, conjunction and preposition. 
 */

#ifndef PROJECT_WORDSUBCLASSES_H
#define PROJECT_WORDSUBCLASSES_H

#include <string>
#include "word.h"

class Noun:public word{
public:
    //constructor
    Noun(std::string typeOfWord,std::string content):word(typeOfWord,content){}
    
    //makes nouns plural
    std::string makeNounPlural(std::string noun);
};

class Verb:public word{
public:
    //constructor
    Verb(std::string typeOfWord,std::string content):word(typeOfWord,content){}
    
    //the following methods conjugate verbs in the past tense
    std::string makeVerbPast(std::string verb);
    std::string makeVerbPastWithVowel(std::string verb);
};

class Adjective:public word{
public:
    //constructor
    Adjective(std::string typeOfWord,std::string content):word(typeOfWord,content){}
};

class Adverb:public word{
public:
    //constructor
    Adverb(std::string typeOfWord,std::string content):word(typeOfWord,content){}
};

class Conjunction:public word{
public:
    //constructor
    Conjunction(std::string typeOfWord,std::string content):word(typeOfWord,content){}
};

class Preposition:public word{
public:
    //constructor
    Preposition(std::string typeOfWord,std::string content):word(typeOfWord,content){}
};

#endif //PROJECT_WORDSUBCLASSES_H
