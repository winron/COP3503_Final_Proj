/* 
   Both word.cpp and word.h are simple, only having 2 members. Both members
   are of type string. When creating a word, the explicit constructor must be 
   called. word has a getter function that returns the caller's typeOfword.
 */
#include "word.h"

//explicit word constructor (must call explicit constructor)
word::word( std::string typeOfWord, std::string content )
{
  this->typeOfWord = typeOfWord;
  this->content = content;
}

//returns a given word's type of word
std::string
word::getTypeOfWord()
{
  return this->typeOfWord;
}


