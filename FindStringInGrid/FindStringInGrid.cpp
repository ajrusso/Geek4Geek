#include <vector>
#include <string>
#include <iostream>

using namespace std;


vector<vector<int>> searchWord(vector<vector<char>>, string);
bool searchDirections(vector<vector<char>>, string, int, int);
void printGrid(vector<vector<char>>);
void printResult(vector<vector<int>>);
void printWord(string);


int main() {
    vector<vector<char>> grid = {{'d','b','c','a','e','a','d','a','b','c','a','a','a'}, 
                                 {'d','e','c','d','c','b','e','d','e','c','c','b','e'}, 
                                 {'c','e','d','d','a','e','e','e','d','d','d','c','d'}, 
                                 {'e','c','e','b','c','d','b','a','d','a','a','c','e'}, 
                                 {'a','c','e','d','d','a','a','d','a','b','a','b','a'}};
    string word = "a";
    vector<vector<int>> result;

    printGrid(grid);
    printWord(word);
    result = searchWord(grid, word);
    printResult(result);
}

// Search given grid for given word.
// return: starting positions of words found.
vector<vector<int>> searchWord(vector<vector<char>> grid, string word) {
    vector<vector<int>> result = {};
    for (int row = 0; row < grid.size(); ++row) {
        for (int col = 0; col < grid[row].size(); ++col) {
            if (searchDirections(grid, word, row, col)) {
                vector<int> word_coordinates = {row, col};
                result.push_back(word_coordinates);
            }
        }
    } 
    return result;
}


// Seach 8 directions for given word (up, down, left, right, and 4 diagonals)
bool searchDirections(vector<vector<char>> grid, string word, int row, int col) {
    int word_len;
    bool word_fits_up;
    bool word_fits_down;
    bool word_fits_left;
    bool word_fits_right;

    cout << "Search grid position (" << row << ", " << col << ") for word \"" << word << "\"" << endl;

    
    if (grid[row][col] != word[0]) {
        return false;
    }
        
    word_len = word.length();
    if (word_len == 1) {
        return true;
    }

    word_fits_up = row + 1 - word_len >= 0;
    word_fits_down = row + word_len <= grid.size();
    word_fits_left = col + 1 - word_len >= 0; 
    word_fits_right = col + word_len <= grid[row].size();

    // Search up
    if (word_fits_up) {
        cout << "Fits Up" << endl;
        int i = 1;
        while (grid[row - i][col] == word[i]) {
            if (++i == word_len)
                return true;
        } 
    }
    // Search down
    if (word_fits_down) {
        cout << "Fits Down" << endl;
        int i = 1;
        while (grid[row + i][col] == word[i]) {
            if (++i == word_len)
                return true;
        } 
    }
    // Search left
    if (word_fits_left) {
        cout << "Fits left" << endl;
        int i = 1;
        while (grid[row][col - i] == word[i]) {
            if (++i == word_len)
                return true;
        }
    }
    // Search Right
    if (word_fits_right) {
        cout << "Fits right" << endl;
        int i = 1;
        while (grid[row][col + i] == word[i]) {
            if (++i == word_len)
                return true;
        }
    }
    // Search diag up-right
    if (word_fits_up && word_fits_right) {
        cout << "Fits up-right" << endl;
        int i = 1;
        while (grid[row - i][col + i] == word[i]) {
            if (++i == word_len)
                return true;
        }
    }
    // Search diag up-left
    if (word_fits_up && word_fits_left) {
        cout << "Fits Up-left" << endl;
        int i = 1;
        while (grid[row - i][col - i] == word[i]) {
            if (++i == word_len)
                return true;
        }
    }
    // Search diag down/right
    if (word_fits_down && word_fits_right) {
        cout << "Fits down-right" << endl;
        int i = 1;
        while (grid[row + i][col + i] == word[i]) {
            if (++i == word_len)
                return true;
        }
    }
    // Search diag down/left
    if (word_fits_down && word_fits_left) {
        cout << "Fits down-left" << endl;
        int i = 1;
        while (grid[row + i][col - i] == word[i]) {
            if (++i == word_len)
                return true;
        }
    }

    return false;
}

void printGrid(vector<vector<char>> grid) {
    printf("##########\n");
    printf("#  GRID  #\n");
    printf("##########\n\n");
    
    for (int x = 0; x < grid.size(); ++x) {
        for (int y = 0; y < grid[x].size(); ++y) {
            printf("%c ", grid[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

void printWord(string word) {
    printf("##########\n");
    printf("#  Word  #\n");
    printf("##########\n\n");

    cout << word << endl << endl; 
}

void printResult(vector<vector<int>> result) {
    printf("############\n");
    printf("#  Result  #\n");
    printf("############\n\n");

    for (int x = 0; x < result.size(); ++x) {
        printf("(");
        for (int y = 0; y < result[x].size(); ++y) {
            (y) ? printf("%d", result[x][y]) : printf("%d,", result[x][y]);
        }
        printf(")\n");
    }
    printf("\n");
}