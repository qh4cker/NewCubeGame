#include<iostream>
#include<string>
#include<conio.h>
#include<windows.h>
#include<vector>
using namespace std;

void clear() {
	system("cls");
    //cout << "\033[2J\033[1;1H";
    //clrscr();
}
/*
char getch() {
	char temp;
	cin >> temp;
	return temp;
}
*/

bool debug = false;
bool cheats = false;
int counter = 0;
char input;
char menuinput;
int currentmap = 0;
int const mapX = 41;
int const mapY = 20;
int const mapN = 7;
int spawnX;
int spawnY;
int ispawnX;
int ispawnY;
int oldplayerX;
int oldplayerY;
int playerX;
int playerY;
bool keycollected = false;
bool inversedkeycollected = false;
bool switched = false;
bool inversed = false;
const string wall = "##"; // 'w' 'f' for fake
const string grass = ",'"; // ','
const string air = "  "; // 'a'
const string lava = "//"; // 'l'
const string boxxedlava = "L\'"; // 'L'
const string player[] = {"[]", "]["};
const string spawn[] = {"<>"}; // 's'
const string ispawn[] = {"><"}; // 'S'
const string goal[] = {"{}"}; // 'g'
const string igoal[] = {"}{"}; // 'G'
const string inverter[] = {"++", "--"}; // 'i'
const string key[] = {"0+", "+0"}; // 'k'
const string door[] = {"II", "||"}; // 'd' or 'D'
const string box[] = {"%%"}; //'b'
const string plate[] = {"()", "_|"}; //'p'
const string gate[] = {"HH", "::"}; // 'h' or 'H'
const string notaswitch[] = {"_/", "\\_"}; // 'n' switch is used for switch cases


#include"map.cpp"

char dynamicmap[mapY][mapX];


/*
class boxes {
public:
    int x;
    int y;
public:
    boxes(int x, int y) : x(x), y(y) {}
    void print() const {
        cout << x << ", " << y << endl;
    }
    bool operator==(boxes other) {
        return x == other.x && y == other.y;
    }
};

vector<boxes> currentboxes;
*/

void loadmap() {
    keycollected = false;
    inversedkeycollected = false;
    switched = false;
    inversed = false;
    for (int f = 0; f < mapY; f++) {
        for (int j = 0; j < mapX; j++) {
            dynamicmap[f][j] = map[currentmap][f][j];
            switch (map[currentmap][f][j]) {
            case 's':// the regular spawn
                spawnY = f;
                spawnX = j;
                playerY = f;
                playerX = j;
                oldplayerY = f;
                oldplayerX = j;
                break;
            case 'S':// the inversed spawn
                ispawnY = f;
                ispawnX = j;
                break;
            }
        }
    }
}

bool checkforpressureplates() {
    for (int f = 0; f < mapY; f++) {
        for (int j = 0; j < mapX; j++) {
            if (dynamicmap[f][j] == 'p') {
                return false;
            }
        }
    }
    return true;
}

int main(){
startup:
    cheats = false;
    debug = false;
currentmap = 0;
    loadmap();
    //startup_menu_drawer20000
    clear();
    
    cout << 
    "##################################################################################\n"
    "##################################################################################\n"
    "####                                                                          ####\n"
    "####      _________      ___.            ________                             ####\n"
    "####      \\_   ___ \\ __ _\\_ |__   ____  /  _____/_____    _____   ____        ####\n"
    "####      /    \\  \\/|  |  \\ __ \\_/ __ \\/   \\  ___\\__  \\  /     \\_/ __ \\       ####\n"
    "####      \\     \\___|  |  / \\_\\ \\  ___/\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/       ####\n"
    "####       \\______  /____/|___  /\\___  >\\______  (____  /__|_|  /\\___  >      ####\n"
    "####              \\/          \\/     \\/        \\/     \\/      \\/     \\/       ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "####                          Type any key to begin!                          ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "####                      Published in 2025 by qhacker's                      ####\n"
    "####                                                                          ####\n"
    "##################################################################################\n"
    "##################################################################################\n";
    getch();
    goto mainmenu;


    credits:
    clear();
    cout << 
    "##################################################################################\n"
    "##################################################################################\n"
    "####                                                                          ####\n"
    "####             _____ _                 _                                    ####\n"
    "####            /__   \\ |__   __ _ _ __ | | __  _   _  ___  _   _             ####\n"
    "####              / /\\/ '_ \\ / _` | '_ \\| |/ / | | | |/ _ \\| | | |            ####\n"
    "####             / /  | | | | (_| | | | |   <  | |_| | (_) | |_| |            ####\n"
    "####             \\/   |_| |_|\\__,_|_| |_|_|\\_\\  \\__, |\\___/ \\__,_|            ####\n"
    "####                                            |___/                         ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "####    Made by Felix-Antoine Lacroix                                         ####\n"
    "####                                                                          ####\n"
    "####    For Coding class at Seminaire de Sherbrooke in 2025                   ####\n"
    "####                                                                          ####\n"
    "####    Hope you enjoyed!                                                     ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "##################################################################################\n"
    "##################################################################################\n";
    getch();
    goto mainmenu ; 



    options:
    clear();
    counter = 0;
    while (true) {
        cout <<
            "##################################################################################\n"
            "##################################################################################\n"
            "####                                                                          ####\n"
            "####                                                                          ####\n"
            "####                                                                          ####\n"
            "####                                                                          ####\n"
            "####                                Options!!!!                               ####\n"
            "####                                                                          ####\n"
            "####                                                                          ####\n";

        if (debug) {
            if (counter == 2) {
                cout <<
                    "####          #######                                          X              ####\n"
                    "####          #Debug#                                       X X               ####\n"
                    "####          #######                                        X                ####\n";
            }
            else {
                cout <<
                    "####                                                           X              ####\n"
                    "####           Debug                                        X X               ####\n"
                    "####                                                         X                ####\n";
            }
        } else {
            if (counter == 2) {
                cout <<
                    "####          #######                                       X X               ####\n"
                    "####          #Debug#                                        X                ####\n"
                    "####          #######                                       X X               ####\n";
            }
            else {
                cout <<
                    "####                                                        X X               ####\n"
                    "####           Debug                                         X                ####\n"
                    "####                                                        X X               ####\n";
            }
        }
        cout <<
            "####                                                                          ####\n";
        if (cheats) {
            if (counter == 1) {
                cout <<
                    "####          #######X                                         X              ####\n"
                    "####          #cheats#                                      X X               ####\n"
                    "####          #######X                                       X                ####\n";
            }
            else {
                cout <<
                    "####                                                           X              ####\n"
                    "####           cheats                                       X X               ####\n"
                    "####                                                         X                ####\n";
            }
        }
        else {
            if (counter == 1) {
                cout <<
                    "####          #######X                                      X X               ####\n"
                    "####          #cheats#                                       X                ####\n"
                    "####          #######X                                      X X               ####\n";
            }
            else {
                cout <<
                    "####                                                        X X               ####\n"
                    "####           cheats                                        X                ####\n"
                    "####                                                        X X               ####\n";
            }
        }
        cout <<
            "####                                                                          ####\n";

        if (counter == 0) {
            cout <<
                "####          ######                                                          ####\n"
                "####          #exit#                                                          ####\n"
                "####          ######                                                          ####\n";
        } else {
            cout <<
                "####                                                                          ####\n"
                "####           exit                                                           ####\n"
                "####                                                                          ####\n";
        }

        cout <<
            "####                                                                          ####\n"
            "##################################################################################\n"
            "##################################################################################\n";
        input = getch();
        switch (input) {
        case 's':
            counter--;
            break;
        case 'w':
            counter++;
            break;
        case 'x':
            cout << "you left" << endl;
            goto end;
        case 'q'://this is enter key
            switch (counter) {
            case 0:
                goto mainmenu;
                break;
            case 1:
                cheats = true;//this makes it so you cant put cheats back off
                break;
            case 2://this is enter key
                debug = !debug;
                break;
            }
        }
        counter = max(counter, 0);
        counter = min(counter, 2);
        clear();
    }

    tutorial:
    counter = 0;
    clear();
    while (true) {
        clear();
        switch(counter) {
            case 0:
                cout << 
                "##################################################################################\n"
                "##          //              ##        ##                                        ##\n"
                "##  %%  %%  //      ()      ##   {}   ##  Welcome to the tutorial!              ##\n" //you are a cube \"[]\" and your goal is to get to the goal \"{}\"
                "##          //              ##        ##                                        ##\n"
                "######HH######              ##   ++   ##  This is more of a slideshow btw       ##\n" // \"//\" is deadly, it returns you to spawn \"<>\"
                "##          ##              ##        ##                                        ##\n"
                "##          ##              ##        ##  Type a or d to cycle between slides   ##\n"
                "##    _/    ##              ##        ##                                        ##\n"
                "##          ##              ##        ##  And enter to exit to the main menu    ##\n"
                "##          ##              ##        ##                                        ##\n"
                "##          ##              ##        ##                                        ##\n"
                "######II######              ##        ##                                        ##\n"
                "##          ##              ##        ##                                        ##\n"
                "##    0+    ##              ##        ##                                        ##\n"
                "##          ##              ##        ##                                        ##\n"
                "##          ##      ++      ##        ##                                        ##\n"
                "##          ##              ##        ##                                        ##\n"
                "##          ##              ##   ><   ##                                        ##\n"
                "##[]        ##//////////////##        ##                                        ##\n"
                "##################################################################################\n";     
                break;
            case 1:
                cout << 
                "##################################################################################\n"
                "##          //              ##        ##                                        ##\n"
                "##  %%  %%  //      ()      ##   {}   ##  You play as a cube \"[]\"               ##\n" 
                "##          //              ##        ##                                        ##\n"
                "######HH######              ##   ++   ##  you move with \"wasd\"                  ##\n" 
                "##          ##              ##        ##                                        ##\n"
                "##          ##              ##        ##  and you want to get to the goal \"{}\"  ##\n"
                "##    _/    ##              ##        ##                                        ##\n"
                "##          ##              ##        ##                                        ##\n"
                "##          ##              ##        ##                                        ##\n"
                "##          ##              ##        ##  You also want to avoid lava \"//\"      ##\n"
                "######II######              ##        ##                                        ##\n"
                "##          ##              ##        ##  or you'll respawn at the spawn \"<>\".  ##\n"
                "##    0+    ##              ##        ##                                        ##\n"
                "##          ##              ##        ##                                        ##\n"
                "##          ##      ++      ##        ##                                        ##\n"
                "##          ##              ##        ##                                        ##\n"
                "##          ##              ##   ><   ##                                        ##\n"
                "##<>  []    ##//////////////##        ##                                        ##\n"
                "##################################################################################\n";
                break;
            case 2:
                cout <<
                    "##################################################################################\n"
                    "##          //              ##        ##                                        ##\n"
                    "##  %%  %%  //      ()      ##   {}   ##  There are some tiles you can touch    ##\n" //you are a cube \"[]\" and your goal is to get to the goal \"{}\"
                    "##          //              ##        ##                                        ##\n"
                    "######HH######              ##   ++   ##  There are keys \"0+\"                   ##\n" // \"//\" is deadly, it returns you to spawn \"<>\"
                    "##          ##              ##        ##                                        ##\n"
                    "##          ##              ##        ##  Which can open doors \"II\"             ##\n"
                    "##    _/    ##              ##        ##                                        ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "##          ##              ##        ##  There are also levers \"_/\"            ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "######II######              ##        ##  Which can open gates \"HH\"             ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "##    0+    ##              ##        ##                                        ##\n"
                    "##          ##              ##        ##  These tiles act differently if you    ##\n"
                    "##          ##      ++      ##        ##                                        ##\n"
                    "##    []    ##              ##        ##  have touched the inversed tile \"++\"   ##\n"
                    "##          ##              ##   ><   ##                                        ##\n"
                    "##<>        ##//////////////##        ##                                        ##\n"
                    "##################################################################################\n";
                break;
            case 3:
                cout <<
                    "##################################################################################\n"
                    "##          //              ##        ##                                        ##\n"
                    "##  %%  %%  //      ()      ##   {}   ##  There also are boxes \"%%\"             ##\n" //you are a cube \"[]\" and your goal is to get to the goal \"{}\"
                    "##    []    //              ##        ##                                        ##\n"
                    "######::######              ##   ++   ##                                        ##\n"
                    "##          ##              ##        ##  You can only push them around         ##\n" // \"//\" is deadly, it returns you to spawn \"<>\"
                    "##          ##              ##        ##                                        ##\n"
                    "##    _/    ##              ##        ##  You can push them into lava \"//\"      ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "##          ##              ##        ##  to make a walkable path \"L\'\"          ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "######||######              ##        ##  Or put them on pressure plates \"()\"   ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "##          ##              ##        ##  To unlock the goal                    ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "##          ##      ++      ##        ##                                        ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "##          ##              ##   ><   ##                                        ##\n"
                    "##<>        ##//////////////##        ##                                        ##\n"
                    "##################################################################################\n";
                break;
            case 4:
                cout <<
                    "##################################################################################\n"
                    "##          //              ##        ##                                        ##\n"
                    "##          L\'      %%      ##   {}   ##  The inverter \"++\" allows you to       ##\n" //you are a cube \"[]\" and your goal is to get to the goal \"{}\"
                    "##          //              ##        ##                                        ##\n"
                    "######::######              ##   ++   ##  become inverted, this has various     ##\n" // \"//\" is deadly, it returns you to spawn \"<>\"
                    "##          ##              ##        ##                                        ##\n"
                    "##          ##              ##        ##  effects.                              ##\n"
                    "##    _/    ##              ##        ##                                        ##\n"
                    "##          ##              ##        ##  For example, if you were to die,      ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "##          ##              ##        ##  you would respawn at the inverted     ##\n"
                    "######||######              ##        ##                                        ##\n"
                    "##          ##      []      ##        ##  spawn \"><\"                            ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "##          ##      ++      ##        ##                                        ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "##          ##              ##   ><   ##                                        ##\n"
                    "##<>        ##//////////////##        ##                                        ##\n"
                    "##################################################################################\n";
                break;
            case 5:
                cout <<
                    "##################################################################################\n"
                    "##          //              ##        ##                                        ##\n"
                    "##          L\'      %%      ##   {}   ##  Btw, you have to be uninverted        ##\n" //you are a cube \"[]\" and your goal is to get to the goal \"{}\"
                    "##          //              ##        ##                                        ##\n"
                    "######::######              ##   --   ##  to enter the regular portals          ##\n" // \"//\" is deadly, it returns you to spawn \"<>\"
                    "##          ##              ##        ##                                        ##\n"
                    "##          ##              ##        ##  otherwise it will have no effects     ##\n"
                    "##    _/    ##              ##        ##                                        ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "##          ##              ##   ][   ##                                        ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "######||######              ##        ##                                        ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "##          ##      --      ##        ##  You should now be ready to brace      ##\n"
                    "##          ##              ##        ##                                        ##\n"
                    "##          ##              ##   ><   ##  the dangers of the levels GLHF :D     ##\n"
                    "##<>        ##//////////////##        ##                                        ##\n"
                    "##################################################################################\n";
                break;
        }

        input = getch();
        switch(input){
            case 'a':
                counter--;
                break;
            case 'd':
                counter++;
                break; 
            case 'q'://this is enter key
                goto mainmenu; 
            case 'x':
                cout << "you left" << endl;
                goto end;
        }
 		counter = max(counter,0);
		counter = min(counter,5);    
    }

    mainmenu:
    counter = 2;
    while (true) {
        clear();
        //menu_drawer2000  

    cout << 
    "##################################################################################\n"
    "##################################################################################\n"
    "####                                                                          ####\n"
    "####                           _                                              ####\n"
    "####               /\\/\\   __ _(_)_ __     /\\/\\   ___ _ __  _   _              ####\n"
    "####              /    \\ / _` | | '_ \\   /    \\ / _ \\ '_ \\| | | |             ####\n"
    "####             / /\\/\\ \\ (_| | | | | | / /\\/\\ \\  __/ | | | |_| |             ####\n"
    "####             \\/    \\/\\__,_|_|_| |_| \\/    \\/\\___|_| |_|\\__,_|             ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n";
    switch(counter){

        case 0:
            cout << 
            "####           #########                                                      ####\n"
            "####           #restart#   tutorial    start    options    credits            ####\n"
            "####           #########                                                      ####\n";   
            break;
        case 1:
            cout << 
            "####                      ##########                                          ####\n"
            "####            restart   #tutorial#   start    options    credits            ####\n"
            "####                      ##########                                          ####\n";   
            break;
        case 2:
            cout << 
            "####                                  #######                                 ####\n"
            "####            restart    tutorial   #start#   options    credits            ####\n"
            "####                                  #######                                 ####\n";   
            break;
        case 3:
            cout << 
            "####                                           #########                      ####\n"
            "####            restart    tutorial    start   #options#   credits            ####\n"
            "####                                           #########                      ####\n";   
            break;
        case 4:
            cout << 
            "####                                                      #########           ####\n"
            "####            restart    tutorial    start    options   #credits#           ####\n"
            "####                                                      #########           ####\n";   
            break;
    }

    cout << 
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "##################################################################################\n"
    "##################################################################################\n";

        //menu_input_is_sigma17000
        input = getch();
        switch(input){
            case 'a':
                counter--;
                break;
            case 'd':
                counter++;
                break; 
            case 'q'://this is enter key
                switch(counter){
                    case 0:
                        goto startup;
                    case 1:
                        goto tutorial;
                    case 2:
                        goto game;
                    case 3:
                        goto options;
                    case 4:
                        goto credits;
                } 
            case 'x':
                cout << "you left" << endl;
                goto end;
        }
 		counter = max(counter,0);
		counter = min(counter,4);       
    }// end of mainmenu loop


    newmap:
    //load the spawn of the first map
    loadmap();

    //############################################ game here
    game:

    while (true){
    //map_drawer3000
    string temp;
	for (int f = 0; f < mapY; f++){

		for (int j = 0; j < mapX; j++) {

            if ((playerX == j)&&(playerY == f)){
                if (inversed) {
                    temp +=player[1];
                } else {
                    temp +=player[0];
                }
                continue;
            }

		switch(dynamicmap[f][j]){
        case 'w':
           	temp += wall;
      		break;
        case 'f':
            temp += wall;
            break;
        case 'a':
           	temp +=air;
      		break;
     	case 's':
           	temp +=spawn[0];
   		    break;
     	case 'S':
           	temp +=ispawn[0];
   		    break;
		case 'g':
		    temp +=goal[0];
			break;
		case 'G':
		    temp +=igoal[0];
			break;
		case 'd':
            if (keycollected || inversedkeycollected) {
                temp += door[1];
                break;
            } else {
                temp += door[0];
                break;
            }
        case 'D':
            if (keycollected || inversedkeycollected) {
                temp += door[0];
                break;
            } else {
                temp += door[1];
                break;
            }
        case 'h':
            if (switched) {
                temp += gate[1];
                break;
            } else {
                temp += gate[0];
                break;
            }
        case 'H':
            if (!switched) {
                temp += gate[1];
                break;
            }
            else {
                temp += gate[0];
                break;
            }
        case 'n':
            if (switched) {
                temp += notaswitch[1];
                break;
            } else {
                temp += notaswitch[0];
                break;
            }

		case 'l':
			temp +=lava;
			break;
        case 'L':
            temp += boxxedlava;
            break;
		case 'k':
            if (keycollected || inversedkeycollected) {
                temp += air;
            } else {
                if (inversed) {
                    temp += key[1];
                }
                else {
                    temp += key[0];
                }
            }
			break;
		case 'b':
			temp +=box[0];
			break;
		case 'p':
			temp +=plate[0];
			break;
		case 'i':
                if (inversed) {
                    temp +=inverter[1];
                } else {
                    temp +=inverter[0];
                }
			break;
            }
		}
        temp += "\n";
	}        
	    clear();
            cout << temp;

        //sigma_displayer_7000
            if (debug) {
                cout << "playerX: " <<playerX << endl;
                cout << "playerY: " <<playerY << endl;
                cout << "currentmap: " <<currentmap << endl;
	            cout << "inversed: " <<inversed << endl;
                cout << "spawnX: " <<spawnX << endl;
                cout << "spawnY: " <<spawnY << endl;
                cout << "ispawnX: " <<ispawnX << endl;
                cout << "ispawnY: " <<ispawnY << endl;
                cout << "keycollected: " << keycollected << endl;
                cout << "invertedkeycollected: " << inversedkeycollected << endl;
                cout << "switeched?: " << switched << endl;
            }
        //input_gatherer_4000
        input = getch();
        switch(input){
            case 'w':
                cout << "you go up" << endl;
                playerY--;
                break;
            case 'a':
                cout << "you go left" << endl;
                playerX--;
                break;
            case 's':
                cout << "you go down" << endl;
                playerY++;
                break;
            case 'd':
                cout << "you go right" << endl;
                playerX++;
                break; 
            case 'e':
                if (cheats) {
                cout << "you go back in time" << endl;
                currentmap--;
                loadmap();
                }
                break; 
            case 'r':
                if (cheats) {
                cout << "you go foward in time" << endl;
                currentmap++;
                loadmap();
                }
                break; 
            case 'f':
                cout << "you feel like going backwards" << endl;
                inversed = !inversed;
                break; 
            case 'q':
                cout << "you go back" << endl;
                goto mainmenu;
                break; 
            case 'x':
                cout << "you leave" << endl;
                goto end;
                break; 
        }

        //mapupdater77000

        //relax, ill handle these events "TM"
        switch (dynamicmap[playerY][playerX]) {
        case 'w':
            playerX = oldplayerX;
            playerY = oldplayerY;
            break;
        case 'a':
            oldplayerX = playerX;
            oldplayerY = playerY;
            break;
        case 'L':
            oldplayerX = playerX;
            oldplayerY = playerY;
            break;
        case 'f':
            oldplayerX = playerX;
            oldplayerY = playerY;
            break;
        case 's':
            oldplayerX = playerX;
            oldplayerY = playerY;
            break;
        case 'S':
            oldplayerX = playerX;
            oldplayerY = playerY;
            break;
        case 'l':
            if (inversed) {
                playerX = ispawnX;
                playerY = ispawnY;
                oldplayerX = ispawnX;
                oldplayerY = ispawnY;
            }
            else {
                playerX = spawnX;
                playerY = spawnY;
                oldplayerX = spawnX;
                oldplayerY = spawnY;
                keycollected = 0;
            }
            break;
        case 'b':
            switch (input) {
            case 'w':
                if ((dynamicmap[playerY - 1][playerX] != 'b') && (dynamicmap[playerY - 1][playerX] != 'w')) {
                    if ((dynamicmap[playerY - 1][playerX] == 'd')) {
                        if (!keycollected) {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                            break;
                        }//This checks for doors
                    }
                        if ((dynamicmap[playerY - 1][playerX] == 'D')) {
                            if (keycollected) {
                                playerX = oldplayerX;
                                playerY = oldplayerY;
                                break;
                        }//This checks for doors
                    }
                    if ((dynamicmap[playerY - 1][playerX] == 'h')) {
                        if (!switched) {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                            break;
                        }//This checks for doors
                    }
                    if ((dynamicmap[playerY - 1][playerX] == 'H')) {
                        if (switched) {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                            break;
                        }//This checks for doors
                    }
                    if ((dynamicmap[playerY - 1][playerX] == 'l')) {
                        dynamicmap[playerY - 1][playerX] = 'L';
                        goto bypassw;
                    }

                    dynamicmap[playerY - 1][playerX] = 'b';
                bypassw:
                    oldplayerX = playerX;
                    oldplayerY = playerY;

                    switch (map[currentmap][playerY][playerX]) {
                    case 'b':
                        dynamicmap[playerY][playerX] = 'a';
                        break;
                    case 'k':
                        dynamicmap[playerY][playerX] = 'a';
                        break;

                    }
                    if (map[currentmap][playerY][playerX] != 'b') {//check for what was behind the box
                        dynamicmap[playerY][playerX] = map[currentmap][playerY][playerX];
                        if (keycollected && (map[currentmap][playerY][playerX] == 'k')) dynamicmap[playerY][playerX] = 'a';
                        if (map[currentmap][playerY][playerX] == 'l') dynamicmap[playerY][playerX] = 'L';
                    }
                    else {
                        dynamicmap[playerY][playerX] = 'a';
                    }
                }
                else {
                    playerX = oldplayerX;
                    playerY = oldplayerY;
                }
                break;
            case 'a':
                if ((dynamicmap[playerY][playerX - 1] != 'b') && (dynamicmap[playerY][playerX - 1] != 'w')) {
                    if ((dynamicmap[playerY][playerX - 1] == 'd')) {
                        if (!keycollected) {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                            break;
                        }//This checks for doors
                    }
                    if ((dynamicmap[playerY][playerX - 1] == 'D')) {
                        if (keycollected) {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                            break;
                        }//This checks for doors
                    }
                    if ((dynamicmap[playerY][playerX - 1] == 'h')) {
                        if (!switched) {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                            break;
                        }//This checks for doors
                    }
                    if ((dynamicmap[playerY][playerX - 1] == 'H')) {
                        if (switched) {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                            break;
                        }//This checks for doors
                    }
                    if ((dynamicmap[playerY][playerX - 1] == 'l')) {
                        dynamicmap[playerY][playerX - 1] = 'L';
                        goto bypassa;
                    }

                    dynamicmap[playerY][playerX - 1] = 'b';
                bypassa:
                    oldplayerX = playerX;
                    oldplayerY = playerY;

                    switch (map[currentmap][playerY][playerX]) {
                    case 'b':
                        dynamicmap[playerY][playerX] = 'a';
                        break;
                    case 'k':
                        dynamicmap[playerY][playerX] = 'a';
                        break;

                    }
                    if (map[currentmap][playerY][playerX] != 'b') {//check for what was behind the box
                        dynamicmap[playerY][playerX] = map[currentmap][playerY][playerX];
                        if (keycollected && (map[currentmap][playerY][playerX] == 'k')) dynamicmap[playerY][playerX] = 'a';
                        if (map[currentmap][playerY][playerX] == 'l') dynamicmap[playerY][playerX] = 'L';
                    }
                    else {
                        dynamicmap[playerY][playerX] = 'a';
                    }
                }
                else {
                    playerX = oldplayerX;
                    playerY = oldplayerY;
                }
                break;
            case 's':
                if ((dynamicmap[playerY + 1][playerX] != 'b') && (dynamicmap[playerY + 1][playerX] != 'w')) {
                    if ((dynamicmap[playerY + 1][playerX] == 'd')) {
                        if (!keycollected) {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                            break;
                        }//This checks for doors
                    }
                    if ((dynamicmap[playerY + 1][playerX] == 'D')) {
                        if (keycollected) {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                            break;
                        }//This checks for doors
                    }
                    if ((dynamicmap[playerY + 1][playerX] == 'h')) {
                        if (!switched) {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                            break;
                        }//This checks for doors
                    }
                    if ((dynamicmap[playerY + 1][playerX] == 'H')) {
                        if (switched) {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                            break;
                        }//This checks for doors
                    }
                    if ((dynamicmap[playerY + 1][playerX] == 'l')) {
                        dynamicmap[playerY + 1][playerX] = 'L';
                        goto bypassS;
                    }

                    dynamicmap[playerY + 1][playerX] = 'b';
                bypassS:
                    oldplayerX = playerX;
                    oldplayerY = playerY;

                    switch (map[currentmap][playerY][playerX]) {
                    case 'b':
                        dynamicmap[playerY][playerX] = 'a';
                        break;
                    case 'k':
                        dynamicmap[playerY][playerX] = 'a';
                        break;

                    }
                    if (map[currentmap][playerY][playerX] != 'b') {//check for what was behind the box
                        dynamicmap[playerY][playerX] = map[currentmap][playerY][playerX];
                        if (keycollected && (map[currentmap][playerY][playerX] == 'k')) dynamicmap[playerY][playerX] = 'a';
                        if (map[currentmap][playerY][playerX] == 'l') dynamicmap[playerY][playerX] = 'L';
                    }
                    else {
                        dynamicmap[playerY][playerX] = 'a';
                    }
                }
                else {
                    playerX = oldplayerX;
                    playerY = oldplayerY;
                }
                break;
            case 'd':
                if ((dynamicmap[playerY][playerX + 1] != 'b') && (dynamicmap[playerY][playerX + 1] != 'w')) {
                    if ((dynamicmap[playerY][playerX + 1] == 'd')) {
                        if (!keycollected) {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                            break;
                        }//This checks for doors
                    }
                    if ((dynamicmap[playerY][playerX + 1] == 'D')) {
                        if (keycollected) {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                            break;
                        }//This checks for doors
                    }
                    if ((dynamicmap[playerY][playerX + 1] == 'h')) {
                        if (!switched) {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                            break;
                        }//This checks for doors
                    }
                    if ((dynamicmap[playerY][playerX + 1] == 'H')) {
                        if (switched) {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                            break;
                        }//This checks for doors
                    }
                    if ((dynamicmap[playerY][playerX + 1] == 'l')) {
                        dynamicmap[playerY][playerX + 1] = 'L';
                        goto bypassD;
                    }

                    dynamicmap[playerY][playerX + 1] = 'b';
                bypassD:
                    oldplayerX = playerX;
                    oldplayerY = playerY;

                    switch (map[currentmap][playerY][playerX]) {
                    case 'b':
                        dynamicmap[playerY][playerX] = 'a';
                        break;
                    case 'k':
                        dynamicmap[playerY][playerX] = 'a';
                        break;

                    }
                    if (map[currentmap][playerY][playerX] != 'b') {//check for what was behind the box
                        dynamicmap[playerY][playerX] = map[currentmap][playerY][playerX];
                        if (keycollected && (map[currentmap][playerY][playerX] == 'k')) dynamicmap[playerY][playerX] = 'a';
                        if (map[currentmap][playerY][playerX] == 'l') dynamicmap[playerY][playerX] = 'L';
                    }
                    else {
                        dynamicmap[playerY][playerX] = 'a';
                    }
                }
                else {
                    playerX = oldplayerX;
                    playerY = oldplayerY;
                }
                break;
            }
            break;

        case 'g':
            if (checkforpressureplates() && !inversed) {
                oldplayerX = playerX;
                oldplayerY = playerY;
                currentmap++;
                goto newmap;
            }
        case 'G':
            if (checkforpressureplates() && inversed) {
                oldplayerX = playerX;
                oldplayerY = playerY;
                currentmap--;
                goto newmap;
            }
        case 'p':
            oldplayerX = playerX;
            oldplayerY = playerY;
            break;

        case 'd':
            if (keycollected || inversedkeycollected) {
                oldplayerX = playerX;
                oldplayerY = playerY;
            }
            else {
                playerX = oldplayerX;
                playerY = oldplayerY;
            }
            break;
        case 'D':
            if (keycollected || inversedkeycollected) {
                playerX = oldplayerX;
                playerY = oldplayerY;
            } else {
                oldplayerX = playerX;
                oldplayerY = playerY;
            }
            break;
        case 'k':
            oldplayerX = playerX;
            oldplayerY = playerY;
            if (inversed) {
                inversedkeycollected = true;
            }
            else {
                keycollected = true;
            }

            break;
        case 'n': // da switch
            oldplayerX = playerX;
            oldplayerY = playerY;
            switched = !switched;
            break;
        case 'h':
            if (switched) {
                oldplayerX = playerX;
                oldplayerY = playerY;
            }
            else {
                playerX = oldplayerX;
                playerY = oldplayerY;
            }
            break;
        case 'H':
            if (!switched) {
                oldplayerX = playerX;
                oldplayerY = playerY;
            }
            else {
                playerX = oldplayerX;
                playerY = oldplayerY;
            }
            break;
        case 'i':
            oldplayerX = playerX;
            oldplayerY = playerY;
            inversed = !inversed;
            break;
            //case 'b':

        }



        

    } //end of game 
    end:
    return 0;
} // end of main
