#include <string>
#include <vector>

#ifndef POKEDOKU_H
#define POKEDOKU_H

using namespace std;

class pokemon {
    public:
     int id;
     string identifier;
     int species_id;
     int height;
     int weight;
     int base_experience;
     int order;
     int is_default;
};

class moves {
    public:
     int id;
     string identifier;
     int generation_id;
     int type_id;
     int power;
     int pp;
     int accuracy;
     int priority;
     int target_id;
     int damage_class_id;
     int effect_id;
     int effect_chance;
     int contest_type_id;
     int contest_effect_id;
     int super_contest_effect_id;
};

class pokemon_moves {
    public:
     int pokemon_id;
     int version_group_id;
     int move_id;
     int pokemon_move_method_id;
     int level;
     int order;
};

class pokemon_species {
    public:
     int id;
     string identifier;
     int generation_id;
     int evolves_from_species_id;
     int evolution_chain_id;
     int color_id;
     int shape_id;
     int habitat_id;
     int gender_rate;
     int capture_rate;
     int base_happiness;
     int is_baby;
     int hatch_counter;
     int has_gender_differences;
     int growth_rate_id;
     int forms_switchable;
     int is_legendary;
     int is_mythical;
     int order;
     int conquest_order;
};

class type_names {
    public:
     int type_id;
     int local_language_id;
     string name;
};

class pokemon_types {
    public:
     int pokemon_id;
     int type_id;
     int slot;
};

class pokemon_Data {
    public:
     vector<pokemon> poke;
     vector<moves> move;
     vector<pokemon_moves> poke_move;
     vector<pokemon_species> poke_spec;
     vector<type_names> type_name;
     vector<pokemon_types> poke_type;
};

class condition_Data {
    public:
     vector<string> name;
     vector<int> id;
};

class highscore_Data {
    public:
     string name;
     double gameDuration;
};

int initPokemonData(pokemon_Data& pokemonData) {
    // Names of the csv_files taken from Pokemon API
    const string dataInput[] = {"pokemon", "moves", "pokemon_moves", "pokemon_species", "type_names", "pokemon_types"};

    // Loop reads and stores all Pokemon API data
    for (int k = 0; k < 6; k++) {
        //Validates files
        ifstream iFile("csv_files/" + dataInput[k] + ".csv");
        if (!iFile) {
            iFile.close();
            cerr << "Error opening csv file!" << endl;
            return 1;
        }

        string firstLine;
        getline(iFile, firstLine);
        string line;

        if (dataInput[k] == "pokemon") {
            while (!iFile.eof()) {
                pokemon p;
                
                getline(iFile, line, ',');
                if (line == "") { 
                    p.id = INT_MAX; 
                }
                else {
                    p.id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.identifier = "";
                }
                else {
                    p.identifier = line;
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.species_id = INT_MAX;
                }
                else {
                    p.species_id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.height = INT_MAX;
                }
                else {
                    p.height = stoi(line);
                }
                
                getline(iFile, line, ',');
                if (line == "") {
                    p.weight = INT_MAX;
                }
                else {
                    p.weight = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.base_experience = INT_MAX;
                }
                else {
                    p.base_experience = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.order = INT_MAX;
                }
                else {
                    p.order = stoi(line);
                }

                getline(iFile, line);
                if (line == "") {
                    p.is_default = INT_MAX;
                }
                else {
                    p.is_default = stoi(line);
                }

                if (iFile.peek() == '\n') {
                    break;
                }

                pokemonData.poke.push_back(p);
            }

            iFile.close();

        }
        else if (dataInput[k] == "moves") {
            while (!iFile.eof()) {
                moves p;

                getline(iFile, line, ',');
                if (line == "") { 
                    p.id = INT_MAX; 
                }
                else {
                    p.id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.identifier = "";
                }
                else {
                    p.identifier = line;
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.generation_id = INT_MAX;
                }
                else {
                    p.generation_id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.type_id = INT_MAX;
                }
                else {
                    p.type_id = stoi(line);
                }
                
                getline(iFile, line, ',');
                if (line == "") {
                    p.power = INT_MAX;
                }
                else {
                    p.power = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.pp = INT_MAX;
                }
                else {
                    p.pp = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.accuracy = INT_MAX;
                }
                else {
                    p.accuracy = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.priority = INT_MAX;
                }
                else {
                    p.priority = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.target_id = INT_MAX;
                }
                else {
                    p.target_id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.damage_class_id = INT_MAX;
                }
                else {
                    p.damage_class_id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.effect_id = INT_MAX;
                }
                else {
                    p.effect_id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.effect_chance = INT_MAX;
                }
                else {
                    p.effect_chance = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.contest_type_id = INT_MAX;
                }
                else {
                    p.contest_type_id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.contest_effect_id = INT_MAX;
                }
                else {
                    p.contest_effect_id = stoi(line);
                }

                getline(iFile, line);
                if (line == "") {
                    p.super_contest_effect_id = INT_MAX;
                }
                else {
                    p.super_contest_effect_id = stoi(line);
                }

                if (iFile.peek() == '\n') {
                    break;
                }

                pokemonData.move.push_back(p);
            }

            iFile.close();

        }
        else if (dataInput[k] == "pokemon_moves") {
            while (!iFile.eof()) {
                pokemon_moves p;
                
                getline(iFile, line, ',');
                if (line == "") { 
                    p.pokemon_id = INT_MAX; 
                }
                else {
                    p.pokemon_id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.version_group_id = INT_MAX;
                }
                else {
                    p.version_group_id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.move_id = INT_MAX;
                }
                else {
                    p.move_id = stoi(line);
                }
                
                getline(iFile, line, ',');
                if (line == "") {
                    p.pokemon_move_method_id = INT_MAX;
                }
                else {
                    p.pokemon_move_method_id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.level = INT_MAX;
                }
                else {
                    p.level = stoi(line);
                }

                getline(iFile, line);
                if (line == "") {
                    p.order = INT_MAX;
                }
                else {
                    p.order = stoi(line);
                }

                if (iFile.peek() == '\n') {
                    break;
                }

                pokemonData.poke_move.push_back(p);
            }

            iFile.close();

        }
        else if (dataInput[k] == "pokemon_species") {
            while (!iFile.eof()) {
                pokemon_species p;
                
                getline(iFile, line, ',');
                if (line == "") { 
                    p.id = INT_MAX; 
                }
                else {
                    p.id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.identifier = "";
                }
                else {
                    p.identifier = line;
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.generation_id = INT_MAX;
                }
                else {
                    p.generation_id = stoi(line);
                }
                
                getline(iFile, line, ',');
                if (line == "") {
                    p.evolves_from_species_id = INT_MAX;
                }
                else {
                    p.evolves_from_species_id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.evolution_chain_id = INT_MAX;
                }
                else {
                    p.evolution_chain_id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.color_id = INT_MAX;
                }
                else {
                    p.color_id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.shape_id = INT_MAX;
                }
                else {
                    p.shape_id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.habitat_id = INT_MAX;
                }
                else {
                    p.habitat_id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.gender_rate = INT_MAX;
                }
                else {
                    p.gender_rate = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.capture_rate = INT_MAX;
                }
                else {
                    p.capture_rate = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.base_happiness = INT_MAX;
                }
                else {
                    p.base_happiness = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.is_baby = INT_MAX;
                }
                else {
                    p.is_baby = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.hatch_counter = INT_MAX;
                }
                else {
                    p.hatch_counter = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.has_gender_differences = INT_MAX;
                }
                else {
                    p.has_gender_differences = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.growth_rate_id = INT_MAX;
                }
                else {
                    p.growth_rate_id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.forms_switchable = INT_MAX;
                }
                else {
                    p.forms_switchable = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.is_legendary = INT_MAX;
                }
                else {
                    p.is_legendary = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.is_mythical = INT_MAX;
                }
                else {
                    p.is_mythical = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.order = INT_MAX;
                }
                else {
                    p.order = stoi(line);
                }

                getline(iFile, line);
                if (line == "") {
                    p.conquest_order = INT_MAX;
                }
                else {
                    p.conquest_order = stoi(line);
                }

                if (iFile.peek() == '\n') {
                    break;
                }

                pokemonData.poke_spec.push_back(p);
            }

            iFile.close();

        }
        else if (dataInput[k] == "type_names") {
            while (!iFile.eof()) {
                type_names p;
                
                getline(iFile, line, ',');
                if (line == "") { 
                    p.type_id = INT_MAX; 
                }
                else {
                    p.type_id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.local_language_id = INT_MAX;
                }
                else {
                    p.local_language_id = stoi(line);
                }
                
                getline(iFile, line);
                if (line == "") {
                    p.name = "";
                }
                else {
                    p.name = line;
                }

                if (iFile.peek() == '\n') {
                    break;
                }

                if (p.local_language_id == 9) {
                    pokemonData.type_name.push_back(p);
                }
            }

            iFile.close();

        }
        else if (dataInput[k] == "pokemon_types") {
            while (!iFile.eof()) {
                pokemon_types p;
                
                getline(iFile, line, ',');
                if (line == "") { 
                    p.pokemon_id = INT_MAX; 
                }
                else {
                    p.pokemon_id = stoi(line);
                }

                getline(iFile, line, ',');
                if (line == "") {
                    p.type_id = INT_MAX;
                }
                else {
                    p.type_id = stoi(line);
                }

                getline(iFile, line);
                if (line == "") {
                    p.slot = INT_MAX;
                }
                else {
                    p.slot = stoi(line);
                }

                if (iFile.peek() == '\n') {
                    break;
                }

                pokemonData.poke_type.push_back(p);
            }

            iFile.close();
        }
    }

    return 0;
}

//Manages High Score data (stored in highscores.txt)
int initHighscoreData(vector<highscore_Data>& highscoreData) {
    string line;
    //Opens highscores.txt in order to later add to data vector
    ifstream iFile("highscores.txt");

    //Validates file
    if (!iFile) {
        iFile.close();
        cerr << "Error opening highscores.txt!" << endl;
        return 1;
    }

    while (!iFile.eof()) {
        highscore_Data h;

        getline(iFile, line, ',');
        if (line == "") {
            h.name = "unnamed";
        }
        else {
            h.name = line;
        }

        getline(iFile, line);
        if (line == "") {
            h.gameDuration = 999.99;
        }
        else {
            h.gameDuration = stod(line);
        }

        highscoreData.push_back(h);

        if (iFile.peek() == '\n') {
            break;
        }
    }

    iFile.close();
    return 0;
}


void createBoard(vector<WINDOW*>& win, WINDOW *background, const condition_Data& conditionData) {
    int start_y = 4, start_x = 20; // Start creating board on background
    int height = 5, width = 32; // Height and width of each cell

    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    wattron(background, COLOR_PAIR(3));
    mvwprintw(background, 2, 4, "PokeDoku");
    wattroff(background, COLOR_PAIR(3));

    mvwprintw(background, 20, 2, "-Does not include megas/regional forms");
    mvwprintw(background, 21, 2, "-Names with spaces use a dash instead");
    mvwprintw(background, 22, 2, "-Press 'q' to quit at end screen");
    wrefresh(background);
    refresh();

    //Divides board into 9 sections
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            int y = row * height;
            int x = col * width;
            int index = row * 3 + col;
            
            win[index] = newwin(height, width, y + start_y, x + start_x);
            box(win[index], 0, 0);
            wrefresh(win[index]);
            refresh();
        }
    }

    int cursorH = 0;
    int cursorV = 0;

    for (int i = 0; i < 3; i++) {
        if (conditionData.name[i] == "generation") {
            mvwprintw(background, 2, 34 + cursorH, "%s %d", conditionData.name[i].c_str(), conditionData.id[i]);
            wrefresh(background);
            refresh();
        }
        else {
            mvwprintw(background, 2, 34 + cursorH, "%s", conditionData.name[i].c_str());
            wrefresh(background);
            refresh();
        }
        cursorH += 30;
    }

    for (int i = 3; i < 6; i++) {
        if (conditionData.name[i] == "generation") {
            mvwprintw(background, 6 + cursorV, 7, "%s %d", conditionData.name[i].c_str(), conditionData.id[i]);
            wrefresh(background);
            refresh();
        }
        else {
            mvwprintw(background, 6 + cursorV, 7, "%s", conditionData.name[i].c_str());
            wrefresh(background);
            refresh();
        }
        cursorV += 5;
    }
}

int getConditions(condition_Data& conditionData, const pokemon_Data& pokemonData) {
    int fillCount = 0;
    int randomType;
    bool repeat = false;
    int i, j;

    // Fill the rest with types
    while (fillCount < 6) {
        randomType = rand() % (pokemonData.type_name.size() - 2);
        repeat = false;

        // Check for duplicates
        for (j = 0; j < fillCount; j++) {
            if (pokemonData.type_name[randomType].name == conditionData.name[j]) {
                repeat = true;
                break;
            }
        }

        if (!repeat) {
            conditionData.name.push_back(pokemonData.type_name[randomType].name);
            conditionData.id.push_back(pokemonData.type_name[randomType].type_id);
            fillCount++;
        }
    }

    int randomGen = rand() % pokemonData.poke_spec.size();
    int randomIdx = rand() % 6;
    conditionData.name[randomIdx] = "generation";
    conditionData.id[randomIdx] = (rand() % 8) + 1;

    return randomIdx;
}

void removeImpossibleCombos(condition_Data& conditionData, const pokemon_Data& pokemonData) {
    int i, j;
    int randomType;

    //Mostly brute forcing, checks for impossible combos, fixing them in the process
    for (i = 0; i < 3; i++) {
        for (j = 3; j < 6; j++) {
            if (conditionData.name[i] == "Normal" && (conditionData.name[j] == "Ice" || conditionData.name[j] == "Poison" || conditionData.name[j] == "Steel" || conditionData.name[j] == "Ghost" || conditionData.name[j] == "Bug" || conditionData.name[j] == "Rock")) {
                do {
                    randomType = rand() % (pokemonData.type_name.size() - 2);
                    conditionData.name[j] = pokemonData.type_name[randomType].name;
                    conditionData.id[j] = pokemonData.type_name[randomType].type_id;
                } while(conditionData.name[j] == "Ice" || conditionData.name[j] == "Poison" || conditionData.name[j] == "Steel" || conditionData.name[j] == "Ghost" || conditionData.name[j] == "Bug" || conditionData.name[j] == "Rock");
            }
            else if (conditionData.name[i] == "Fire" && (conditionData.name[j] == "Grass" || conditionData.name[j] == "Ice" || conditionData.name[j] == "Fairy" || conditionData.name[j] == "Electric")) {
                do {
                    randomType = rand() % (pokemonData.type_name.size() - 2);
                    conditionData.name[j] = pokemonData.type_name[randomType].name;
                    conditionData.id[j] = pokemonData.type_name[randomType].type_id;
                } while(conditionData.name[j] == "Grass" || conditionData.name[j] == "Ice" || conditionData.name[j] == "Fairy" || conditionData.name[j] == "Electric");
            }
            else if (conditionData.name[i] == "Poison" && (conditionData.name[j] == "Normal" || conditionData.name[j] == "Steel" || conditionData.name[j] == "Ice" || conditionData.name[j] == "Psychic" || conditionData.name[j] == "Fairy")) {
                do {
                    randomType = rand() % (pokemonData.type_name.size() - 2);
                    conditionData.name[j] = pokemonData.type_name[randomType].name;
                    conditionData.id[j] = pokemonData.type_name[randomType].type_id;
                } while(conditionData.name[j] == "Normal" || conditionData.name[j] == "Steel" || conditionData.name[j] == "Ice" || conditionData.name[j] == "Psychic" || conditionData.name[j] == "Fairy");
            }
            else if (conditionData.name[i] == "Ice" && (conditionData.name[j] == "Poison" || conditionData.name[j] == "Normal" || conditionData.name[j] == "Fire" || conditionData.name[j] == "Steel" || conditionData.name[j] == "Fairy")) {
                do {
                    randomType = rand() % (pokemonData.type_name.size() - 2);
                    conditionData.name[j] = pokemonData.type_name[randomType].name;
                    conditionData.id[j] = pokemonData.type_name[randomType].type_id;
                } while(conditionData.name[j] == "Poison" || conditionData.name[j] == "Normal" || conditionData.name[j] == "Fire" || conditionData.name[j] == "Steel" || conditionData.name[j] == "Fairy");
            }
            else if (conditionData.name[i] == "Fairy" && (conditionData.name[j] == "Fighting" || conditionData.name[j] == "Fire" || conditionData.name[j] == "Ground" || conditionData.name[j] == "Poison" || conditionData.name[j] == "Dragon" || conditionData.name[j] == "Ice")) {
                do {
                    randomType = rand() % (pokemonData.type_name.size() - 2);
                    conditionData.name[j] = pokemonData.type_name[randomType].name;
                    conditionData.id[j] = pokemonData.type_name[randomType].type_id;
                } while(conditionData.name[j] == "Fighting" || conditionData.name[j] == "Fire" || conditionData.name[j] == "Ground" || conditionData.name[j] == "Poison" || conditionData.name[j] == "Dragon" || conditionData.name[j] == "Ice");
            }
            else if (conditionData.name[i] == "Fighting" && (conditionData.name[j] == "Electric" || conditionData.name[j] == "Fairy" || conditionData.name[j] == "Ground")) {
                do {
                    randomType = rand() % (pokemonData.type_name.size() - 2);
                    conditionData.name[j] = pokemonData.type_name[randomType].name;
                    conditionData.id[j] = pokemonData.type_name[randomType].type_id;
                } while(conditionData.name[j] == "Electric" || conditionData.name[j] == "Fairy" || conditionData.name[j] == "Ground");
            }
            else if (conditionData.name[i] == "Steel" && (conditionData.name[j] == "Normal" || conditionData.name[j] == "Poison" || conditionData.name[j] == "Ice")) {
                do {
                    randomType = rand() % (pokemonData.type_name.size() - 2);
                    conditionData.name[j] = pokemonData.type_name[randomType].name;
                    conditionData.id[j] = pokemonData.type_name[randomType].type_id;
                } while(conditionData.name[j] == "Normal" || conditionData.name[j] == "Poison" || conditionData.name[j] == "Ice");
            }
            else if (conditionData.name[i] == "Grass" && (conditionData.name[j] == "Fire" || conditionData.name[j] == "Electric")) {
                do {
                    randomType = rand() % (pokemonData.type_name.size() - 2);
                    conditionData.name[j] = pokemonData.type_name[randomType].name;
                    conditionData.id[j] = pokemonData.type_name[randomType].type_id;
                } while(conditionData.name[j] == "Fire" || conditionData.name[j] == "Electric");
            }
            else if (conditionData.name[i] == "Ghost" && (conditionData.name[j] == "Normal")) {
                do {
                    randomType = rand() % (pokemonData.type_name.size() - 2);
                    conditionData.name[j] = pokemonData.type_name[randomType].name;
                    conditionData.id[j] = pokemonData.type_name[randomType].type_id;
                } while(conditionData.name[j] == "Normal");
            }
            else if (conditionData.name[i] == "Electric" && (conditionData.name[j] == "Fighting" || conditionData.name[j] == "Rock" || conditionData.name[j] == "Psychic" || conditionData.name[j] == "Fire" || conditionData.name[j] == "Grass")) {
                do {
                    randomType = rand() % (pokemonData.type_name.size() - 2);
                    conditionData.name[j] = pokemonData.type_name[randomType].name;
                    conditionData.id[j] = pokemonData.type_name[randomType].type_id;
                } while(conditionData.name[j] == "Fighting" || conditionData.name[j] == "Rock" || conditionData.name[j] == "Psychic" || conditionData.name[j] == "Fire" || conditionData.name[j] == "Grass");
            }
            else if (conditionData.name[i] == "Bug" && (conditionData.name[j] == "Dragon" || conditionData.name[j] == "Normal" || conditionData.name[j] == "Psychic" || conditionData.name[j] == "Dark")) {
                do {
                    randomType = rand() % (pokemonData.type_name.size() - 2);
                    conditionData.name[j] = pokemonData.type_name[randomType].name;
                    conditionData.id[j] = pokemonData.type_name[randomType].type_id;
                } while(conditionData.name[j] == "Dragon" || conditionData.name[j] == "Dark" || conditionData.name[j] == "Normal" || conditionData.name[j] == "Psychic");
            }
            else if (conditionData.name[i] == "Dragon" && (conditionData.name[j] == "Bug" || conditionData.name[j] == "Fairy")) {
                do {
                    randomType = rand() % (pokemonData.type_name.size() - 2);
                    conditionData.name[j] = pokemonData.type_name[randomType].name;
                    conditionData.id[j] = pokemonData.type_name[randomType].type_id;
                } while(conditionData.name[j] == "Bug" || conditionData.name[j] == "Fairy");
            }
            else if (conditionData.name[i] == "Dark" && (conditionData.name[j] == "Bug" || conditionData.name[j] == "Fairy")) {
                do {
                    randomType = rand() % (pokemonData.type_name.size() - 2);
                    conditionData.name[j] = pokemonData.type_name[randomType].name;
                    conditionData.id[j] = pokemonData.type_name[randomType].type_id;
                } while(conditionData.name[j] == "Bug" || conditionData.name[j] == "Fairy");
            }
            else if (conditionData.name[i] == "Ground" && (conditionData.name[j] == "Fairy" || conditionData.name[j] == "Fighting")) {
                do {
                    randomType = rand() % (pokemonData.type_name.size() - 2);
                    conditionData.name[j] = pokemonData.type_name[randomType].name;
                    conditionData.id[j] = pokemonData.type_name[randomType].type_id;
                } while(conditionData.name[j] == "Fairy" || conditionData.name[j] == "Fighting");
            }
            else if (conditionData.name[i] == "Psychic" && (conditionData.name[j] == "Poison" || conditionData.name[j] == "Electric" || conditionData.name[j] == "Bug")) {
                do {
                    randomType = rand() % (pokemonData.type_name.size() - 2);
                    conditionData.name[j] = pokemonData.type_name[randomType].name;
                    conditionData.id[j] = pokemonData.type_name[randomType].type_id;
                } while(conditionData.name[j] == "Poison" || conditionData.name[j] == "Electric" || conditionData.name[j] == "Bug");
            }
            else if (conditionData.name[i] == "Rock" && (conditionData.name[j] == "Electric" || conditionData.name[j] == "Normal")) {
                do {
                    randomType = rand() % (pokemonData.type_name.size() - 2);
                    conditionData.name[j] = pokemonData.type_name[randomType].name;
                    conditionData.id[j] = pokemonData.type_name[randomType].type_id;
                } while(conditionData.name[j] == "Electric" || conditionData.name[j] == "Normal");
            }
        }
    }
}

//Manages all user actions while in-game
int playGame(vector<WINDOW*>& win, const condition_Data& conditionData, const pokemon_Data& pokemonData, const int& generationIndex) {
    int score = 0;
    string guess;
    char buffer[100];
    int pokemonId = INT_MAX;
    int i, j, k;
    bool slot1 = false, slot2 = false;
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    for (i = 0; i < 9; i++) {
        wmove(win[i], 2, 2);
        wrefresh(win[i]);
        refresh();

        wscanw(win[i], "%s", buffer);
        guess = buffer;

        for (char& c : guess) {
            c = tolower(c);
        }

        for (k = 0; k < pokemonData.poke_spec.size(); k++) {
            if (strcmp(guess.c_str(), pokemonData.poke_spec[k].identifier.c_str()) == 0) {
                pokemonId = pokemonData.poke_spec[k].id;
            }
        }

        if (i == 0) {
            if (generationIndex == 0) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[0] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[3] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
                
            }
            else if (generationIndex == 3) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[3] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[0] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }

            }
            else {
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[0] == pokemonData.poke_type[k].type_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[3] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }

            }
        }
        else if (i == 1) {
            if (generationIndex == 1) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[1] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[3] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
            else if (generationIndex == 3) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[3] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[1] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
            else {
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[1] == pokemonData.poke_type[k].type_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[3] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
        }
        else if (i == 2) {
            if (generationIndex == 2) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[2] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[3] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
            else if (generationIndex == 3) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[3] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[2] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
            else {
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[2] == pokemonData.poke_type[k].type_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[3] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
        }
        else if (i == 3) {
            if (generationIndex == 0) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[0] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[4] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
            else if (generationIndex == 4) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[4] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[0] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
            else {
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[0] == pokemonData.poke_type[k].type_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[4] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
        }
        else if (i == 4) {
            if (generationIndex == 1) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[1] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[4] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
            else if (generationIndex == 4) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[4] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[1] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
            else {
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[1] == pokemonData.poke_type[k].type_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[4] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
        }
        else if (i == 5) {
            if (generationIndex == 2) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[2] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[4] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
            else if (generationIndex == 4) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[4] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[2] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
            else {
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[2] == pokemonData.poke_type[k].type_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[4] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
        }
        else if (i == 6) {
            if (generationIndex == 0) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[0] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[5] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
            else if (generationIndex == 5) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[5] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[0] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
            else {
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[0] == pokemonData.poke_type[k].type_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[5] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
        }
        else if (i == 7) {
            if (generationIndex == 1) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[1] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[5] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
            else if (generationIndex == 5) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[5] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[1] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
            else {
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[1] == pokemonData.poke_type[k].type_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[5] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
        }
        else if (i == 8) {
            if (generationIndex == 2) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[2] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[5] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
            else if (generationIndex == 5) {
                for (j = 0; j < pokemonData.poke_spec.size(); j++) {
                    if (pokemonId == pokemonData.poke_spec[j].id && conditionData.id[5] == pokemonData.poke_spec[j].generation_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[2] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
            else {
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[2] == pokemonData.poke_type[k].type_id) {
                        slot1 = true;
                        break;
                    }
                }
                for (k = 0; k < pokemonData.poke_type.size(); k++) {
                    if (pokemonId == pokemonData.poke_type[k].pokemon_id && conditionData.id[5] == pokemonData.poke_type[k].type_id) {
                        slot2 = true;
                        break;
                    }
                }
            }
        }

        if (slot1 && slot2) {
            wattron(win[i], COLOR_PAIR(1));
            wmove(win[i], 2, 2);
            wprintw(win[i], "%s", guess.c_str());
            wrefresh(win[i]);
            refresh();
            wattroff(win[i], COLOR_PAIR(1));
            score++;
        }
        else {
            wattron(win[i], COLOR_PAIR(2));
            wmove(win[i], 2, 2);
            wprintw(win[i], "%s", guess.c_str());
            wrefresh(win[i]);
            refresh();
            wattroff(win[i], COLOR_PAIR(2));
        }

        slot1 = false;
        slot2 = false;
        memset(buffer, 0, sizeof(buffer));
        guess.clear();
    }

    return score;
}

void writeToLeaderboard(const vector<highscore_Data>& highscoreData) {
    ofstream oFile("highscores.txt", ios::trunc);
    if (!oFile) {
        throw ios_base::failure("Failed to open highscores.txt");
    }

    for (const auto& score : highscoreData) {
        oFile << score.name << "," << score.gameDuration << endl;
    }

    oFile.close();
}

bool compareDuration(const highscore_Data& x, const highscore_Data& y) {
    const double tolerance = 1e-9;
    return (y.gameDuration - x.gameDuration) >= tolerance;
}

char displayEndScreen(WINDOW *endScreen, int score, double gameDuration, vector<highscore_Data>& highscoreData) {
    const double tolerance = 1e-9;
    highscore_Data h;
    string name;
    char input;
    char buffer[100];
    
    box(endScreen, 0, 0);
    mvwprintw(endScreen, 2, 20, "Congratulations!");
    mvwprintw(endScreen, 7, 17, "You got %d/9 correct!", score);
    mvwprintw(endScreen, 9, 8, "You completed the puzzle in %.2f seconds!", gameDuration);
    mvwprintw(endScreen, 11, 12, "Done playing? Press 'q' to quit");
    mvwprintw(endScreen, 12, 12, "Press 'T' to view the highscores");
    mvwprintw(endScreen, 13, 15, "Enter to continue playing");
    wrefresh(endScreen);
    refresh();

    if (score == 9) {
        for (int i = 0; i < highscoreData.size(); i++) {
            if ((highscoreData[i].gameDuration - gameDuration) >= tolerance) {
                mvwprintw(endScreen, 4, 6, "Please enter your name for the leaderboard: ");
                wmove(endScreen, 5, 6);
                wrefresh(endScreen);
                refresh();
                wscanw(endScreen, "%s", buffer);
                wmove(endScreen, 23, 0);
                name = buffer;
                h.name = name;
                h.gameDuration = gameDuration;
                highscoreData.push_back(h);
                sort(highscoreData.begin(), highscoreData.end(), compareDuration);
                writeToLeaderboard(highscoreData);
                break;
            }
        }
    }
    wrefresh(endScreen);
    refresh();

    noecho();
    while (input != 'q' && input != 'T' && input != '\n') {
        input = getch();
    }
    echo();
    return input;
}

char viewLeaderboard(WINDOW *leaderboard, const vector<highscore_Data>& highscoreData) {
    char input;
    box(leaderboard, 0, 0);
    mvwprintw(leaderboard, 1, 2, "High Scores:");
    for (int i = 0; i < highscoreData.size() && i < 10; i++) {
        mvwprintw(leaderboard, i + 2, 2, "%d. %s, %.2f seconds", i + 1, highscoreData[i].name.c_str(), highscoreData[i].gameDuration);
    }

    mvwprintw(leaderboard, 14, 2, "Done playing? Press 'q' to quit");
    mvwprintw(leaderboard, 15, 2, "Enter to continue playing");
    wrefresh(leaderboard);
    refresh();

    noecho();
    while (input != 'q' && input != '\n') {
        input = getch();
    }
    echo();
    return input;
}


#endif