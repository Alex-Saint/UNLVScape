#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// global constants
const int MAX_INVENTORY = 24, MAX_BANK = 24,
          MAP_X_SIZE = 30, MAP_Y_SIZE = 15;

// data type for map items
struct Entity
{
    double chance = 1.0;
    string type = "";
};

// data type for player
struct Player
{
    int inventorySize = 0, position[2] = {14, 7};
    Entity inventory[MAX_INVENTORY];
};

// prototypes
void readMap(Entity[MAP_Y_SIZE][MAP_X_SIZE]);
void displayMap(Entity[MAP_Y_SIZE][MAP_X_SIZE], Player);
void displayInventory(Player);
void displayBank(Entity[MAX_BANK], int);
string getCommand();
// PLACE YOUR PROTOTYPES FOR move(), chop(), mine(), bank() HERE

int main()
{
    // variables
    int bankSize = 0;
    string command = "";
    Player player;
    Entity map[MAP_Y_SIZE][MAP_X_SIZE], storage[MAX_BANK];
    srand(0);
    // get the map
    readMap(map);
    while (true)
    {
        // show map/inventory
        displayMap(map, player);
        displayInventory(player);
        displayBank(storage, bankSize);

        // display error from previous command if needed
        if (command != "")
            cout << command << endl;

        // get command
        command = getCommand();

        // perform command
        if (command == "move")
        {
            // PLACE YOUR FUNCTION CALL FOR MOVING HERE
        }
        else if (command == "chop")
        {
            // PLACE YOUR FUNCTION CALL FOR CHOPPING HERE
        }
        else if (command == "mine")
        {
            // PLACE YOUR FUNCTION CALL FOR MINING HERE
        }
        else if (command == "bank")
        {
            // PLACE YOUR FUNCTION CALL FOR BANKING HERE
        }
        else if (command == "exit")
        {
            break;
        }
    }
    return 0;
}

// reads from "map.csv" into passed map array
void readMap(Entity map[MAP_Y_SIZE][MAP_X_SIZE])
{
    // PLACE YOUR CODE TO READ MAP FROM .csv HERE
}

// prints passed map with player on it
void displayMap(Entity map[MAP_Y_SIZE][MAP_X_SIZE], Player player)
{
    // top line
    cout << left << "\n*  ";
    for (int x = 0; x < MAP_X_SIZE; x++)
        cout << setw(3) << x;
    cout << " *\n";
    // map
    for (int y = 0; y < MAP_Y_SIZE; y++)
    {
        // output row number
        cout << left << setw(3) << y;
        // output all items in the row
        for (int x = 0; x < MAP_X_SIZE; x++)
        {
            cout << setw(3);
            // output 'p' for player
            if (x == player.position[0] && y == player.position[1])
                cout << 'p';
            // output first character of type if entity at space
            else if (map[y][x].type != "")
                cout << char(tolower(map[y][x].type[0]));
            // output blank if nothing at space
            else
                cout << "";
        }
        // end of line
        cout << right << setw(2) << y << endl;
    }
    // bottom line
    cout << left << "*  ";
    for (int x = 0; x < MAP_X_SIZE; x++)
        cout << setw(3) << x;
    cout << " *\n";
}

// prints passed inventory
void displayInventory(Player player)
{
    // don't output if nothing in inventory
    if (player.inventorySize == 0)
        return;
    // inventory label
    cout << "Inventory: ";
    // output each item in inventory's type separated by commas
    for (int i = 0; i < player.inventorySize; i++)
        cout << player.inventory[i].type
             << ((i < player.inventorySize - 1) ? ", " : "\n");
}

// prints passsed bank
void displayBank(Entity storage[MAX_BANK], int size)
{
    // don't output if nothing in bank
    if (size == 0)
        return;
    // inventory label
    cout << "Bank: ";
    // output each item in bank's type separated by commas
    for (int i = 0; i < size; i++)
        cout << storage[i].type << ((i < size - 1) ? ", " : "\n");
}

// gets a valid command from the user in lowercase
string getCommand()
{
    string command = "";
    // loop until valid command is entered
    do
    {
        // get command
        cout << "Command: ";
        getline(cin, command);
        // lowercase command
        for (unsigned int i = 0; i < command.length(); i++)
            command[i] = tolower(command[i]);
        // error check command
        if (command != "move" && command != "chop" &&
            command != "mine" && command != "bank" &&
            command != "exit")
        {
            cout << "Invalid command!\n";
        }
    } while (command != "move" && command != "chop" &&
             command != "mine" && command != "bank" &&
             command != "exit");
    // return the command (in all lower case)
    return command;
}

// returns a pseudo-random number each time called
double rng()
{
    // generates a pseudo-random double and returns it
    // seed the generator initially
    static unsigned int seed = 0;

    // parameters for the LCG
    unsigned int a = 1103515245;
    unsigned int c = 12345;
    unsigned int m = 2147483648; // 2^31

    // generate new seed
    seed = (a * seed + c) % m;
    return seed / static_cast<double>(RAND_MAX);
}

// PLACE YOUR move() FUNCTION HERE

// PLACE YOUR chop() FUNCTION HERE

// PLACE YOUR mine() FUNCTION HERE

// PLACE YOUR bank() FUNCTION HERE
