// Author: Matthew Peach
// Program Status: Complete
// Description:
//   User input is assigned to a string, then becomes an attribute of a Word_Modifier object.
// The Word_Modifier class has methods that manipulate the string. For wordUpper(), wordLower(),
// and wordFlip() a char (C-string) version of user input is used.

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Word_Modifier {
private:
    string word;
    int x; //Needed to determine length for C-string version
    char word_as_char[100]; //Since the requirement said to use C-strings
    
public:
    Word_Modifier();
    string wordSeparator();
    void wordUpper();
    void wordLower();
    void wordFlip();
};

int main(){
    bool goAgain {true};
    string userChoice {"Unset"};
    
    do{
        Word_Modifier *word_ptr = new Word_Modifier(); //Constructor
        cout << "Separated by uppercase: " << word_ptr->wordSeparator() << endl; // word separator
        word_ptr->wordUpper(); //uppercase
        word_ptr->wordLower(); //lowercase
        word_ptr->wordFlip(); //swapcase
        delete word_ptr; //free memory
        
        do{
            cout << "\nWould you like to enter another word? (y/n): ";
            getline(cin, userChoice);
            cin.clear();
        }while(userChoice != "Y" && userChoice != "y" && userChoice != "N" && userChoice != "n");
        if(userChoice == "N" || userChoice == "n"){
            goAgain = false;
        }
        else if(userChoice == "Y" || userChoice == "y"){
            goAgain = true;
        }
        cout << endl << "====================================================================================" << endl;
    }while(goAgain);
    
    return 0;
}

Word_Modifier::Word_Modifier(){
    string userInput{"Unset"};
    
    do{
    cout << "Enter a word/phrase (up to 99 characters): ";
        getline(cin, userInput);
        cin.clear();
        cout << endl;
    }while(userInput.length() >= 99);
    
    this->word = userInput;
    
    this->x = userInput.length();
    
    for(int i = 0; i < userInput.length(); ++i){
        this->word_as_char[i] = userInput[i];
    }
    
}

string Word_Modifier::wordSeparator(){
    // I didn't want to change the original word input, so I do a pseudo-pass-by-reference here
    // by assigning word to a new variable only in scope in this function
    string wordSeparated = word;
    string space {" "};
    
    // Starts at index 1 to prevent a space being inserted as the first character
    for (int i = 1; i < wordSeparated.length(); ++i){
        // If the word at [i] is uppercase AND does not already have a space before it
        if (isupper(wordSeparated[i]) == 1 && wordSeparated[i-1] != ' '){
            wordSeparated.insert(i, space);
            ++i; // Adds 1 to i if a space is inserted or else the next character will always be uppercase and it will loop forever
        }
    }
    return wordSeparated;
}

void Word_Modifier::wordUpper(){
    char wordUpper[100];
    
    for(int i = 0; i < x; ++i){
        if(word_as_char[i] >= 97 && word_as_char[i] <= 122){ //ASCII lowercase range
            wordUpper[i] = word_as_char[i] - 32; //Convert to ASCII uppercase
        }
        else{
            wordUpper[i] = word_as_char[i];
        }
    }
    cout << endl << "Converted to uppercase: ";
    for(int i = 0; i < x; ++i){
        cout << wordUpper[i];
    }
    cout << endl;
}

void Word_Modifier::wordLower(){
    char wordLower[100];
    
    for(int i = 0; i < x; ++i){
        if(word_as_char[i] >= 65 && word_as_char[i] <= 90){
            wordLower[i] = word_as_char[i] + 32;
        }
        else{
            wordLower[i] = word_as_char[i];
        }
    }
    cout << endl << "Converted to lowercase: ";
    for(int i = 0; i < x; ++i){
        cout << wordLower[i];
    }
    cout << endl;
}

void Word_Modifier::wordFlip(){
    char wordFlip[100];
    
    for (int i = 0; i < x; ++i){
        if(word_as_char[i] >= 97 && word_as_char[i] <= 122){ // If character is lowercase, flip to uppercase
            wordFlip[i] = word_as_char[i] - 32;
        }
        else if(word_as_char[i] >= 65 && word_as_char[i] <= 90){ // Else if character is uppercase, flip to lowercase
            wordFlip[i] = word_as_char[i] + 32;
        }
        else{
            wordFlip[i] = word_as_char[i]; // Else leave the character as-is if not in the ASCII alphabet ranges
        }
    }
    cout << endl << "Case-flipped: ";
    for(int i = 0; i < x; ++i){
        cout << wordFlip[i];
    }
    cout << endl;
}