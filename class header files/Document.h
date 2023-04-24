#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
class Document
{
public:
    Document(std::string file_path); // constructor
    void parse_sentences(); //parses every sentence in the doc and stores it in the sentences vector
    std::vector<std::string> get_sentences(); // getter: returns the sentences vector
    void set_plagiarism_percentage(float percentage); //setter: sets the plagiarism percentage
    float get_plagiarism_percentage(); //getter: returns the plagiarism percentage

private:
    std::string file_path;
    std::vector<std::string> sentences; //stores all the sentences in the document
    float plagiarism_percentage;
};

