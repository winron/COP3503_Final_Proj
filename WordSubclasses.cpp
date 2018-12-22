
#include "WordSubclasses.h"
#include <string>

//used to make singular nouns plural. only works for simple nouns that are made plural by appending "s."
std::string Noun::makeNounPlural(std::string noun){
    noun += "s" ;
    return noun;
}

//used to convert simple verbs to the past tense
std::string Verb::makeVerbPast(std::string verb){
    verb += "ed" ;
    return verb;
}

//used to convert simple verbs ending in a vowel to the past tense
std::string Verb::makeVerbPastWithVowel(std::string verb){
    verb += "d" ;
    return verb;
}
