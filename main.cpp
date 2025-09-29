/*
Bearflix movie list
implements the list processing the right output messages
Ethen Dixon
 */

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
#include <cstdlib>

bool find(const std::list<std::string> &myList, const std::string &value)
{
    bool found = (std::find(myList.begin(),
                            myList.end(),
                            value) != myList.end());
    return found;
}

static void stripCR(std::string& s) {
    if (!s.empty() && s.back() == '\r') s.pop_back();
}

int main()
{
    std::list<std::string> movies;
    std::string line;

    std::cout << "Reading in BearFlix movie list..." << std::endl;
    std::ifstream in1("mymovies.txt");
    if (!in1) {
        std::cout << "File mymovies.txt cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }
    while (std::getline(in1, line)) {
        stripCR(line);
        if (!line.empty()) movies.push_back(line);
    }
    in1.close();

    std::cout << "Adding new movies..." << std::endl;
    std::ifstream in2("add_movies.txt");
    if (!in2) {
        std::cout << "File add_movies.txt cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }
    while (std::getline(in2, line)) {
        stripCR(line);
        if (line.empty()) continue;
        if (find(movies, line)) {
            std::cout << "Movie " << line << " cannot be added to the list." << std::endl;
        } else {
            movies.push_back(line);
        }
    }
    in2.close();

    std::cout << "Removing movies..." << std::endl;
    std::ifstream in3("del_movies.txt");
    if (!in3) {
        std::cout << "File del_movies.txt cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }
    while (std::getline(in3, line)) {
        stripCR(line);
        if (line.empty()) continue;
        if (!find(movies, line)) {
            std::cout << "Movie " << line << " cannot be removed from the list." << std::endl;
        } else {
            movies.remove(line);
        }
    }
    in3.close();

    std::ofstream out("mymovies_updated.txt");
    if (!out) {
        std::cout << "File mymovies_updated.txt cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }
    for (const auto& title : movies) {
        out << title << '\n';
    }
    out.close();

    std::cout << "New movie list ready!" << std::endl;
    return EXIT_SUCCESS;
}
