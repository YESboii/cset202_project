#include <vector>
#include <iostream>
#include <algorithm>
#include "Trie.cpp"

int main() {

    Trie *trie = new Trie(); // create a Trie object
    // interact with the Trie object
    int choice=1;
    while(true) {
        cout << "+========================================+" << endl;
        cout << "|     WELCOME TO CODE QUEST              |" << endl;
        cout << "==========================================" << endl;
        cout << "|   Please select one:                   |" << endl;
        cout << "|-----------------------------------------" << endl;
        cout << "|   Enter 1 for manually entering a word |" << endl;
        cout << "|-----------------------------------------" << endl;
        cout << "|   Enter 2 for autocomplete             |" << endl;
        cout << "|-----------------------------------------" << endl;
        cout << "|   Enter 0 for exiting                  |" << endl;
        cout << "+========================================+" << endl;
        cout<<"CHOICE : ";
        cin>>choice;
        string input;  
        if (choice == 0) {
            break;
        }
        else if(choice==1){
            trie->InsertUserInput();
        }
        else if(choice==2) {
            cout << "Please type search queries: " << endl;
            cin >> input;
            std::transform(input.begin(), input.end(), input.begin(), ::tolower);

            vector<string> results = trie->Search(input);

            if (trie->IsWord(input) || trie->IsValidPrefix(input)) {
                if (trie->IsWord(input)) {
                    auto it = std::remove(results.begin(), results.end(), input);
                    results.erase(it, results.end());
                    cout << "Your search query is a valid word; however, we still may have recommendations for you:"
                         << endl;

                }
                cout << "AUTOCOMPLETE - Your options are:" << endl;
                if (results.empty()) {
                    cout << "Sorry! We don't have any options for you." << endl;
                } else {
                    for (string result: results) {
                        cout << result << endl;
                    }
                }

            } else {
                cout << "RECOMMENDATION - Do you mean:" << endl;
                if (results.empty()) {
                    cout << "Sorry! We don't have any recommendations for you." << endl;
                } else {
                    for (string result: results) {
                        cout << result << endl;
                    }
                }
            }
        }
        else{
            cout<<"Enter a correct choice!!"<<endl;
        }

    }
    cout<<"THANK YOU!!"<<endl;
    return 0;
}

