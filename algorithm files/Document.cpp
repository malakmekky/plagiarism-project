#include <fstream>
#include <sstream>
#include "Document.h"
using namespace std;
Document::Document(string file_path) {
    this->file_path = file_path;
}

void Document::parse_sentences() {
    // Clear any existing sentences
    sentences.clear();
    // Open file
    ifstream file(file_path);
    if (!file.is_open()) {
        throw runtime_error("Failed to open file: " + file_path);
    }
    // Read file line by line and split each line into sentences
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string sentence;
        while (getline(iss, sentence, '.')) {
            // Remove leading/trailing whitespace (spaces, tabs, newlines, carriage returns, form feeds, vertical tabs)
            sentence.erase(0, sentence.find_first_not_of(" \t\n\r\f\v"));
            sentence.erase(sentence.find_last_not_of(" \t\n\r\f\v") + 1);
            // Add sentence to vector (if it's not empty)
            if (!sentence.empty()) {
                sentences.push_back(sentence);
            }
        }
    }
}

vector<string> Document::get_sentences() {
    return sentences;
}

void Document::set_plagiarism_percentage(float percentage) {
    plagiarism_percentage = percentage;
}

float Document::get_plagiarism_percentage() {
    return plagiarism_percentage;
}
