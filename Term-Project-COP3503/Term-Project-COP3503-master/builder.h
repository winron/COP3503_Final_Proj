//Richard Blake
//Myra Kurosu Jalil
//Alexander Scardina
//Winton Liu
//Abigail Halem
//Zachary Tsarnas
//Group Project
#include <climits>
#include "word.h"
#include "controller.h"

int menu();
controller *createSentence( int numNoun, int numAdj, int numVerb, int numAdv, controller *wordBank );
word *selectPunct( word *period, word *exclam, word *quest );
bool isPlural();
bool isVowel( word *word );
