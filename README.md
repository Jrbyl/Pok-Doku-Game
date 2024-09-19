Jon Beltzhoover
beltzj03@iastate.edu

PokeDoku Game

- - - - - - - - - - - - - - - - - - - - - - - -
DISCLAIMER: MUST BE PLAYED IN A 117x24 TERMINAL
- - - - - - - - - - - - - - - - - - - - - - - -

    Description:

    As part of the create your own project assignment, I created my own terminal game based off an actual browser game,
    PokeDoku (https://pokedoku.com/). Like our semester long project, it involved using the same Pokemon data from 
    assignment 1.07 and onward. My game, while not as complex as the browser game, randomly generates a set of types
    including at least one generation tag (based off actual game titles) and the user must guess a Pokemon based on
    the restrictions by the given grid. These restrictions also had to be checked for duplicates and impossible
    data entries that would make the game impossible to beat. In addition, I added a leaderboard function; if the user gets 
    all 9 grids correct, they have the option to add their name to the leaderboard with their time. At the end of the game, 
    the user can choose to play again, view the leaderboard (shows top 10), or quit the game. Leaderboard data is stored 
    between games, so even if you quit and rerun the program the leaderboard will remain intact with names and times.

    Instructions:

    Played in a 117x24 terminal!
    Compile with: g++ pokedoku.cpp -o pokedoku -lncurses
    Run with: ./pokedoku
    make file: make pokedoku
    Certain key instructions are shown in the game