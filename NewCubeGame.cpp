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

int counter = 0;
char input;
char menuinput;
int currentmap = 0;
int const mapX = 41;
int const mapY = 20;
int const mapN = 2;
int spawnX;
int spawnY;
int ispawnX;
int ispawnY;
int oldplayerX;
int oldplayerY;
int playerX;
int playerY;
int keynumber = 0;
bool inversed = false;
const string wall = "##"; // 'w'
const string block = "_|"; 
const string air = "  "; // 'a'
const string player[] = {"[]", "]["};
const string spawn[] = {"<>"}; // 's'
const string ispawn[] = {"><"}; // 'S'
const string goal[] = {"{}"}; // 'g'
const string igoal[] = {"}{"}; // 'G'
const string lava[] = {"//","L\'"}; // 'l'
const string inverter[] = {"++", "--"}; // 'i'
const string key[] = {"0+", "+0"}; // 'k'
const string door[] = {"II", "||"}; // 'd' 
const string box[] = {"%%"}; //'b'
const string plate[] = {"()"}; //'p'

#include"map.cpp"

char dynamicmap[mapY][mapX];



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


void loadmap() {
    for (int f = 0; f < mapY; f++) {
        for (int j = 0; j < mapX; j++) {
            dynamicmap[f][j] = map[currentmap][f][j];
            switch (map[currentmap][f][j]) {
            case 's':
                spawnY = f;
                spawnX = j;
                playerY = f;
                playerX = j;
                oldplayerY = f;
                oldplayerX = j;
                break;
            case 'S':
                ispawnY = f;
                ispawnX = j;
                break;
            case 'b':
                boxes temp = boxes(f, j);
                currentboxes.push_back(temp);
                break;
            }
        }
    }
}

int main(){
startup:

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
    while (true) {
    cout << 
    "##################################################################################\n"
    "##################################################################################\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "####            Options ig                                                    ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "####                        idk what to put pls give me ideas at              ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "####                             felixantoinelacroix@gmail.com                ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "####                                                                          ####\n"
    "##################################################################################\n"
    "##################################################################################\n";
    getch();
    goto mainmenu ; 
    }
        /*
    pq :: gates _/ and \_ for levers


[> door

<] exit door

 one-way? 


 block not lava?
 block in lava?
 */
    tutorial:
    counter = 0;
    clear();
    while (true) {
        clear();
        switch(counter) {
            case 0:
                cout << 
                "##################################################################################\n"
                "##                                  {}##                                        ##\n"
                "##                                    ##  Welcome to the tutorial!              ##\n" //you are a cube \"[]\" and your goal is to get to the goal \"{}\"
                "##                                    ##                                        ##\n"
                "##                                    ##  This is more of a slideshow btw       ##\n" // \"//\" is deadly, it returns you to spawn \"<>\"
                "##                                    ##                                        ##\n"
                "##                                    ##  Type a or d to cycle between slides   ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##  And enter to exit to the main menu    ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##                                        ##\n"
                "##[]                                  ##                                        ##\n"
                "##################################################################################\n";     
                break;
            case 1:
                cout << 
                "##################################################################################\n"
                "##                                  {}##                                        ##\n"
                "##                                    ##  You play as a cube \"[]\"               ##\n" //you are a cube \"[]\" and your goal is to get to the goal \"{}\"
                "##                                    ##                                        ##\n"
                "##                                    ##  you move with \"wasd\"                  ##\n" // \"//\" is deadly, it returns you to spawn \"<>\"
                "##                                    ##                                        ##\n"
                "##                                    ##  and you want to get to the goal \"{}\"  ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##  You also want to avoid lava \"//\"      ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##                                        ##\n"
                "##                                    ##                                        ##\n"
                "##<>  []                              ##                                        ##\n"
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
		counter = min(counter,4);    
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
    clear();
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
			temp +=door[0];
			break;
		case 'l':
			temp +=lava[0];
			break;
		case 'k':
                if (inversed) {
                    temp +=key[1];
                } else {
                    temp +=key[0];
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
            cout << temp;

        //sigma_displayer_7000
        cout << "playerX: " <<playerX << endl;
        cout << "playerY: " <<playerY << endl;
        cout << "currentmap: " <<currentmap << endl;
	    cout << "inversed: " <<inversed << endl;
        cout << "spawnX: " <<spawnX << endl;
        cout << "spawnY: " <<spawnY << endl;
        cout << "ispawnX: " <<ispawnX << endl;
        cout << "ispawnY: " <<ispawnY << endl;








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
                cout << "you go back in time" << endl;
                currentmap--;
                loadmap();
                break; 
            case 'r':
                cout << "you go foward in time" << endl;
                currentmap++;
                loadmap();
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
        switch(dynamicmap[playerY][playerX]) {
            case 'w':
                playerX = oldplayerX;
                playerY = oldplayerY;
                break;
            case 'a':
                oldplayerX = playerX;
                oldplayerY = playerY;
                break;
            case 's':
                oldplayerX = playerX;
                oldplayerY = playerY;
                break;
	        case 'l':
                if (inversed) {
  		            playerX = ispawnX;
		            playerY = ispawnY;
		            oldplayerX = ispawnX;
		            oldplayerY = ispawnY;         
                } else {
 		            playerX = spawnX;
		            playerY = spawnY;
		            oldplayerX = spawnX;
		            oldplayerY = spawnY;           
                }
		        break;
	        case 'b':
                
                //for (int i = 0; i < currentboxes.size(); i++) {
                    //boxes& temporaryvec = currentboxes[i]; //goes through all the boxes
                    //temporaryvec.print();
                    //cout << endl;
                    //if (temporaryvec == boxes(playerY, playerX)) {// if it matches the players pos
                        //cout << "touching player" << endl;


                        switch(input) {//checks where the player moved into the box from
                    case 'w':
                        if ((dynamicmap[playerY - 1][playerX] != 'b') && (dynamicmap[playerY - 1][playerX] != 'w')) {
                            oldplayerX = playerX;
                            oldplayerY = playerY;
                            //playerY++;
                            dynamicmap[playerY - 1][playerX] = 'b';
                            
                            if (map[currentmap][playerY][playerX] != 'b') {//check for what was behind the box
                                dynamicmap[playerY][playerX] = map[currentmap][playerY][playerX];
                            } else {
                                dynamicmap[playerY][playerX] = 'a';
                            }
                        } else {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                        }

                        break;
                    case 'a':
                        if ((dynamicmap[playerY][playerX -1] != 'b') && (dynamicmap[playerY][playerX -1] != 'w')) {
                            oldplayerX = playerX;
                            oldplayerY = playerY;
                            //playerX--;
                            dynamicmap[playerY][playerX -1] = 'b';
                            if (map[currentmap][playerY][playerX] != 'b') {
                                dynamicmap[playerY][playerX] = map[currentmap][playerY][playerX];
                            } else {
                                dynamicmap[playerY][playerX] = 'a';
                            }
                        } else {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                        }
                        break;
                    case 's':
                        if ((dynamicmap[playerY +1][playerX] != 'b') && (dynamicmap[playerY +1][playerX] != 'w')) {
                            oldplayerX = playerX;
                            oldplayerY = playerY;
                            //playerY--;
                            dynamicmap[playerY + 1][playerX] = 'b';
                            if (map[currentmap][playerY][playerX] != 'b') {
                                dynamicmap[playerY][playerX] = map[currentmap][playerY][playerX];
                            } else {
                                dynamicmap[playerY][playerX] = 'a';
                            }
                        } else {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                        } 
                        break;
                    case 'd':
                        if ((dynamicmap[playerY][playerX +1] != 'b') && (dynamicmap[playerY][playerX +1] != 'w')) {
                            oldplayerX = playerX;
                            oldplayerY = playerY;
                            //playerX++;
                            dynamicmap[playerY][playerX + 1] = 'b';
                            if (map[currentmap][playerY][playerX] != 'b') {
                                dynamicmap[playerY][playerX] = map[currentmap][playerY][playerX];
                            } else {
                                dynamicmap[playerY][playerX] = 'a';
                            }
                        } else {
                            playerX = oldplayerX;
                            playerY = oldplayerY;
                        }
                        break;
                    }
                break;

                
                
		        
	        case 'g':
                oldplayerX = playerX;
                oldplayerY = playerY;
		        currentmap++;
		        goto newmap;
            case 'p':
                oldplayerX = playerX;
                oldplayerY = playerY;
                break;

            case 'd':
                if (keynumber > 0) {
                    oldplayerX = playerX;
                    oldplayerY = playerY;                    
                } else {
                    playerX = oldplayerX;
                    playerY = oldplayerY;                    
                }
            case 'k':
                oldplayerX = playerX;
                oldplayerY = playerY;
                keynumber++;
                break;
            //case 'i':
            //case 'b':



        }

        

    } //end of game 
    end:
    return 0;
} // end of main
