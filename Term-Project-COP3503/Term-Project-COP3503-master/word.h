/*
  This file includes the declaration for word. This will likely be the only
  class in the project that #includes string. word.h also defines a struct
  wordList in order to be used by the controller. The controller is a linked
  list implementation. The controller lists will be used as word banks,
  constituents pairs, full sentences etc.
 */

#ifndef WORD_H_
#define WORD_H_
#include <string>

class word
{
 public:

  //word member variables
  std::string typeOfWord;
  std::string content;

  //word member functions
  std::string getTypeOfWord();
  word( std::string typeOfWord, std::string content );

};

//wordList struct. These objects will be used by the controller in lists
struct wordList
{
  word *content;
  wordList *next;
};






#endif // WORD_H_
