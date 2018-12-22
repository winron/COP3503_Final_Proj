//Richard Blake
//Myra Kurosu Jalil
//Alexander Scardina
//Winton Liu
//Abbigail Halem
//Zachary Tsarnas
//Group Project
#include "builder.h"
#include "controller.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
const int GENERATE_SENTENCE = 1;
const int MAD_LIBS = 2;
const int KNOCK_KNOCK = 3;
const int EXIT = 4;

int main() {
  int choice = 0; //an int is created to store the value of the menu function
  controller *wordBank = new controller();
  ifstream file( "word.txt" );
  wordBank->makeWordBank( file );
   
  do { //a do-while loop is created to run the menu function on loop 
    choice = menu(); //the choice int stores the value of the menu function
    switch(choice) { //a switch statement is generated that uses the int choice
    case GENERATE_SENTENCE:
      {

	//initializes important variables
	int chooseComp = 2;
	int sentType = 1;
	int numNoun = 1;
	int numAdj = 0;
	int numVerb = 1;
	int numAdv = 0;
	controller *sentence;
	

	//asks user if they would like to set up the number of nouns/ verbs in the sentence
	cout << "Would you like to set the number of components? \n1. Yes\n2. No\n";
	cout << "Input: ";
	cin >> chooseComp;
	//std::cout << "chooseComp = " << chooseComp;

	//checks validity of chooseComp
	while (cin.fail() || chooseComp < 1 || chooseComp > 2) {
	  cin.clear();
	  cout << "\nPlease input a valid number.";
	  cout << "\nWould you like to control the components? \n1. Yes\n2. No\n";
	  cout << "\nInput: ";
	  cin >> chooseComp;
	  cin.ignore(INT_MAX, '\n');
	}

	switch (chooseComp) {
	  //if user wants to set components
	case  1: {
	  //asks user if they want adjectives or adverbs
	  cout << "Do you want a basic sentence (1) or a colorful sentence (2)? ";
	  cin >> sentType;
	  //checks input validity
	  while (cin.fail() || sentType < 1 || sentType > 2) {
	    cin.clear();
	    cin.ignore(INT_MAX, '\n');
	    cout << "\nPlease input a valid number (1-2): ";
	    cin >> sentType;
	  }
		
	  //asks user for number of nouns
	  cout << "Please enter the number of nouns (1-3): ";
	  cin >> numNoun;
	  //checks input validity
	  while (cin.fail() || numNoun < 1 || numNoun > 3) {
	    cin.clear();
	    cin.ignore(INT_MAX, '\n');
	    cout << "\nPlease input a valid number (1-3): ";
	    cin >> numNoun;
	  }
	  //if colorful sentence, set numAdj equal to numNouns.
	  if (sentType == 2) {
	    numAdj = numNoun;
	  }
		
	  //asks user for number of verbs
	  cout << "Please enter the number of verbs (1-2): ";
	  cin >> numVerb;
	  //checks input validty
	  while (cin.fail() || numVerb < 1 || numVerb > 2) {
	    cin.clear();
	    cin.ignore(INT_MAX, '\n');
	    cout << "\nPlease input a valid number (1-2): ";
	    cin >> numVerb;
	  }
	  //if colorful sentence, set numAdv equal to numVerb.
	  if (sentType == 2) {
	    numAdv = numVerb;
	  }


	  //std::cout << numNoun << " " << numAdj << " " << numVerb << " " << numAdv << std::endl;
	  sentence = createSentence(numNoun, numAdj, numVerb, numAdv, wordBank); //generate sentence based on num of components
	  break;
	}
	
	  //if user wants to randomize number of components
	case 2 : {	
	  //srand(time(NULL));
	  numNoun = (rand() % 3) + 1; //generates num 1-3
	  numAdj = numNoun;
	  numVerb = (rand() % 2) + 1; //generates num 1-2
	  numAdv = numVerb;
	  sentence = createSentence(numNoun, numAdj, numVerb, numAdv, wordBank); //generates sentence based on num of components
	  break;
	}
	   

	}
	sentence->printSentence(); //prints out generated sentence
	break;
      }
      
    case MAD_LIBS:
      {	
	cout << "\nWelcome to the Mad Libs Game. Please select the corresponding integer to the categories below.";
	cout << "\n1. Holiday";
	cout << "\n2. UF";
	cout << "\n3. Mystery";
	cout << "\n\nChoice: ";
	int madchoice = 0;
	cin >> madchoice;

	//checks input validity
	while (cin.fail() || madchoice < 1 || madchoice > 3) {
	  cin.clear();
	  cin.ignore(INT_MAX, '\n');
	  cout << "\nPlease input a valid number (1-3): ";
	  cin >> madchoice;
	}

	string word1="";
	string word2="";
	string word3="";
	string word4="";
	string word5="";
	string word6="";

	if (madchoice == 1) {
	  cout << "\nPlease enter a place: ";
	  cin >> word1;
	  cout << "Please enter a noun: ";
	  cin >> word2;
	  cout << "Please enter a famous person(one word): ";
	  cin >> word3;
	  cout << "Please enter an adjective: ";
	  cin >> word4;
	  cout << "Please enter a noun: ";
	  cin >> word5;
	  cout << "Please enter another adjective: ";
	  cin >> word6;

	  cout << "\nYour Holiday Mad Lib";
	  cout << "\n--------------------";
	  cout << "\nIn the " << word1 << " we can build a " << word2;
	  cout << "\nThen pretend that he is " << word3;
	  cout << "\nHe'll say, \"Are you " << word4 << "?\"";
	  cout << "\nWe'll say, \"No man\"";
	  cout << "\nBut you can do the job, when you're in town";
	  cout << "\nLater on, we'll conspire";
	  cout << "\nAs we dream by the " << word5;
	  cout << "\nTo face unafraid, the plans that we've made";
	  cout << "\nWalking in a " << word6 << " wonderland\n";
        }

	else if (madchoice == 2){
          cout << "\nPlease enter an adjective: ";
	  cin >> word1;
	  cout << "Please enter a body part: ";
	  cin >> word2;
	  cout << "Please enter a large number: ";
	  cin >> word3;
	  cout << "Please enter a beverage: ";
	  cin >> word4;
	  cout << "Please enter an animal(plural): ";
	  cin >> word5;
	  cout << "Please enter a name: ";
	  cin >> word6;

          cout << "\nYour UF Mad Lib";
	  cout << "\n---------------";
	  cout << "\nDear prof Fuchs,"; 
	  cout << "\n\nI cannot make it to class this afternoon. I am very " << word1 << " and cannot stop";
	  cout << "\nscratching my " << word2 << " I have a fever of " << word3 << " degrees and the doctor ordered";
	  cout << "\nme to stay in bed and drink lots of " << word4 << ". Also, can I have a 2 day extension";
	  cout << "\non the essay about " << word5 << "? My dog ate it and now I have to start all over.";
	  cout << "\n\nBest wishes,";
	  cout << "\n" << word6 << "\n";
	}
	
        else if (madchoice == 3){
	  cout << "\nPlease enter a name: ";
	  cin >> word1;
	  cout << "Please enter another name: ";
	  cin >> word2;
	  cout << "Please enter an object: ";
	  cin >> word3;
	  cout << "Please enter a 3rd name: ";
	  cin >> word4;
	  cout << "Please enter an adjective: ";
	  cin >> word5;
	  cout << "Please enter a drink: ";
	  cin >> word6;

	  
	  cout << "\nYour Mystery Mad Lib";
	  cout << "\n--------------------";
	  cout << "\nHello. My name is Detective " << word1 << ". Supposedly, somebody stole the";
	  cout << "\ncookie from " << word2 << "'s " << word3 << ". So it now brings me to my first suspect.";
	  cout << "\nHis name is " << word4 << ". My proof is that he runs a shop down town called " << word4 << "'s";
	  cout << "\n" << word5 << " bottles of " << word6 << " ,was juggling supplies and stole the watermelon";
	  cout << "\nbecause he had an injured costumer.\n";
	}


      
	
     
      break;
    }
    case KNOCK_KNOCK:
      {
	srand( time ( NULL ) );
	string punchline = wordBank->findTypeOfWord( "noun" )->content;
	cout << "\nWelcome to the Knock Knock Joke. Please press enter to continue after each statement.";
	cin.ignore();
	cout << "\nKnock knock.";
	cin.ignore();
	cout << "\nWho's there?";
	cin.ignore();
	cout << punchline;
	cin.ignore();
	cout << punchline << " who";
	cin.ignore();
	cout << wordBank->findTypeOfWord( "adjective" )->content << " " <<  punchline << std::endl; //adj + noun
	break;
	//break;
      }
    case EXIT:
      break; //if the user selects 4, the while loop is stopped and the program ends
    }
  } while (choice != EXIT); //the loop stops when the user selects 4
  return 0;
}

//a menu function is created to display the menu that the user sees
int menu() {
  cout << "\nMenu: ";
  cout << "\n1. Generate random sentence";
  cout << "\n2. Mad libs mode";
  cout << "\n3. Knock knock joke";
  cout << "\n4. Exit";
  cout << "\n\nChoice: ";
    
  int input = 0; //an int is created to store the user's input
  cin >> input;
    
  //this while loop checks to see if the user input is valid
  //if the input is invalid, the input is cleared and the user is asked to give input again
  while (cin.fail() || input < 1 || input > 4) {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "\nPlease enter a valid number (1-4).";
    cout << "\nChoice: ";
    cin >> input;
  }
  return input; //the int 'input' is returned
}


controller*
createSentence(int numNoun, int numAdj, int numVerb, int numAdv, controller *wordBank ) {
  //initializes counters for the parts of speech
  srand ( time ( NULL ) );
  int verbCount = 0;
  //initializes the punctuations
  word *period= new word( "punct", "." );
  word *exclam= new word( "punct", "!" );
  word *quest= new word( "punct", "?" );
	
  bool plural = isPlural(); //calls bool method to determine if the sentence will use singular or plural nouns.
  bool prepUse = isPlural();
  //randomly chooses if sentence will contain singular nouns or plural nouns 

  //if plural, use "the" as the article preference
  word *articleCapThe = new word ("punct", "The");
  word *articleThe = new word ("punct", "the");
		
  //if singular, randomly select "the" or "a/an" as the article preference
  word *articleCap = new word ("punct", "A");
  word *article = new word ("punct", "a");
  word *articleCapAn = new word ("punct", "An");
  word *articleAn = new word ("punct", "an");
	
	
  controller *randomList = new controller();
  word *currentword;
  word *currentNoun;
  
  if (numNoun == 1) {
    currentNoun = wordBank->findTypeOfWord( "noun" ); //generates random noun
    
    if (isVowel(currentNoun) && !plural) {
      randomList -> addWord(articleCapAn); //if using singular nouns and noun starts with a vowel, use 'an'
    }
    else if (!isVowel(currentNoun) && !plural) {
      randomList -> addWord(articleCap); //if using singular nouns and noun starts with a consonant, use 'a'
    }
    else {
      randomList -> addWord(articleCapThe); //else use 'the'
    }
    if (numAdj != 0) {
      currentword = wordBank->findTypeOfWord( "adjective" ); //if adj exists, add a random adj
      randomList -> addWord(currentword);
    }

    if ( plural )
      currentNoun->content += "s"; //if using plural nouns, append s
    
    randomList -> addWord(currentNoun); //add noun

    
    for (int i = 0; i < numVerb; i++) { //for loops through all verbs and existing adv 
      if (numAdv != 0) {

        randomList -> addWord( wordBank->findTypeOfWord( "adverb" )); //adds adv
      }
    
      randomList -> addWord( wordBank->findTypeOfWord( "verb" )); //adds verb
     
      if (numVerb == 2 && verbCount != 1) {
	randomList -> addWord(wordBank->findTypeOfWord( "conjunction" )); //adds conjunction if needed
      }
      verbCount++;
    }	
    randomList -> addWord(selectPunct(period, exclam, quest)); //adds random punctuation

    return randomList;
  }

  if (numNoun == 2) {
    currentNoun = wordBank->findTypeOfWord( "noun" ); //generates random noun
    
    if (isVowel(currentNoun) && !plural) {
      randomList -> addWord(articleCapAn); //if using singular nouns and noun starts with a vowel, use 'an'
    }
    else if (!isVowel(currentNoun) && !plural) {
      randomList -> addWord(articleCap); //if using singular nouns and noun starts with a consonant, use 'a'
    }
    else {
      randomList -> addWord(articleCapThe); //else use 'the'
    }
    if (numAdj != 0) {
      currentword = wordBank->findTypeOfWord( "adjective" ); //if adj exists, add a random adj
      randomList -> addWord(currentword);
    }

    if ( plural )
      currentNoun->content += "s"; //if using plural nouns, append s
     
    randomList -> addWord(currentNoun); //add noun

    for (int i = 0; i < numVerb; i++) { //for loops through all verbs and existing adv 
      if (numAdv != 0) {

        randomList -> addWord( wordBank->findTypeOfWord( "adverb" )); //adds adv
      }
    
      randomList -> addWord( wordBank->findTypeOfWord( "verb" )); //adds verb
     
      if (numVerb == 2 && verbCount != 1) {
	randomList -> addWord(wordBank->findTypeOfWord( "conjunction" )); //adds conjunction if needed
      }
      verbCount++;
    }	

    currentNoun = wordBank->findTypeOfWord( "noun" ); //generates random noun
    
    if (isVowel(currentNoun) && !plural) {
      randomList -> addWord(articleAn); //if using singular nouns and noun starts with a vowel, use 'an'
    }
    else if (!isVowel(currentNoun) && !plural) {
      randomList -> addWord(article); //if using singular nouns and noun starts with a consonant, use 'a'
    }
    else {
      randomList -> addWord(articleThe); //else use 'the'
    }
    if (numAdj != 0) {
      currentword = wordBank->findTypeOfWord( "adjective" ); //if adj exists, add a random adj
      randomList -> addWord(currentword);
    }
    
    if ( plural )
      currentNoun->content += "s"; //if using plural nouns, append s
    
    
    randomList -> addWord(currentNoun); //add noun
     
    randomList -> addWord(selectPunct(period, exclam, quest)); //adds random punctuation

    return randomList;
   
    
    //same thing but order is:
    //articleCap, adjective, noun, adverb, verb, article, adjective, noun, punct.
  }
	
  if (numNoun == 3) {
    if (prepUse) {
    
      for ( int i = 0; i < 2; ++i )
	{

	  currentNoun = wordBank->findTypeOfWord( "noun" ); //generates random noun
    
	  if (isVowel(currentNoun) && !plural && i == 0) {
	    randomList -> addWord(articleCapAn); //if using singular nouns and noun starts with a vowel, use 'an'
	  }
	  else if (!isVowel(currentNoun) && !plural && i == 0) {
	    randomList -> addWord(articleCap); //if using singular nouns and noun starts with a consonant, use 'a'
	  }
	  else if (plural && i == 0) {
	    randomList -> addWord(articleCapThe); //else use 'the'
	  }

	  
	  else  if (isVowel(currentNoun) && !plural && i == 1 ) {
	    randomList -> addWord(articleAn); //if using singular nouns and noun starts with a vowel, use 'an'
	  }
	  else if (!isVowel(currentNoun) && !plural && i == 1) {
	    randomList -> addWord(article); //if using singular nouns and noun starts with a consonant, use 'a'
	  }
	  else {
	    randomList -> addWord(articleThe); //else use 'the'
	  }
	  
	  if (numAdj != 0) {
	    currentword = wordBank->findTypeOfWord( "adjective" ); //if adj exists, add a random adj
	    randomList -> addWord(currentword);
	  }

	  if ( plural )
	    currentNoun->content += "s"; //if using plural nouns, append s
    
	  
	  randomList -> addWord(currentNoun); //add noun

	  if ( i == 0 )
	    randomList -> addWord(wordBank->findTypeOfWord( "conjunction" )); //adds conjunction if needed
	  
	 
	}

      for (int i = 0; i < numVerb; i++) { //for loops through all verbs and existing adv 
	if (numAdv != 0) {

	  randomList -> addWord( wordBank->findTypeOfWord( "adverb" )); //adds adv
	}
    
	randomList -> addWord( wordBank->findTypeOfWord( "verb" )); //adds verb
     
	if (numVerb == 2 && verbCount != 1) {
	  randomList -> addWord(wordBank->findTypeOfWord( "conjunction" )); //adds conjunction if needed
	}
	verbCount++;
      }

      currentNoun = wordBank->findTypeOfWord( "noun" ); //generates random noun
    
      if (isVowel(currentNoun) && !plural) {
	randomList -> addWord(articleAn); //if using singular nouns and noun starts with a vowel, use 'an'
      }
      else if (!isVowel(currentNoun) && !plural) {
	randomList -> addWord(article); //if using singular nouns and noun starts with a consonant, use 'a'
      }
      else {
	randomList -> addWord(articleThe); //else use 'the'
      }
      if (numAdj != 0) {
	currentword = wordBank->findTypeOfWord( "adjective" ); //if adj exists, add a random adj
	randomList -> addWord(currentword);
      }

      if ( plural )
	currentNoun->content += "s"; //if using plural nouns, append s
    
      randomList -> addWord(currentNoun); //add noun

      randomList -> addWord(selectPunct(period, exclam, quest)); //adds random punctuation

      return randomList;


    }






    else
      {

	currentNoun = wordBank->findTypeOfWord( "noun" ); //generates random noun
    
	if (isVowel(currentNoun) && !plural) {
	  randomList -> addWord(articleCapAn); //if using singular nouns and noun starts with a vowel, use 'an'
	}
	else if (!isVowel(currentNoun) && !plural) {
	  randomList -> addWord(articleCap); //if using singular nouns and noun starts with a consonant, use 'a'
	}
	else {
	  randomList -> addWord(articleCapThe); //else use 'the'
	}
	if (numAdj != 0) {
	  currentword = wordBank->findTypeOfWord( "adjective" ); //if adj exists, add a random adj
	  randomList -> addWord(currentword);
	}

	if ( plural )
	  currentNoun->content += "s"; //if using plural nouns, append s
    
	randomList -> addWord(currentNoun); //add noun

    
	for (int i = 0; i < numVerb; i++) { //for loops through all verbs and existing adv 
	  if (numAdv != 0) {

	    randomList -> addWord( wordBank->findTypeOfWord( "adverb" )); //adds adv
	  }
    
	  randomList -> addWord( wordBank->findTypeOfWord( "verb" )); //adds verb
     
	  if (numVerb == 2 && verbCount != 1) {
	    randomList -> addWord(wordBank->findTypeOfWord( "conjunction" )); //adds conjunction if needed
	  }
	  verbCount++;
	}

	currentNoun = wordBank->findTypeOfWord( "noun" ); //generates random noun
    
	if (isVowel(currentNoun) && !plural) {
	  randomList -> addWord(articleAn); //if using singular nouns and noun starts with a vowel, use 'an'
	}
	else if (!isVowel(currentNoun) && !plural) {
	  randomList -> addWord(article); //if using singular nouns and noun starts with a consonant, use 'a'
	}
	else {
	  randomList -> addWord(articleThe); //else use 'the'
	}
	if (numAdj != 0) {
	  currentword = wordBank->findTypeOfWord( "adjective" ); //if adj exists, add a random adj
	  randomList -> addWord(currentword);
	}

	if ( plural )
	  currentNoun->content += "s"; //if using plural nouns, append s
    
	randomList -> addWord(currentNoun); //add noun

	randomList->addWord( wordBank->findTypeOfWord( "preposition" ));

	currentNoun = wordBank->findTypeOfWord( "noun" ); //generates random noun
    
	if (isVowel(currentNoun) && !plural) {
	  randomList -> addWord(articleAn); //if using singular nouns and noun starts with a vowel, use 'an'
	}
	else if (!isVowel(currentNoun) && !plural) {
	  randomList -> addWord(article); //if using singular nouns and noun starts with a consonant, use 'a'
	}
	else {
	  randomList -> addWord(articleThe); //else use 'the'
	}
	if (numAdj != 0) {
	  currentword = wordBank->findTypeOfWord( "adjective" ); //if adj exists, add a random adj
	  randomList -> addWord(currentword);
	}

	if ( plural )
	  currentNoun->content += "s"; //if using plural nouns, append s
    
	randomList -> addWord(currentNoun); //add noun


	randomList -> addWord(selectPunct(period, exclam, quest)); //adds random punctuation

	return randomList;
	
      }
    


    
    // article, adjective, noun, WITH, article, adjective, noun, punct.
   
  }
  return nullptr;
}



//randomly selects 1 or 2 to determine if the sentence will use singular or plural nouns. 
bool isPlural () {
  int randomNumber = (rand() % 2) + 1; //generates num 1-2
  if (randomNumber == 1) {
    return false; //use singular nouns
  }
  else {
    
    return true; //use plural nouns
  }
}

//randomly selects 1, 2, or 3 to determine the punctuation of the sentence. 
word* selectPunct (word *period, word *exclam, word *quest) {
  int randomNumber = (rand() % 3) + 1; //generates num 1-3
  if (randomNumber == 1) {
    return period; //use period
  }
  else if (randomNumber == 2) {
    return exclam; //use exclamation point
  }
  else {
    return quest; //use question mark
  }
}

//determines if the first letter of the noun starts with a vowel 
bool isVowel (word *word) {
  std::string wordcontent = word->content;
  std::string firstLetter = word->content.substr(0,0);
  char const *temp = firstLetter.c_str();
  int value = *temp;
	
  switch ( value ) {
  case 'a':
  case 'e':
  case 'i':
  case 'o': 
  case 'u':
    return true;
  default:
    return false;
  }
}
