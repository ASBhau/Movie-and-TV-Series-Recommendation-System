#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct Media {
    string title;
    string genre;
    float imdbScore;
};

void readMoviesFromFile(vector<Media>& library, const string& filePath) {
    ifstream file(filePath);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string title, genre, scoreStr;
        float imdbScore;

        getline(ss, title, ',');
        getline(ss, genre, ',');
        getline(ss, scoreStr);

        imdbScore = stof(scoreStr);
        library.push_back({title, genre, imdbScore});
    }
}

void addPreferredGenre(set<string>& preferredGenres, const string& genre) {
    preferredGenres.insert(genre);
}

vector<Media> recommendMovies(set<string>& preferredGenres, vector<Media>& library) {
    vector<Media> recommendations;

    for (const auto& media : library) {
        if (preferredGenres.count(media.genre) > 0) {
            recommendations.push_back(media);
        }
    }

    sort(recommendations.begin(), recommendations.end(), [](const Media& a, const Media& b) {
        return a.imdbScore > b.imdbScore;
    });

    return recommendations;
}

int main() {
    vector<Media> library;
    set<string> preferredGenres;

    readMoviesFromFile(library, "C:\\Users\\Agrim Singh\\Downloads\\extended_movies.txt");

    addPreferredGenre(preferredGenres, "Sci-Fi");
    addPreferredGenre(preferredGenres, "Comedy");

    vector<Media> recommendations = recommendMovies(preferredGenres, library);

    cout << "Recommended movies and TV series:" << endl;
    for (const auto& media : recommendations) {
        cout << media.title << " (" << media.genre << ") - IMDB Score: " << media.imdbScore << endl;
    }

    return 0;
}
