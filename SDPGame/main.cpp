#include "FEHLCD.h"
#include "FEHRandom.h"
#include "FEHUtility.h"
#include "FEHImages.h"
#include <iostream>
#include <fstream>

using namespace std;

#define EASY_WIDTH 15
#define EASY_HEIGHT 10
#define REG_WIDTH 30
#define REG_HEIGHT 20

/**
 * Creates object called Menu which sets up the main menu with the the 4 buttons
 * asked for in the SDP 3 documentation. This also defines a function that allows
 * for the button press to be read. All functions are void functions and use
 * private variables as values for x and y and loop iterations.
 * @author Gabriel Regis.
 */
class Menu
{
public:
    Menu();
    void CreatePlayButton();
    void CreateStatsButton();
    void CreateInstructButton();
    void CreateCreditButton();
    void ButtonPress();
    int menuchoice;

private:
    int xmid, y1, y2, y3, y4, menuloop;
    float xtouch, ytouch;
};
/**
 * Constructor sets initial values for variables
 */
Menu::Menu()
{
    xmid = 94.;
    y1 = 0;
    y2 = 0;
    y3 = 0;
    y4 = 0;
    xtouch = 0;
    ytouch = 0;
    menuchoice = 0;
    menuloop = 1;
}
/**
 * This function displays the title of the game at the top of the screen.
 * Then it creates a white rectangle and places the text "Play Game" inside
 * creating the play game button.
 * @author Gabriel Regis
 */
void Menu::CreatePlayButton()
{
    // Writng Game title
    LCD.SetFontColor(RED);
    LCD.WriteAt("MAZE ESCAPE", 94, 20);

    // Finding the y value of the play game button
    y1 = (190 / 4) + 10;

    // Draw rectangle for the play game button
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(100, y1, 120, 30);
    // Place text inside the rectangle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("PLAY GAME", 105, y1 + 8);
}
/**
 * This function creates a white rectangle and places the text "Stats" inside
 * creating the play game button.
 * @author Gabriel Regis
 */
void Menu::CreateStatsButton()
{
    y2 = 2 * (190 / 4) + 10;
    // Draw rectangle for the stats button
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(100, y2, 120, 30);
    // Place text inside the rectangle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Stats", 130, y2 + 8);
}
/**
 * This function creates a white rectangle and places the text "Instructions" inside
 * creating the play game button.
 * @author Gabriel Regis
 */
void Menu::CreateInstructButton()
{
    y3 = 3 * (190 / 4) + 10;
    // Draw rectangle for the instruction button
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(100, y3, 120, 30);
    // Place text inside the rectangle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Instructns", 100, y3 + 8);
}
/**
 * This function creates a white rectangle and places the text "Credits" inside
 * creating the play game button.
 * @author Gabriel Regis
 */
void Menu::CreateCreditButton()
{
    y4 = (190) + 10;
    // Draw rectangle for the credit button
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(100, y4, 120, 30);
    // Place text inside the rectangle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Credits", 115, y4 + 8);
}
/**
 * This function waits for the screen to be touched, and once it is
 * touched it records where it was touched. If statements are then set
 * up to which button was pressed, and if a button was pressed it changes
 * the menu select value or waits for another touch.
 * @author Gabriel Regis
 */
void Menu::ButtonPress()
{
    while (menuloop == 1)
    {

        // waiting for touch and keeps track of where the touch occurred
        while (!LCD.Touch(&xtouch, &ytouch))
        {
        }
        while (LCD.Touch(&xtouch, &ytouch))
        {
        }

        // touching play game
        if (xtouch >= 100 && xtouch <= 220 && ytouch >= y1 && ytouch <= (y1 + 30))
        {
            menuchoice = 0;
            menuloop = 0;
        }

        // touching stats
        else if (xtouch >= 100 && xtouch <= 220 && ytouch >= y2 && ytouch <= (y2 + 30))
        {
            menuchoice = 1;
            menuloop = 0;
        }

        // touching instructions
        else if (xtouch >= 100 && xtouch <= 220 && ytouch >= y3 && ytouch <= (y3 + 30))
        {
            menuchoice = 2;
            menuloop = 0;
        }

        // touching credits
        else if (xtouch >= 100 && xtouch <= 220 && ytouch >= y4 && ytouch <= (y4 + 30))
        {
            menuchoice = 3;
            menuloop = 0;
        }
    }
}

/**
 * Void function to show a little backstory to the game. It clears the
 * previous screen and writes the text at the top of the screen. It will
 * show pictures, and stay on the screen for 5 seconds.
 * @author Gabriel Regis
 */
void Story()
{
    // clearing the screen
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    // Writing "Select Difficulty" at the top
    LCD.SetFontColor(RED);
    LCD.WriteAt("Escape the Ghosts!", 50, 20);

    // draws knight and ghosts pictures on the screen
    FEHImage knight;
    knight.Open("knight.png");
    knight.Draw(40, 70);

    FEHImage ghost;
    ghost.Open("ghosts.png");
    ghost.Draw(200, 70);
    Sleep(5000);
    LCD.SetFontColor(WHITE);
}

/**
 * Creating object for the Difficulty selection. This creates the
 * buttons for the three difficulty levels and the title for the page.
 * It also includes a function to read the button press.
 * @author Gabriel Regis
 */
class GameDifficulty
{
public:
    GameDifficulty();
    void DifficultyTitle();
    void Difficulty1();
    void Difficulty2();
    void Difficulty3();
    void DiffButtonPress();
    void DiffBackButton();
    int getDifficulty();

    int entergame;

private:
    int xbox, yeasy, ymedium, yhard, diffchoice, diffloop;
    float xtouchdiff, ytouchdiff;
};
/**
 * Constructor the sets initial values of object variables
 * @author Gabriel Regis
 */
GameDifficulty::GameDifficulty()
{
    xbox = 100;
    yeasy = 0;
    ymedium = 0;
    yhard = 0;
    xtouchdiff = 0;
    ytouchdiff = 0;
    entergame = 0;
    diffloop = 1;
}
/**
 * Constructor the sets initial values of object variables
 * @author Gabriel Regis
 */
int GameDifficulty::getDifficulty()
{
    return diffchoice;
}
/**
 * This function clears the prexisting background and makes it black.
 * Afterwards it displays the text "Select Difficulty" at the top of the screen.
 * @author Gabriel Regis
 */
void GameDifficulty::DifficultyTitle()
{
    // clearing the screen
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    // Writing "Select Difficulty" at the top
    LCD.SetFontColor(RED);
    LCD.WriteAt("Select Difficulty", 65, 20);
}
/**
 * The three functions, Difficulty1, Difficulty2, and Difficulty 3 draw out the
 * three rectangles and text for the easy, medium, and hard buttons.
 * @author Gabriel Regis
 */
void GameDifficulty::Difficulty1()
{
    // set x value for the button boxes
    xbox = 100;

    // find y value for easy button
    yeasy = (150 / 3) + 10;

    // Draw rectangle for the Easy Button
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(xbox, yeasy, 120, 30);
    // Place text inside the rectangle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("EASY", 135, yeasy + 8);
}
void GameDifficulty::Difficulty2()
{

    // find y value for medium button
    ymedium = 2 * (150 / 3) + 10;

    // Draw rectangle for the Medium Button
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(xbox, ymedium, 120, 30);
    // Place text inside the rectangle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("MEDIUM", 125, ymedium + 8);
}
void GameDifficulty::Difficulty3()
{

    // find y value for HARD button
    yhard = 3 * (150 / 3) + 10;

    // Draw rectangle for the HARD Button
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(xbox, yhard, 120, 30);
    // Place text inside the rectangle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("HARD", 135, yhard + 8);
}
/**
 * This function waits for the screen to be touched, and once it is
 * touched it records where it was touched. If statements are then set
 * up to determin which button was pressed, and if a button was pressed it changes
 * the menu select value or waits for another touch.
 * @author Gabriel Regis
 */
void GameDifficulty::DiffButtonPress()
{
    // while loop for if somewhere besides buttons are pressed
    while (diffloop == 1)
    {
        // waiting for touch and keeps track of where the touch occurred
        while (!LCD.Touch(&xtouchdiff, &ytouchdiff))
        {
        }
        while (LCD.Touch(&xtouchdiff, &ytouchdiff))
        {
        }

        // touching Easy
        if (xtouchdiff >= xbox && xtouchdiff <= 220 && ytouchdiff >= yeasy && ytouchdiff <= (yeasy + 30))
        {
            diffchoice = 0;
            diffloop = 0;
            entergame = 1;
        }

        // touching Medium
        else if (xtouchdiff >= xbox && xtouchdiff <= 220 && ytouchdiff >= ymedium && ytouchdiff <= (ymedium + 30))
        {
            diffchoice = 1;
            diffloop = 0;
            entergame = 1;
        }

        // touching Hard
        else if (xtouchdiff >= xbox && xtouchdiff <= 220 && ytouchdiff >= yhard && ytouchdiff <= (yhard + 30))
        {
            diffchoice = 2;
            diffloop = 0;
            entergame = 1;
        }

        // touching back button
        if (xtouchdiff >= 20 && xtouchdiff <= 70 && ytouchdiff >= 200 && ytouchdiff <= (200 + 30))
        {
            diffchoice = 0;
            diffloop = 0;
        }
    }
}
/**
 * The DiffBackButton fuction draws the box and text that creates the back button
 * in the bottom left corner of the screen.
 * @author Gabriel Regis
 */
void GameDifficulty::DiffBackButton()
{
    // Draw Back Button in Corner
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(20, 200, 50, 30);

    // Place text "Back" inside rectangle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("BACK", 21, 200 + 8);
}

/**
 * Creates class/object for the Stats page. It scans in the best scores for
 * each difficulty from their corresponding files and draws the back button in the
 * bottom lefthand corner. It includes a function to read the button press.
 * All functions are void fuctions and recieve no input.
 * @author Gabriel Regis
 */
class Stats
{
public:
    Stats();
    void StatsTitle();
    void StatsBackButton();
    void StatsText();
    void StatsButtonPress();

private:
    float xtouchstats, ytouchstats;
    int statschoice, statsloop;
};
/**
 * Constructor the sets initial values of object variables
 * @author Gabriel Regis
 */
Stats::Stats()
{
    xtouchstats = 0;
    ytouchstats = 0;
    statschoice = 0;
    statsloop = 1;
}
/**
 * Fuction clears the background and writes the title "Stats" for the
 * Stats page.
 * @author Gabriel Regis
 */
void Stats::StatsTitle()
{
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    LCD.SetFontColor(RED);
    LCD.WriteAt("STATS", 130, 20);
}
/**
 * The DiffBackButton fuction draws the box and text that creates the back button
 * in the bottom left corner of the screen.
 * @author Gabriel Regis
 */
void Stats::StatsBackButton()
{
    // Draw Back Button in Corner
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(20, 200, 50, 30);

    // Place "Back" inside rectangle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("BACK", 21, 200 + 8);
}
/**
 * This function defines three file pointers, and assigns them to the three files
 * containing the best times for each difficulty level. Using the pointers and the
 * LCD WriteAt Function it prints the values to the PROTEUS screen.
 * @author Gabriel Regis
 */
void Stats::StatsText()
{
    FILE *easyscorein, *mediumscorein, *hardscorein;
    easyscorein = fopen("easyscorefile.txt", "r");
    mediumscorein = fopen("mediumscorefile.txt", "r");
    hardscorein = fopen("hardscorefile.txt", "r");

    float easyscoredisplay, mediumscoredisplay, hardscoredisplay;
    while (fscanf(easyscorein, "%f", &easyscoredisplay) != EOF)
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Best Easy:", 10, 50);
        LCD.WriteAt(easyscoredisplay, 130, 50);
        LCD.WriteAt("Seconds", 230, 50);
    }
    fclose(easyscorein);

    while (fscanf(mediumscorein, "%f", &mediumscoredisplay) != EOF)
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Best Med.:", 10, 75);
        LCD.WriteAt(mediumscoredisplay, 130, 75);
        LCD.WriteAt("Seconds", 230, 75);
    }
    fclose(mediumscorein);

    while (fscanf(hardscorein, "%f", &hardscoredisplay) != EOF)
    {
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Best Hard:", 10, 100);
        LCD.WriteAt(hardscoredisplay, 130, 100);
        LCD.WriteAt("Seconds", 230, 100);
    }
    fclose(hardscorein);
}
/**
 * This function waits for the screen to be touched, and once it is
 * touched it records where it was touched. If statements are then set
 * up to which button was pressed, and if a button was pressed it changes
 * the menu select value or waits for another touch.
 * @author Gabriel Regis
 */
void Stats::StatsButtonPress()
{
    // while loop for if somewhere besides button is pressed
    while (statsloop == 1)
    {
        // waiting for touch and keeps track of where the touch occurred
        while (!LCD.Touch(&xtouchstats, &ytouchstats))
        {
        }
        while (LCD.Touch(&xtouchstats, &ytouchstats))
        {
        }

        // touching baack button
        if (xtouchstats >= 20 && xtouchstats <= 70 && ytouchstats >= 200 && ytouchstats <= (200 + 30))
        {
            statschoice = 0;
            statsloop = 0;
        }
    }
}

/**
 * Class/Object created for instructions page. The functions are all
 * public, void, and have no input. They first clear the screen, then
 * create the page title, load in an image containing the game instructions,
 * and create the back button in the bottom lefthand corner. This also
 * contains a function that looks for a button press. The private variables
 * are used to store x and y coordinates for screen touch and loop conditions.
 * @author Gabriel Regis
 */
class Instructions
{
public:
    Instructions();
    void InstructTitle();
    void InstructBackButton();
    void InstructText();
    void InstructButtonPress();

private:
    float xtouchinstruct, ytouchinstruct;
    int instructchoice, instructloop;
};
/**
 * Constructor sets initial values of object variables
 * @author Gabriel Regis
 */
Instructions::Instructions()
{
    xtouchinstruct = 0;
    ytouchinstruct = 0;
    instructchoice = 0;
    instructloop = 1;
}
/**
 * This function clears the background, and afterwards writes the title
 * "Instructions" at the top of the page in the middle.
 * @author Gabriel Regis
 */
void Instructions::InstructTitle()
{
    // Clear background
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    // write title for page
    LCD.SetFontColor(RED);
    LCD.WriteAt("INSTRUCTIONS", 85, 10);
}
/**
 * This function draws a rectangle for the back button and places the text
 * "Back" inside the rectangle created.
 * @author Gabriel Regis
 */
void Instructions::InstructBackButton()
{
    // Draw Back Button in Corner
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(20, 200, 50, 30);

    // Place text "Back" inside rectangle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("BACK", 21, 200 + 8);
}
/**
 * This function loads in the instruction image and places it in the middle
 * of the screen. It should be readable by the user and tell them how to
 * play the game.
 * @author Gabriel Regis
 */
void Instructions::InstructText()
{
    // write the instructions
    FEHImage instructtxt;
    instructtxt.Open("pixil-frame-0.png");
    instructtxt.Draw(60, 35);
}
/**
 * This function waits for the screen to be touched, and once it is
 * touched it records where it was touched. If statements are then set up
 * to which button was pressed, and if a button was pressed it changes the menu
 * select value or waits for another touch.
 * @author Gabriel Regis
 */
void Instructions::InstructButtonPress()
{
    // while loop for if somewhere besides button is pressed
    while (instructloop == 1)
    {
        // waiting for touch and keeps track of where the touch occurred
        while (!LCD.Touch(&xtouchinstruct, &ytouchinstruct))
        {
        }
        while (LCD.Touch(&xtouchinstruct, &ytouchinstruct))
        {
        }

        // touching back button
        if (xtouchinstruct >= 20 && xtouchinstruct <= 70 && ytouchinstruct >= 200 && ytouchinstruct <= (200 + 30))
        {
            instructchoice = 0;
            instructloop = 0;
        }
    }
}

/**
 * Class/Object created for Credits page, where the private functions are all
 * void and have no inputs. The functions clear the screen then write the title,
 * print the developers name and references to the screen, and create a working
 * back button. The private variables are used to store x and y coordinates for
 * screen touch and loop conditions.
 * @author Gabriel Regis
 */
class Credits
{
public:
    Credits();
    void CreditTitle();
    void CreditBackButton();
    void CreditText();
    void CreditButtonPress();

private:
    float xtouchcredit, ytouchcredit;
    int creditchoice, creditloop;
};
/**
 * Constructor sets initial values of object variables
 * @author Gabriel Regis
 */
Credits::Credits()
{
    xtouchcredit = 0;
    ytouchcredit = 0;
    creditchoice = 0;
    creditloop = 1;
}
/**
 * Function writes the text "Credits" at the top middle of the screen,
 * after clearing the previous screen.
 * @author Gabriel Regis
 */
void Credits::CreditTitle()
{
    // Clear background
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    // write title for page
    LCD.SetFontColor(RED);
    LCD.WriteAt("CREDITS", 110, 20);
}
/**
 * This function draws a rectangle for the back button and places the text
 * "Back" inside the rectangle created.
 * @author Gabriel Regis
 */
void Credits::CreditBackButton()
{
    // Draw Back Button in Corner
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(20, 200, 50, 30);

    // Place text "Back" inside rectangle
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("BACK", 21, 200 + 8);
}
/**
 * This function writes The Developers' names to the screen along with
 * any references used. It does this by using the LCD.WriteAt function.
 * @author Gabriel Regis
 */
void Credits::CreditText()
{
    // write the developers names
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Developers: Gabriel Regis", 10, 50);
    LCD.WriteAt("& Luca Sivilotti", 10, 70);
}
/**
 * This function waits for the screen to be touched, and once it is
 * touched it records where it was touched. If statements are then set
 * up to which button was pressed, and if a button was pressed it changes
 * the menu select value or waits for another touch.
 * @author Gabriel Regis
 */
void Credits::CreditButtonPress()
{
    // while loop for if somewhere besides button is pressed
    while (creditloop == 1)
    {
        // waiting for touch and keeps track of where the touch occurred
        while (!LCD.Touch(&xtouchcredit, &ytouchcredit))
        {
        }
        while (LCD.Touch(&xtouchcredit, &ytouchcredit))
        {
        }

        // touching back button
        if (xtouchcredit >= 20 && xtouchcredit <= 70 && ytouchcredit >= 200 && ytouchcredit <= (200 + 30))
        {
            creditchoice = 0;
            creditloop = 0;
        }
    }
}

/**
 * Class/Object that stores all information for each cell of the maze. Functions
 * are getters and setters for specific changable properties like player and passed.
 * One function also draws the block.
 * @author Luca Sivilotti
 */
class Block
{
private:
    /* The x position of the block in the maze */
    int x;
    /* The y position of the block in the maze */
    int y;
    /* The height and width of the block (dependant on difficulty) */
    int size;
    /* The x position of the block on the PROTEUS screen */
    int drawX;
    /* The y position of the block on the PROTEUS screen */
    int drawY;
    /* 0 == start, 1 == normal, 2 == end */
    int type;
    /* what directions the player can move from this*/
    bool nesw[4];
    /* describes if the block is where the player is "standing" */
    bool player;
    /* describes if block has been "walked on" */
    bool passed;
    /* defines whether player can go return along their path */
    bool retreat;

public:
    /*default constructor*/
    Block();
    /*constructor with arguments*/
    Block(int x, int y, int dir, bool player, int size, int type);
    /*returns this.x*/
    int getX();
    /*returns this.y*/
    int getY();
    /*returns this.passed*/
    bool getPassed();
    /*returns this.retreat*/
    bool getRetreat();
    /*returns this.player*/
    bool getPlayer();
    /*returns a pointer to the first element of this.nesw*/
    bool *getNESW();
    /*toggles this.player*/
    void togglePlayer();
    /*toggles this.passed*/
    void treadOn();
    /*sets this.passed value to false*/
    void treadOff();
    /*sets this.retreat to false*/
    void hardMode();
    /*draws this on the PROTEUS screen*/
    void drawBlock();
};
/**
 * Default constructor for class Block. Sets (x,y) to (0,0), all boolean
 * values are false and size is set to 4.
 * @author Luca Sivilotti
 */
Block::Block()
{
    x = 0;
    y = 0;
    nesw[0] = false;
    nesw[1] = false;
    nesw[2] = false;
    nesw[3] = false;
    player = false;
    retreat = false;
    size = 4;
}
/**
 * Constructor sets all instance variables of the Block based on inputs.
 * @author Luca Sivilotti
 */
Block::Block(int xPos, int yPos, int dir, bool p, int s, int t)
{
    /*initializes the instance variables of this*/
    x = xPos;
    y = yPos;
    size = s;
    type = t;
    drawX = 35 + x * size;
    drawY = 35 + y * size;
    player = p;
    retreat = true;
    passed = false;
    nesw[0] = false;
    nesw[1] = false;
    nesw[2] = false;
    nesw[3] = false;
    /*
     * depending on the directions the player would be able to move
     * in from this block, those directions in this.nesw are set to
     * true
     */

    switch (dir)
    {
    case 0:
        nesw[0] = true;
        break;
    case 1:
        nesw[1] = true;
        break;
    case 2:
        nesw[2] = true;
        break;
    case 3:
        nesw[3] = true;
        break;
    case 4:
        nesw[0] = true;
        nesw[1] = true;
        break;
    case 5:
        nesw[0] = true;
        nesw[2] = true;
        break;
    case 6:
        nesw[0] = true;
        nesw[3] = true;
        break;
    case 7:
        nesw[1] = true;
        nesw[2] = true;
        break;
    case 8:
        nesw[1] = true;
        nesw[3] = true;
        break;
    case 9:
        nesw[2] = true;
        nesw[3] = true;
        break;
    case 10:
        nesw[0] = true;
        nesw[1] = true;
        nesw[2] = true;
        break;
    case 11:
        nesw[0] = true;
        nesw[1] = true;
        nesw[3] = true;
        break;
    case 12:
        nesw[0] = true;
        nesw[2] = true;
        nesw[3] = true;
        break;
    case 13:
        nesw[1] = true;
        nesw[2] = true;
        nesw[3] = true;
        break;
    case 14:
        nesw[0] = true;
        nesw[1] = true;
        nesw[2] = true;
        nesw[3] = true;
        break;
    default:
        printf("%i not valid", dir);
    }
}
/**
 * Function sets value of player to !player.
 * @author Luca Sivilotti
 */
void Block::togglePlayer()
{
    player = !player;
}
/**
 * Function sets value of passed to true.
 * @author Luca Sivilotti
 */
void Block::treadOn()
{
    passed = true;
}
/**
 * Function sets value of passed to false.
 * @author Luca Sivilotti
 */
void Block::treadOff()
{
    passed = false;
}
/**
 * Function sets value of retreate to false.
 * @author Luca Sivilotti
 */
void Block::hardMode()
{
    retreat = false;
}
/**
 * Function gets a pointer to the boolean array nesw.
 * @returns pointer to nesw
 * @author Luca Sivilotti
 */
bool *Block::getNESW()
{
    return nesw;
}
/**
 * Funtion gets and returns the x value of the block in the maze.
 * @returns x value of the block
 * @author Luca Siviotti
 */
int Block::getX()
{
    return x;
}
/**
 * Funtion gets and returns the y value of the block in the maze.
 * @returns y value of the block
 * @author Luca Siviotti
 */
int Block::getY()
{
    return y;
}
/**
 * Funtion gets and returns whether the block has already
 * been passed by the player.
 * @returns passed
 * @author Luca Siviotti
 */
bool Block::getPassed()
{
    return passed;
}
/**
 * Funtion gets and returns whether the player can retreat back over their
 * path (only false in hard-mode).
 * @returns retreat
 * @author Luca Siviotti
 */
bool Block::getRetreat()
{
    return retreat;
}
/**
 * Funtion gets and returns whether the block contains the square
 * the user is controlling.
 * @returns player
 * @author Luca Siviotti
 */
bool Block::getPlayer()
{
    return player;
}
/**
 * Function draws the block on the PROTEUS screen with
 * it's walls and special properties.
 * @author Luca Sivilotti
 */
void Block::drawBlock()
{
    /*determines the background color of this*/
    int color;
    /*default background color of this*/
    color = GREEN;
    if (player)
    {
        /*color if this contains the player*/
        color = CYAN;
    }
    else if (type == 0)
    {
        color = YELLOW;
    }
    else if (type == 2)
    {
        /*color if this is either the start or end block*/
        color = RED;
    }
    else if (passed)
    {
        /*color if this.passed == true*/
        color = GRAY;
    }
    LCD.SetFontColor(color);
    LCD.FillRectangle(drawX, drawY, size, size);
    LCD.SetFontColor(WHITE);
    /*if the player cannot move up a wall is drawn at the top of this*/
    if (!nesw[0])
    {
        LCD.DrawHorizontalLine(drawY, drawX, drawX + size);
    }
    /*if the player cannot move right a wall is drawn to the right of this*/
    if (!nesw[1])
    {
        LCD.DrawVerticalLine(drawX + size, drawY, drawY + size);
    }
    /*if the player cannot move down a wall is drawn at the bottom of this*/
    if (!nesw[2])
    {
        LCD.DrawHorizontalLine(drawY + size, drawX, drawX + size);
    }
    /*if the player cannot move left a wall is drawn to the left of this*/
    if (!nesw[3])
    {
        LCD.DrawVerticalLine(drawX, drawY, drawY + size);
    }
    LCD.Update();
}

/**
 * Class/Object that defines the maze the user is playing in. Instance
 * variables store height and width of maze, difficulty, and the coordinates
 * of special squares. Functions define collisions, movement, drawing the
 * maze and whether the player is on the end block.
 * @author Luca Sivilotti
 */
class Maze
{
private:
    /*difficulty of the maze*/
    int difficulty;
    /*width of maze (in cells)*/
    int width;
    /*height of maze (in cells)*/
    int height;
    /*coordinate of the player in this*/
    int playerCoord[2];
    /*coordinate of the start block in this*/
    int startCoord[2];
    /*coordinate of the end block in this*/
    int endCoord[2];

public:
    /*array of Blocks that describe this*/
    Block maze[REG_HEIGHT][REG_WIDTH];
    /*constructor with arguments*/
    Maze(int difficulty, FILE *ptr);
    /*returns whether there was a collision as the player tried to move*/
    bool collision(int dir);
    /*returns whether the player collided with the border*/
    bool collisionBorder(int dir);
    /*returns whether there was a collision as the player tried to retrace steps*/
    bool collisionHard(int dir, bool collision);
    /*draws this on the PROTEUS screen*/
    void drawMaze();
    /*returns difficulty*/
    int getDifficulty();
    /*returns a pointer to this.playerCoord*/
    int *getPlayer();
    /*returns whether the player is on the end block*/
    bool playerAtEnd();
    /*reads user input and moves accordingly*/
    void move();
    /*clears any path that the player created*/
    void clearPath();
};
/**
 * Constructor for Maze class with difficulty and pointer to a text
 * file as parameters. Fills a matrix with Blocks corresponding to
 * properties generated from the file.
 * @author Luca Sivilotti
 */
Maze::Maze(int d, FILE *ptr)
{
    difficulty = d;
    int size;
    if (difficulty == 0)
    {
        width = EASY_WIDTH;
        height = EASY_HEIGHT;
        size = 16;
    }
    else
    {
        width = REG_WIDTH;
        height = REG_HEIGHT;
        size = 8;
    }
    int rngX = round((Random.RandInt() / 32767.0) * (width - 1));
    int rngY = round((Random.RandInt() / 32767.0) * (height - 1));
    startCoord[0] = rngX;
    startCoord[1] = rngY;
    rngX = round((Random.RandInt() / 32767.0) * (width - 1));
    rngY = round((Random.RandInt() / 32767.0) * (height - 1));
    while (rngX == startCoord[0] && rngY == startCoord[1])
    {
        rngX = round((Random.RandInt() / 32767.0) * (width - 1));
        rngY = round((Random.RandInt() / 32767.0) * (height - 1));
    }
    endCoord[0] = rngX;
    endCoord[1] = rngY;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            bool player = false;
            int direction, type = 1;
            fscanf(ptr, "%i", &direction);
            if (x == startCoord[0] && y == startCoord[1])
            {
                playerCoord[0] = x;
                playerCoord[1] = y;
                type = 0;
                player = true;
            }
            else if (x == endCoord[0] && y == endCoord[1])
            {
                type = 2;
            }
            maze[y][x] = Block(x, y, direction, player, size, type);
            if (d == 2)
            {
                maze[y][x].hardMode();
            }
        }
    }
}
/**
 * Function returns the difficulty of the maze.
 * @returns difficulty
 * @author Luca Sivilotti
 */
int Maze::getDifficulty()
{
    return difficulty;
}
/**
 * Function determines if there was a collision as the player
 * attempted to move in the designated direction.
 * @param dir direction the player is trying to move in
 * @returns true if a collision occured, false otherwise
 * @author Luca Sivilotti
 */
bool Maze::collision(int dir)
{
    bool collides = !*(maze[playerCoord[1]][playerCoord[0]].getNESW() + dir);
    collides = collides || collisionBorder(dir) || collisionHard(dir, collides);
    return collides;
}
/**
 * Function determines if the player was attempting to
 * move outside the maze.
 * @param dir direction the player is trying to move in
 * @returns true if a collision occured, false otherwise
 * @author Luca Sivilotti
 */
bool Maze::collisionBorder(int dir)
{
    bool collides = false;
    collides = collides || (playerCoord[1] == 0 && dir == 0);
    collides = collides || (playerCoord[0] == width - 1 && dir == 1);
    collides = collides || (playerCoord[1] == height - 1 && dir == 2);
    collides = collides || (playerCoord[0] == 0 && dir == 3);
    return collides;
}
/**
 * Function determines if the player was attempting to retrace their
 * steps when they aren't allowed to (hard-mode).
 * @param dir direction the player is trying to move in
 * @param collides whether a collision with a wall occured
 * @returns true if a collision occured, false otherwise
 * @author Luca Sivilotti
 */
bool Maze::collisionHard(int dir, bool collides)
{
    // 0 == up, 1 == right, 2 == down, 3 == left
    if (!collides)
    {
        int x = playerCoord[0];
        int y = playerCoord[1];
        switch (dir)
        {
        case 0:
            y--;
            break;
        case 1:
            x++;
            break;
        case 2:
            y++;
            break;
        case 3:
            x--;
            break;
        default:
            break;
        }
        collides = maze[y][x].getPassed() && !maze[y][x].getRetreat();
    }
    return collides;
}
/**
 * Function clears the path the player traveled over after
 * a collision occurs.
 * @author Luca Sivilotti
 */
void Maze::clearPath()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (maze[y][x].getPassed())
            {
                maze[y][x].treadOff();
                maze[y][x].drawBlock();
            }
        }
    }
}
/**
 * Function draws the arrows and maze on the PROTEUS screen.
 * @author Luca Sivilotti
 */
void Maze::drawMaze()
{
    /*up arrow*/
    LCD.DrawHorizontalLine(30, 150, 200);
    LCD.DrawLine(150, 30, 175, 5);
    LCD.DrawLine(175, 5, 200, 30);
    /*down arrow*/
    LCD.DrawHorizontalLine(200, 150, 200);
    LCD.DrawLine(150, 200, 175, 225);
    LCD.DrawLine(175, 225, 200, 200);
    /*right arrow*/
    LCD.DrawVerticalLine(30, 100, 150);
    LCD.DrawLine(30, 100, 5, 125);
    LCD.DrawLine(5, 125, 30, 150);
    /*left arrow*/
    LCD.DrawVerticalLine(280, 100, 150);
    LCD.DrawLine(280, 100, 305, 125);
    LCD.DrawLine(305, 125, 280, 150);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            maze[y][x].drawBlock();
        }
    }
}
/**
 * Function returns a pointer to the coordinates of the player Block.
 * @returns pointer to playerCoord array
 * @author Luca Sivilotti
 */
int *Maze::getPlayer()
{
    return playerCoord;
}
/**
 * Function returns whether or not the player is on the end Block.
 * @returns true if player coordinates == end coordinates, false otherwise
 * @author Luca Sivilotti
 */
bool Maze::playerAtEnd()
{
    return playerCoord[0] == endCoord[0] && playerCoord[1] == endCoord[1];
}
/**
 * Function waits for an input and moves the player in the corresponding
 * direction. If a collision is registered the player is sent back to the
 * beginning of the maze and the path gets reset.
 * @author Luca Sivilotti
 */
void Maze::move()
{
    int xTouch, yTouch;
    int direction;
    while (!LCD.Touch(&xTouch, &yTouch))
        ;
    while (LCD.Touch(&xTouch, &yTouch))
        ;
    if ((xTouch > 35 && xTouch < 275) && (yTouch < 35))
    {
        direction = 0;
    }
    else if ((xTouch > 275) && (yTouch > 35 && yTouch < 195))
    {
        direction = 1;
    }
    else if ((xTouch > 35 && xTouch < 275) && (yTouch > 195))
    {
        direction = 2;
    }
    else if ((xTouch < 35) && (yTouch > 35 && yTouch < 195))
    {
        direction = 3;
    }
    else
    {
        direction = 4;
    }
    if (direction != 4)
    {
        maze[playerCoord[1]][playerCoord[0]].togglePlayer();
        maze[playerCoord[1]][playerCoord[0]].treadOn();
        maze[playerCoord[1]][playerCoord[0]].drawBlock();
        if (collision(direction))
        {
            playerCoord[0] = startCoord[0];
            playerCoord[1] = startCoord[1];
            clearPath();
        }
        else
        {
            switch (direction)
            {
            case 0:
                playerCoord[1]--;
                break;
            case 1:
                playerCoord[0]++;
                break;
            case 2:
                playerCoord[1]++;
                break;
            case 3:
                playerCoord[0]--;
                break;
            default:
                break;
            }
        }
        maze[playerCoord[1]][playerCoord[0]].togglePlayer();
        maze[playerCoord[1]][playerCoord[0]].drawBlock();
    }
}

/**
 * Main method that controlls the large processes of the game.
 * @authors Gabriel Regis and Luca Sivilotti
 */
int main()
{
    /*While loop to take player back to beginning after game is over*/
    int mainmenureturn = 1;
    /*keeps track of best time for each difficulty*/
    float besteasy, bestmedium, besthard;
    ifstream be;
    be.open("easyscorefile.txt");
    be >> besteasy;
    be.close();

    ifstream bm;
    bm.open("mediumscorefile.txt");
    bm >> bestmedium;
    bm.close();

    ifstream bh;
    bh.open("hardscorefile.txt");
    bh >> besthard;
    bh.close();

    while (mainmenureturn == 1)
    {
        /*array of easy mazes' file names*/
        char easyMazes[3][30] = {"easyMaze1.txt", "easyMaze2.txt", "easyMaze3.txt"};
        /*array of regular/hard mazes' file names*/
        char regMazes[3][30] = {"regMaze1.txt", "regMaze2.txt", "regMaze3.txt"};
        /*name of maze's file*/
        char maze[30];
        /*difficulty of maze*/
        int difficult = 0;

        int entergamemain = 0;
        /*main menu screen*/
        while (entergamemain == 0)
        {
            // Clear background
            LCD.SetBackgroundColor(BLACK);
            LCD.Clear();

            Menu start;

            // setting up the menu using the Menu object's functions
            start.CreatePlayButton();
            start.CreateStatsButton();
            start.CreateInstructButton();
            start.CreateCreditButton();

            LCD.Update();

            // reading the button press using Menu object's functions
            start.ButtonPress();

            // if statements to take the player to the next screen based on where on the screen they pressed
            // Building Game Difficulty Page
            if (start.menuchoice == 0)
            {
                GameDifficulty difficulty = GameDifficulty();
                difficulty.DifficultyTitle();
                difficulty.Difficulty1();
                difficulty.Difficulty2();
                difficulty.Difficulty3();
                difficulty.DiffBackButton();
                difficulty.DiffButtonPress();

                entergamemain = difficulty.entergame;
                difficult = difficulty.getDifficulty();
            }

            // Building Stats Page
            else if (start.menuchoice == 1)
            {
                Stats statistics = Stats();
                statistics.StatsTitle();
                statistics.StatsBackButton();
                statistics.StatsText();
                statistics.StatsButtonPress();
            }
            // Building Instructions Page
            else if (start.menuchoice == 2)
            {
                Instructions instruct = Instructions();
                instruct.InstructTitle();
                instruct.InstructBackButton();
                instruct.InstructText();
                instruct.InstructButtonPress();
            }

            // Building Credits Page
            else if (start.menuchoice == 3)
            {
                Credits cred = Credits();
                cred.CreditTitle();
                cred.CreditBackButton();
                cred.CreditText();
                cred.CreditButtonPress();
            }
        }
        /*randomly generated integer [0,1]*/
        bool selected = false;

        /*loop for play again*/
        int playagainchoice = 1;
        float starttime, endtime, totaltime;
        while (playagainchoice == 1)
        {

            int rng = round((Random.RandInt() / 32767.0) * 2);
            if (difficult == 0)
            {
                strcpy(maze, easyMazes[rng]);
            }
            else
            {
                strcpy(maze, regMazes[rng]);
            }
            /*Story Screen*/
            Story();

            LCD.SetBackgroundColor(BLACK);
            LCD.Clear();
            /*opens file that stores the maze for reading*/
            FILE *ptr = fopen(maze, "r");
            /*creates new maze*/
            Maze m(difficult, ptr);
            LCD.Update();
            /*draws maze*/
            m.drawMaze();

            /*start time*/
            starttime = TimeNow();

            while (!m.playerAtEnd())
            {
                m.move();
                LCD.Update();
            }

            /*end time and total time calculation*/
            endtime = TimeNow();
            totaltime = endtime - starttime;

            /*Open output file for score and send score to it*/
            if (difficult == 0 && totaltime < besteasy)
            {
                besteasy = totaltime;
                ofstream scorefile;
                scorefile.open("easyscorefile.txt");
                scorefile << totaltime << endl;
                scorefile.close();
            }

            else if (difficult == 1 && totaltime < bestmedium)
            {
                bestmedium = totaltime;
                ofstream scorefile;
                scorefile.open("mediumscorefile.txt");
                scorefile << totaltime << endl;
                scorefile.close();
            }

            else if (difficult == 2 && totaltime < besthard)
            {
                besthard = totaltime;
                ofstream scorefile;
                scorefile.open("hardscorefile.txt");
                scorefile << totaltime << endl;
                scorefile.close();
            }

            LCD.Clear();
            LCD.DrawRectangle(35, 35, 215, 195);
            LCD.WriteAt("Congratulations!", 35, 60);
            LCD.WriteAt(totaltime, 45, 85);
            LCD.WriteAt("Seconds", 45, 105);
            LCD.WriteAt("Play Again?", 50, 150);
            LCD.WriteAt("Yes", 75, 190);
            LCD.WriteAt("No", 120, 190);
            int x, y;
            while (!LCD.Touch(&x, &y))
                ;
            while (LCD.Touch(&x, &y))
                ;

            int playagainloop = 1;

            while (playagainloop == 1)
            {

                if (x > 75 && x < 100 && y > 190 && y < 210)
                {
                    playagainchoice = 1;
                    playagainloop = 0;
                }

                else if (x > 120 && x < 145 && y > 190 && y < 210)
                {
                    playagainchoice = 0;
                    playagainloop = 0;
                }
            }

            LCD.Update();
        }
    }
    return 0;
}
