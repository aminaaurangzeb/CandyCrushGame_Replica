Move the cursor to Select any gem to match 3 same matches   
-----Scoring Strategy----
Match 3 --> 150 
Match 4 --> 200  
Flaming --> 400
Destroyer --> 500

----void swaparray(int data[][8][3], int x, int y, int swapx, int swapy)----
swap selected gems

----void flamingOverlay(int y, int x)----
Flaming Gem distinction

----void clearscreen()----
Clears the array before reprinting

----void drawDestroy(int y, int x)----
Shows the gems which are to be deleted

----void printArray(int data[][8][3])----
Prints the 8 x 8 grid and arrays in the slots

----void printCursor(int x, int y, int color)----
Prints the selection square around the selected box

----bool boardEmpty(int data[8][8][3])----

----bool checkMatch(int data[][8][3],int &GameScore)----
Checks if any common matches > 3 found when random array is printed

----bool hcheck(int data[][8][3], int x1, int y1, int x2, int y2,int &GameScore)----
Checks for horizontal matches

----bool vcheck(int data[][8][3], int x1, int y1, int x2, int y2,int &GameScore)----
Checks for horizontal matches

----void destroyGems(int data[][8][3])----

----void randomize(int data[][8][3],int &GameScore)----
Assigns random elements to the array

----void Falling(int data[][8][3])----
Animates the falling gems from upper row

----void savearray(int data[][8][3], time_t t)----
Saves Score, Time and array

----void loadarray(int data[][8][3], time_t& t) ----
Loads Score, Time and array

----void timer(time_t GameTime)----
Displays Progression Bar

----void PrintScore(int ScoreEarned, int GameScore, int PrevScore, int HighScore)----
Prints Score Board