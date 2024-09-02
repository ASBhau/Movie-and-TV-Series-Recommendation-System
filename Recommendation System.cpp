#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

struct Media {
    string title;
    string genre;
};

void addMedia(vector<Media>& library, string title, string genre) {
    library.push_back({title, genre});
}

void addPreferredGenre(set<string>& preferredGenres, string genre) {
    preferredGenres.insert(genre);
}

bool isPreferredGenre(set<string>& preferredGenres, string genre) {
    return preferredGenres.count(genre) > 0;
}

vector<string> recommend(set<string>& preferredGenres, vector<Media>& library) {
    vector<string> recommendations;
    for (int i = 0; i < library.size(); i++) {
        if (isPreferredGenre(preferredGenres, library[i].genre)) {
            recommendations.push_back(library[i].title);
        }
    }
    return recommendations;
}

int main() {
    vector<Media> library;
    set<string> preferredGenres;

    addMedia(library, "Inception", "Sci-Fi");
    addMedia(library, "The Matrix", "Sci-Fi");
    addMedia(library, "Friends", "Comedy");

    addPreferredGenre(preferredGenres, "Sci-Fi");
    addPreferredGenre(preferredGenres, "Comedy");

    vector<string> recommendations = recommend(preferredGenres, library);

    cout << "Recommended movies and TV series:" << endl;
    for (int i = 0; i < recommendations.size(); i++) {
        cout << recommendations[i] << endl;
    }

    return 0;
}
