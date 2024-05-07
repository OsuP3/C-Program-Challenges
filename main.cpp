#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cctype>
using namespace std;


void result(int stage, string & won, string inputword, vector<char> guessed, string allguesses){
    int notin = 0;
    for(int i = 0; i < inputword.length(); i++){
        if(inputword[i] != guessed.at(i) && inputword[i] != toupper(guessed.at(i))) notin++;
    }
    if (notin == 0){
        cout<<"Word or Phrase Successfully Guessed!\n";
        cout<<inputword<<"\n";
        won = "Word or Phrase Guessed";
        return;
    }
    cout<<allguesses<<endl;
    switch (stage) {
    case 0:
        cout<<"______\n|    |\n|    \n|   \n|   \n|_____\n";
        break;
    case 1:
        cout<<"______\n|    |\n|    O\n|   \n|   \n|_____\n";
        break;
    case 2:
        cout<<"______\n|    |\n|    O\n|    |\n|   \n|_____\n";
        break;
    case 3:
        cout<<"______\n|    |\n|    O\n|   /|\n|   \n|_____\n";
        break;
    case 4:
        cout<<"______\n|    |\n|    O\n|   /|\\\n|   \n|_____\n";
        break;
    case 5:
        cout<<"______\n|    |\n|    O\n|   /|\\\n|   / \n|_____\n";
        break;
    case 6:
        cout<<"______\n|    |\n|    O\n|   /|\\\n|   / \\\n|_____\n"<<"You've Lost!"<<endl;
        cout<<inputword<<"\n";
        won = "Lose";
        break;
    default:
        break;
    }
}


int main()
{
    string win = "in progress";
    string guessword;
    vector<char> printed = {};
    string allguessed = "Letters Guessed: ";
    char guess;
    int stage = 0;

    cout<<"input word or phrase to guess\n";
    getline(cin, guessword);
    for(int i = 0; i < 10; i++) cout<<"\n";
    cout<<"^^^^^^^^word/phrase hidden"<<endl;
    cout<<"______\n|    |\n|    \n|   \n|   \n|_____\n";
    for(int i = 0; i < guessword.length(); i++){
        if(guessword[i] == ' ') printed.push_back(' ');
        else printed.push_back('_');

    }
    while(win == "in progress"){
        for(int i = 0; i < guessword.length(); i++)cout<<printed.at(i);
        cout<<"\nGuess a letter:\n";
        cin>>guess;
        allguessed = allguessed + guess + " ";
        if(guessword.find(guess) == string::npos && guessword.find(toupper(guess)) == string::npos ){
            cout<<guess<<" is not in the word/phrase\n";
            stage++;
        }
        else{
            if(guessword.find(guess) == string::npos) guess = toupper(guess);
            printed.at(guessword.find(guess)) = guess;
            size_t index = guessword.find(guess);
            while(index != string::npos){
                if(guessword.find(guess) == string::npos) guess = toupper(guess);
                printed.at(guessword.find(guess, index)) = guess;
                index = guessword.find(guess, index+1);
            }
        }

        result(stage, win, guessword, printed, allguessed);
    }


    return 0;
}
//12 11 13 (chapters)
