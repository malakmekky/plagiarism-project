#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <fstream>
class Document
{
public:
    Document(std::string file_path);
    void parse_sentences();
    std::vector<std::string> get_sentences();
    void set_plagiarism_percentage(float percentage);
    float get_plagiarism_percentage();

private:
    std::string file_path;
    std::vector<std::string> sentences;
    float plagiarism_percentage;
};

