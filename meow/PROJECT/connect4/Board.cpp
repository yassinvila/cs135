/*
    Author: Yassin Vila
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: HW Lab 12A

    Task: Connect 4 game logic and win checking
*/

#include "Board.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

// Struct to represent a location in the grid
struct Coord {
    int bin;
    int idx;
};

// Default constructor delegates to parameterized version
Board::Board() : Board(6, 4) {}

// Parameterized constructor with minimum size limits
Board::Board(int numBins, int capacity) {
    if (numBins < 5) numBins = 5;
    if (capacity < 4) capacity = 4;

    this->numBins = numBins;
    this->capacity = capacity;

    for (int i = 0; i < numBins; i++) {
        vector<int> oneBin;
        grid.push_back(oneBin);
    }
}

// Non-member helper function to print row borders
void print(int numBins) {
    cout << "+";
    for (int i = 0; i < numBins; i++)
        cout << "--+";
    cout << endl;
}

// Display method using shape mapping
void Board::display() const {
    string mapping[] = {
        "\033[31m\u2b24\033[0m", // 0: red circle
        "\033[34m\u2b1f\033[0m", // 1: blue pentagon
        "\033[31m\u25c9\033[0m", // 2: red double circle
        "\033[34m\u2b54\033[0m"  // 3: blue hollow pentagon
    };

    print(numBins);

    for (int j = capacity - 1; j >= 0; j--) {
        cout << "|";
        for (int i = 0; i < numBins; i++) {
            if (j < grid[i].size())
                cout << mapping[grid[i][j]] << "|";
            else
                cout << " |";
        }
        cout << endl;
        print(numBins);
    }

    // Print bin indices
    for (int i = 0; i < numBins; i++)
        cout << " " << i;
    cout << endl;
}

// Add a shape to a valid, not-full bin
int Board::add(int player) {
    int bin;
    cout << "Enter a bin index in [0, " << numBins << ") that is not full: ";
    cin >> bin;

    while (bin < 0 || bin >= numBins || grid[bin].size() >= capacity) {
        if (bin < 0 || bin >= numBins)
            cout << "invalid bin index, needs to be in [0, " << numBins << ")" << endl;
        else
            cout << "the bin is full" << endl;

        cout << "Re-enter a bin index in [0, " << numBins << ") that is not full: ";
        cin >> bin;
    }

    grid[bin].push_back(player);
    return bin;
}

// Horizontal win check
int Board::winInHorizontal(int bin) {
    int row = grid[bin].size() - 1;
    if (row < 0) return -1;

    int player = grid[bin][row];
    vector<Coord> candidates = { Coord{bin, row} };

    // Check left
    for (int i = bin - 1; i >= 0; i--) {
        if (grid[i].size() > row && grid[i][row] == player)
            candidates.push_back(Coord{i, row});
        else break;
    }

    // Check right
    for (int i = bin + 1; i < numBins; i++) {
        if (grid[i].size() > row && grid[i][row] == player)
            candidates.push_back(Coord{i, row});
        else break;
    }

    if (candidates.size() >= 4) {
        for (Coord c : candidates)
            grid[c.bin][c.idx] += 2;
        return player;
    }

    return -1;
}

// Vertical win check
int Board::winInVertical(int bin) {
    int row = grid[bin].size() - 1;
    if (row < 0) return -1;

    int player = grid[bin][row];
    vector<Coord> candidates;

    for (int i = row; i >= 0; i--) {
        if (grid[bin][i] == player)
            candidates.push_back(Coord{bin, i});
        else break;
    }

    if (candidates.size() >= 4) {
        for (Coord c : candidates)
            grid[c.bin][c.idx] += 2;
        return player;
    }

    return -1;
}

// Diagonal and anti-diagonal win check
int Board::winInDiagonal(int bin) {
    int row = grid[bin].size() - 1;
    if (row < 0) return -1;

    int player = grid[bin][row];

    // Diagonal:
    vector<Coord> diag1 = { Coord{bin, row} };

    // down-left (\)
    int b = bin - 1, r = row - 1;
    while (b >= 0 && r >= 0 && r < grid[b].size() && grid[b][r] == player) {
        diag1.push_back(Coord{b, r});
        b--; r--;
    }

    // up-right (\)
    b = bin + 1, r = row + 1;
    while (b < numBins && r < capacity && r < grid[b].size() && grid[b][r] == player) {
        diag1.push_back(Coord{b, r});
        b++; r++;
    }

    if (diag1.size() >= 4) {
        for (Coord c : diag1)
            grid[c.bin][c.idx] += 2;
        return player;
    }

    // Anti-diagonal: /
    vector<Coord> diag2 = { Coord{bin, row} };

    // up-left (/)
    b = bin - 1, r = row + 1;
    while (b >= 0 && r < capacity && r < grid[b].size() && grid[b][r] == player) {
        diag2.push_back(Coord{b, r});
        b--; r++;
    }

    // down-right (/)
    b = bin + 1, r = row - 1;
    while (b < numBins && r >= 0 && r < grid[b].size() && grid[b][r] == player) {
        diag2.push_back(Coord{b, r});
        b++; r--;
    }

    if (diag2.size() >= 4) {
        for (Coord c : diag2)
            grid[c.bin][c.idx] += 2;
        return player;
    }

    return -1;
}

// Wrapper to check for any win
int Board::win(int bin) {
    int result = winInHorizontal(bin);
    if (result != -1) return result;

    result = winInVertical(bin);
    if (result != -1) return result;

    return winInDiagonal(bin);
}

void Board::play() {
    // Not implemented in Task B
}