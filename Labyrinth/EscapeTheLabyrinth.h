 #include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;

/* Change this constant to contain your full first and last name (middle is ok too).
 *
 * WARNING: Once you've set set this constant and started exploring your maze,
 * do NOT edit the value of kYourName. Changing kYourName will change which
 * maze you get back, which might invalidate all your hard work!
 */
const string kYourName = "Jamani Alford";
/* Change these constants to contain the paths out of your mazes. */
const string kPathOutOfRegularMaze = "ESSSWNSENEESWENWWNNWSNESEEN";
const string kPathOutOfTwistyMaze = "NNSESSSWWNNEESE";
bool isPathToFreedom(MazeCell *start, const string& moves) {
  for (int i = 0; i < moves.size(); ++i) {
    if ('W' != moves[i] && 'E' != moves[i] && 'N' != moves[i] && 'S' != moves[i])
      return false;
  }
 set <string> search;
  search.insert("Spellbook");
  search.insert("Potion");
  search.insert("Wand");
  for (int z = 0; z < moves.size(); z++) {
    if (search.count(start -> whatsHere))
      search.erase(start -> whatsHere);
    if (moves[z] == 'W' && start -> west != nullptr)
      start = start -> west;
    else if (moves[z] == 'E' && start -> east != nullptr)
      start = start -> east;
    else if (moves[z] == 'S' && start -> south != nullptr)
      start = start -> south;
    else if (moves[z] == 'N' && start -> south != nullptr)
      start = start -> north;
    else
      return false;
  }
  return true;
}


