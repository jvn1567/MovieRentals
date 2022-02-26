#include "movie.h"
#include "movieFactory.h"
#include "drama.h"

int main() {
    string test = "F, 10, Nora Ephron, You've Got Mail, 1998";
    istringstream input(test);
    string type, count, director, title, year;
    getline(input, type, ',');
    getline(input, count, ',');
    getline(input, director, ',');
    getline(input, title, ',');
    getline(input, year, ',');
    cout << type << endl << count << endl << director << endl;
    cout << title << endl << year << endl;
    return 0;
}