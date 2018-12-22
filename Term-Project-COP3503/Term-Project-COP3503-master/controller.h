/*
  This is the declaration for the class controller. it includes 2 member variables: head and
  tail. These members point to struct wordList objects. They will control the singly-linked
  list. Currently, there are 5 member functions, which perform fundamental list operations
  such as add, delete, and find. There are 2 print functions. The toString function is to 
  print the details of each word in the wordList; the content of the word followed by the type
  of word. The printSentence functon prints a list's words from head to tail.
*/

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "word.h"


class controller
{
 public:
  //constructor
  controller();
  
  //member variables
  wordList *head;
  wordList *tail;
  
  //member functions
  int addWord( word *word );
  int deleteWord( word *word );
  word * findWord( int index );
  word * findTypeOfWord( std::string content );
  void makeWordBank( std::ifstream &file );
  void toString();
  void printSentence();
  
};

#endif //CONTROLLER_H_
