#include <iostream>
#include <vector>
using namespace std;


/**
 * Current train of thought:
 * 1. Locate position of princess
          - Create a function called findPrincess(grid), which returns row & column of princess
 * 2. Locate suitable algorithm to move bot (A*, Dijkstra, etc) & use manhattan distance
 * 3. Output suitable position to move
 *
 * Asumptions:
 * 1. There are no obstacles to block in the grid
 */

vector<string> split(string s)
{
    vector<string> output;
    for(char c : s)
        output.push_back(string(1, c));

    return output;
}

/**
 * Returns an array containing the row & column position of the princess
 * @grid: 2D array of the grid to search-in
 * 
 * @return - vector containing: {row, column}
 */
vector<int> findPrincess(vector <vector<string>> grid)
{
        // Basic O(N) search which looks through all the data items in-order
       for(int row=0; row<grid.size(); row++)
           for(int column=0; column<grid[0].size(); column++)
               if(grid[row][column] == "p")
                    // Return the row & column the princess is at
                    return {row, column};
        // If not found, return out of bound coordinates
        return {-1, -1};
}


/**
 * @summary - Returns an string direciton containing the path to the destination
 * 
 * @rStart: Row/Y-coordinate to start-at
 * @cStart: Column/X-coordinate to start-at
 * @rEnd: Row/Y-coordinate to end-at
 * @cEnd: Column/X-coordinate to end-at
 *  
 * @returns - String Vector with elements: "Left", "Right", "Up", or "Down"
 */
string calculateManhattanDirection(int rStart, int cStart, int rEnd, int cEnd)
{
    // Given Manhattan distance, the function attempt to go in a straight line to the desintation:
    // 1. Decide which direction to move in first: horizontal or vertical
    //    - Decision is based-on whether is bigger: vertical distance or horizontal distance
    // 2. Calculate which direction to move in: LEFT OR RIGHT; UP OR DOWN
    vector<string> pathOutput;
    vector<string> direction = {"LEFT", "RIGHT", "UP", "DOWN"};
    int rDistance, cDistance, rABS, cABS;
    // Calculate absolute distance
    rDistance = rStart - rEnd;
    cDistance = cStart - cEnd;
    rABS = abs(cDistance);
    cABS = abs(cDistance);

    // 1. Decide which direction to move
    if(cABS != 0){
        // Moves the pointer left
        if(cDistance > 0) {return direction[0];} 
        else {return direction[1];}
    // Else move horizontally
    } else {
        if(rDistance > 0) {return direction[2];} 
        else {return direction[3];}
    }
}

 
/**
 * n - n x n grid-size
 * r - bots' current row
 * c - bots' current column
 * grid - vector of actual grid
 */
string nextMove(int n, int r, int c, vector <vector<string>> grid)
{
    // 1. Find the princesses coordinates
    vector<int> princessCoordinates = findPrincess(grid);
    //cout << "Princess location: (" << princessCoordinates[0] << ", " << princessCoordinates[1] <<")";
    // 2. Find the optimal direction to travel-in, using manhattan distance
    return calculateManhattanDirection(r, 
                                        c,
                                        princessCoordinates[0],
                                        princessCoordinates[1]);
}




int main(void) {

    int n, r, c;
    vector <vector<string>> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(split(s));
    }
    
    cout << nextMove(n, r, c, grid);

    return 0;
}  
    
