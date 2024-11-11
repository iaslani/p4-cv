#include <iostream>
#include "csvstream.hpp"
#include <iostream>
#include <string>
#include <map>
#include <set>  
#include <cmath>
using namespace std;

class Classifier {
    public:
    int getPosts() {
        return numPosts;
    }

    void setPosts(int p) {
      numPosts = p;
    }

    void setNumPostsWithWord(string word) {
        // iterate through set of strings and add each word to map
        // if the map contains the word then incrememnt count by 1
        if (numPostsWithWord.find(word) == numPostsWithWord.end()) {
            numPostsWithWord[word] = 1;
        }
        else {
            numPostsWithWord[word]++;
        }
    }

    void setNumPostsWithLabel(string label) {
        if (numPostsWithLabel.find(label) == numPostsWithLabel.end()) {
            numPostsWithLabel[label] = 1;
        }
        else {
            numPostsWithLabel[label]++;
        }
    }

    void setLabelAndWord(string label, string word) {
        set<string> words = unique_words(word);
        if (words.find(word) != words.end()) {
            numPostsWithLabelAndWord++;
        }
    }

    int getLabelAndWord() {
        return numPostsWithLabelAndWord;
    }

    double LnPofC (string label) {
        return log(numPostsWithLabel[label]/static_cast<double>(numPosts));
    }

    double LNWPofC (string label, string word) {
        set<string> words = unique_words(word);
        if (words.find(word) == words.end()) {
            return (1/static_cast<double>(numPosts));
        }
        else if ()
    }


    private:
    int numPosts;

    set<string> unique_words(const string &str) {
        istringstream source(str);
        set<string> words;
        string word;
        while (source >> word) {
            words.insert(word);
        }
        return words;
    }

    // map
    // from the set of unique words, add each word into numPostsWithWord
    // and if the map contains the word already then incrememnt it by 1
    map<string, int> numPostsWithWord;

    // map
    // if tag has a new word then incremement the count of label in
    // the map by 1
    map<string, int> numPostsWithLabel;

    // check if post contains label C and then
    // try to insert word into the set unique words and if you can't
    // then you know that the word is already in the set
    int numPostsWithLabelAndWord;
};


int main(int argc, char **argv) {

    cout.precision(3);

    if (argc < 2 || argc > 3) {
        cout << "Usage: classifier.exe TRAIN_FILE [TEST_FILE]" << endl;
        return 1;
    }
    
    string train_file = argv[1];
    string test_file = argv[2];

    ifstream infile(train_file);

    if (!infile) {
        cout << "Error opening " << train_file << endl;
    }

    csvstream csvin(train_file);

    map<string, string> row;

    try {
        while (csvin >> row) {
            cout << row["tag"] << " " << row["content"] << "\n";
        }
    } catch(const csvstream_exception &e) {
        cerr << e.what() << "\n";
        return 1;
    }    


    return 0;
}