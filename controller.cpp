/*
  This is the implementation for the class controller. All functions apart from the printing functions (toString and
  printSentence), each function takes a pointer to a word as its only parameter. Both addWord and deleteWord return
  an int. These functions return 1 if the operation was successful, and 0 if something went wrong. This can be helpful
  in debugging.
*/

#include "controller.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>

//implicit constructor for controller
controller::controller()
{
  head = nullptr;
  tail = nullptr;
}


int
controller::addWord( word *word )
{
  wordList *newItem = new wordList();

  //if the list is empty, use the newItem as the first and only item in the list
  if ( !head && !tail )
    {
      newItem->content = word;
      head = newItem;
      tail = newItem;
      return 1;
      
    }

  //if the list is not empty, add the newItem to the end of the list and make it the tail
  else
    {
      newItem->content = word;
      tail->next = newItem;
      tail = newItem;
      newItem->next = nullptr;
      return 1;
    }
  
  return 0;
}

int
controller::deleteWord( word *word )
{

  //searcher is set to the head of the list. searcherFollower will eventually point to the item behind searcher.
  wordList *searcher = head;
  wordList *searcherFollower = head;

  //if the list is empty, return 0 to indicate operation failure
  if ( !head && !tail )
    return 0;

  /* if the word passed to the function is equal to the first item in the list, delete it and make the second list item
     the new head */
  else if ( word == head->content )
    {
      wordList *temp = head;
      head = head->next;
      delete temp;
      return 1;
    }

  //if list is not empty, search for the word passed to the function and delete it. 
  if ( head && tail )
    {
      //this is where seacher is set to point to the item after searcherFollower.
      searcher = searcher->next;
      while ( searcher )
	{
	  if ( searcher->content == word )
	    {
	      searcherFollower->next = searcher->next;
	      delete searcher;
	      return 1;
	    }
	  searcher = searcher->next;
	  searcherFollower = searcherFollower->next;
	   
	}
    }
  return 0;
}

word*
controller::findWord( int index )
{

  wordList *searcher = head;

  if ( index < 1 )
    return nullptr;

  for ( int i = 0; i < index - 1; ++i )
    {
      searcher = searcher->next;
    }
  
  return searcher->content;
  
}

void
controller::toString()
{
  wordList *n = head;
  int count = 1;

  if ( !head && !tail )
    std::cout << "{ empty list }" << std::endl;

  else
    {
      while ( n )
	{
	  
	  std::cout << count << ": " << n->content->content << ": " << n->content->typeOfWord << std::endl;
	  n = n->next;
	  ++count;
	}
     
    }
}

void
controller::printSentence()
{
  wordList *n = head;

  if ( !head && !tail )
    std::cout << "{ empty list }" << std::endl;

  else
    {
      while ( n )
	{	 
	  std::cout << n->content->content << " ";
	  n = n->next;
	}
      std::cout << std::endl;
    }
}


void
controller::makeWordBank( std::ifstream &file )
{

  std::string str;
  word *currentword;
  
  while ( std::getline( file, str ) && str != "" )
    {
      currentword = new word( "verb", str );
      this->addWord( currentword );
    }

  while ( std::getline( file, str ) && str != "" )
    {
      currentword = new word( "noun", str );
      this->addWord( currentword );
    }

  while ( std::getline( file, str ) && str != "" )
    {
      currentword = new word( "adjective", str );
      this->addWord( currentword );
    }

  while ( std::getline( file, str ) && str != "" )
    {
      currentword = new word( "adverb", str );
      this->addWord( currentword );
    }

  while ( std::getline( file, str ) && str != "" )
    {
      currentword = new word( "preposition", str );
      this->addWord( currentword );
    }

  while ( std::getline( file, str ) && str != "" )
    {
      currentword = new word( "conjunction", str );
      this->addWord( currentword );
    }
      
}

word*
controller::findTypeOfWord( std::string typeOfWord )
{

  
  
  int randnum = 0;
  
  if ( !head && !tail )
    return nullptr;

  if ( typeOfWord == "verb" )
    {
      randnum = (rand() % 87) + 1;
    }

  if ( typeOfWord == "noun" )
    {
      randnum = (rand() % 99) + 88;
    }

  if ( typeOfWord == "adjective" )
    {
      randnum = (rand() % 47) + 188;
    }
  
  if ( typeOfWord == "adverb" )
    {
      randnum = (rand() % 68) + 236;
    }
  
  if ( typeOfWord == "preposition" )
    {
      randnum = 305;
    }
  
  if ( typeOfWord == "conjunction" )
    { 
      randnum = (rand() % 2) + 306;
      //std::cout << randnum;
    }

  //std::cout << randnum << std::endl;

  return findWord( randnum );
     

}
