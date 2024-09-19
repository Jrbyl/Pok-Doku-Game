#include <iostream>
#include <vector>
#include <ncurses.h>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>
#include <cstring>
#include <string>
#include <unistd.h>
#include <algorithm>
#include <chrono>
#include "pokedoku.h"

using namespace std;

int main(int argc, char *argv[]) {

    srand(time(NULL));

    initscr();
    start_color();
    cbreak();
    keypad(stdscr, TRUE);

    char game;
    int score;
    int generationIndex;
    int error1;
    int error2;

    do {
        pokemon_Data pokemonData;
        condition_Data conditionData;
        vector<highscore_Data> highscoreData;

        error1 = initPokemonData(pokemonData);
        error2 = initHighscoreData(highscoreData);
        if (error1 > 0 || error2 > 0) {
            return 0;
        }
        
        generationIndex = getConditions(conditionData, pokemonData);
        removeImpossibleCombos(conditionData, pokemonData);
        removeImpossibleCombos(conditionData, pokemonData);

        WINDOW *background = newwin(24, 117, 0, 0);
        wrefresh(background);
        refresh();

        vector<WINDOW*> win;
        win.resize(9);
        createBoard(win, background, conditionData);

        auto start = chrono::high_resolution_clock::now();
        score = playGame(win, conditionData, pokemonData, generationIndex);
        auto end = chrono::high_resolution_clock::now();

        auto gameDuration = chrono::duration<double>(end - start);

        WINDOW *endScreen = newwin(17, 58, 3, 29);
        game = displayEndScreen(endScreen, score, gameDuration.count(), highscoreData);

        if (game == 'T') {
            WINDOW *leaderboard = newwin(17, 58, 3, 29);
            game = viewLeaderboard(leaderboard, highscoreData);
            delwin(leaderboard);
        }

        for (auto& winIndex : win) {
            delwin(winIndex);
        }
        delwin(endScreen);
        delwin(background);
        endwin();

        score = 0;
    } while (game != 'q');

    return 0;
}