#include <gtest/gtest.h>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include "maze.h"
#include "grid.h"
#include "EscapeTheLabyrinth.h"


TEST(grid, defaultConstructor){
    
    
    // TO DO:  Write 100s of asserts per member function.
    
    
}





// TO DO:  Write many TESTs, at least one for, if not more,
// for each member function.  Each tests should have 100s of assertions.






// TO DO:  As you get to each milestone, you can comment out these provided
// tests.  They currently use grid.h and will segfault until you implement
// grid correctly.  


//Provided Test: sample maze from handout, make lots more yourself!
TEST(maze, basic) {
   vector<string> textMaze;

   textMaze.push_back("* *-W *");
   textMaze.push_back("| |   |");
   textMaze.push_back("*-* * *");
   textMaze.push_back("  | | |");
   textMaze.push_back("S *-*-*");
   textMaze.push_back("|   | |");
   textMaze.push_back("*-*-* P");

   Maze m(textMaze);

   MazeCell* start = m.getStart(2, 2);

   /* These paths are the ones in the handout. They all work. */
   EXPECT_TRUE(isPathToFreedom(start, "ESNWWNNEWSSESWWN"));
   EXPECT_TRUE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES"));
   EXPECT_TRUE(isPathToFreedom(start, "WNNEWSSESWWNSEENES"));

   /* These paths don't work, since they don't pick up all items. */
   EXPECT_FALSE(isPathToFreedom(start, "ESNW"));
   EXPECT_FALSE(isPathToFreedom(start, "SWWN"));
   EXPECT_FALSE(isPathToFreedom(start, "WNNE"));

   /* These paths don't work, since they aren't legal paths. */
   EXPECT_FALSE(isPathToFreedom(start, "WW"));
   EXPECT_FALSE(isPathToFreedom(start, "NN"));
   EXPECT_FALSE(isPathToFreedom(start, "EE"));
   EXPECT_FALSE(isPathToFreedom(start, "SS"));
}

// Provided Test: don't allow going through walls
TEST(maze, tryingToGoThroughWalls) {
   vector<string> textMaze;

   textMaze.push_back("* S *");
   textMaze.push_back("     ");
   textMaze.push_back("W * P");
   textMaze.push_back( "     ");
   textMaze.push_back( "* * *");

   Maze m(textMaze);

   MazeCell* start = m.getStart(1, 1);

   EXPECT_FALSE(isPathToFreedom(start, "WNEES"));
   EXPECT_FALSE(isPathToFreedom(start, "NWSEE"));
   EXPECT_FALSE(isPathToFreedom(start, "ENWWS"));
   EXPECT_FALSE(isPathToFreedom(start, "SWNNEES"));
}

// Provided Test: Works when starting on an item
TEST(maze, startOnItem) {
   vector<string> textMaze;

   textMaze.push_back("P-S-W");

   Maze m(textMaze);
   MazeCell* start = m.getStart(0, 0);

   EXPECT_TRUE(isPathToFreedom(start, "EE"));
   start = m.getStart(0, 1);
   EXPECT_TRUE(isPathToFreedom(start, "WEE"));
   start = m.getStart(0, 2);
   EXPECT_TRUE(isPathToFreedom(start, "WW"));

}

// Provided Test: Reports errors if given illegal characters.
TEST(maze, invalidChar) {
   vector<string> textMaze;

   textMaze.push_back("* *-W *");
   textMaze.push_back("| |   |");
   textMaze.push_back("*-* * *");
   textMaze.push_back("  | | |");
   textMaze.push_back("S *-*-*");
   textMaze.push_back("|   | |");
   textMaze.push_back("*-*-* P");

   Maze m(textMaze);
   MazeCell* start = m.getStart(0, 0);

   /* These paths contain characters that aren't even close to permissible. */
   EXPECT_FALSE(isPathToFreedom(start, "Q"));
   EXPECT_FALSE(isPathToFreedom(start, "X"));
   EXPECT_FALSE(isPathToFreedom(start, "!"));
   EXPECT_FALSE(isPathToFreedom(start, "?"));

   EXPECT_FALSE(isPathToFreedom(start, "n"));
   EXPECT_FALSE(isPathToFreedom(start, "s"));
   EXPECT_FALSE(isPathToFreedom(start, "e"));
   EXPECT_FALSE(isPathToFreedom(start, "w"));

   ///* These are tricky - they're legal paths that happen to have an unexpected
   // * character at the end.
   start = m.getStart(2, 2);
   EXPECT_FALSE(isPathToFreedom(start, "ESNWWNNEWSSESWWNQ"));
   EXPECT_FALSE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES!!!"));
   EXPECT_FALSE(isPathToFreedom(start, "WNNEWSSESWWNSEENES??"));

}

// Provided Test: This tests your personalized regular maze to see if you were
// able to escape.
TEST(maze, escapeRegularMaze) {
   Maze m(4, 4);
   MazeCell* start = m.mazeFor(kYourName);
   EXPECT_TRUE(isPathToFreedom(start, kPathOutOfRegularMaze));
}

// Provided Test: This tests your personalized twisty maze to see if you were
// able to escape.
TEST(maze, escapeTwistyMaze) {
   Maze m(4, 4);
   MazeCell* start = m.twistyMazeFor(kYourName);
   EXPECT_TRUE(isPathToFreedom(start, kPathOutOfTwistyMaze));
}

