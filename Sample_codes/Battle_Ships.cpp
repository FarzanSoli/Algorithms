#include <iostream>
#include <string>
#include <random>
/* ---------------------------------------------- */ 
// Generate random int in the interval [initial, last]
int random_int(int initial, int last) 
{
    static std::random_device rd;  // Random device engine, usually based on /dev/random on UNIX-like systems
    static std::mt19937_64 gen(rd()); // Initialize Mersennes' twister using rd to generate the seed
    static std::uniform_int_distribution<int> distribution(initial, last);
    return distribution(gen);  // Use gen as a generator
}
/* ---------------------------------------------- */ 
/* Create the grid */
class Grid{
    public: 
        int x_dim, y_dim;
        // one must select right ship size to make a successful hit. One can obtain higher score by hiting a ship with bigger size.
        int ship_size; 
        void Grid_dims(){
            std::cout << std::endl; 
            std::cout << "Enter the X-dimension of the grid: ";
            std::cin >> x_dim;
            std::cout << "Enter the Y-dimension of the grid: ";
            std::cin >> y_dim;
            std::cout << "Enter the max score assigned to ships: ";
            std::cin >> ship_size;
            std::cout << std::endl; 
        };
};
/* ---------------------------------------------- */ 
/* Game Configuration */
class Game_Config{
    public:
        int hits = 0;
        int max_hits;
        int total_score = 0;
        void config(){
            std::cout << "How many hits can be played by a player" << std::endl;
            std::cin >> max_hits;
        }

};
/* ---------------------------------------------- */ 
/* Play */
class Make_move{
    public:
        int row, column;
        int score;
        void attack(){
            std::cout << "*** Selecting coordinates: *** " << std::endl;
            std::cout << "select x-coordinate" << std::endl;
            std::cin >> row;
            std::cout << "select y-coordinate" << std::endl;
            std::cin >> column;
            std::cout << "Select the ship size you think you hit" << std::endl;
            std::cin >> score;
        };
};
/* ---------------------------------------------- */ 
int main (){
    Grid build;
    build.Grid_dims();
    int ships[build.x_dim][build.y_dim]{};
    for (auto &rows : ships){
        for (auto &elements: rows){
            elements = random_int(0, build.ship_size);
            std::cout << elements << " ";
        }
        std::cout << std::endl;
    }
    /* --------------------------- */ 
    Game_Config game;
    game.config();
    /* --------------------------- */ 
    Make_move play;
    /* --------------------------- */ 
    while (game.hits < game.max_hits){
        play.attack();
        if (play.score == ships[play.row][play.column]) {
            std::cout << "It's a HIT!  " << (game.max_hits - game.hits - 1) << " Number of hits left.\n";
            game.hits++;
            game.total_score += play.score;
        }
        else {
            std::cout << "You MISSED the ship!  " << (game.max_hits - game.hits - 1) << " Number of hits left.\n";
        }
    }
    /* --------------------------- */ 
    std::cout << "You ran out of hits!\n";
    std::cout << "Your total score is: " << game.total_score << std::endl;
    return 0;
}



