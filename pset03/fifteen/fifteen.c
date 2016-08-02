/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// universally scoped array to hold coordinates of empty tile
int open[2];

// universally scoped array to hold coordinates of user's chosen tile
int tile_coord[2];

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void tileSearch(int tile);
bool tileSwap(int tile);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        // && TODO remove before submission
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // set flag to indicate whether d is even or odd in order to adjust tiles 1 and 2 for games where d is even
    int even_odd = d % 2;
    
    // set the highest number on the board
    int game_of_me = (d * d) - 1;
    
    // write each row of the board to array from highest to lowest
    for (int row = 0; row < d; row++) {
        
        int row_mod = row * d;
        
        // write each column in i-th row
        for (int col = 0; col < d; col++) {
            
            int tile = game_of_me - row_mod - col;
            
            // swap last two tiles for games where d is even; init final three tiles and return
            if (even_odd == 0 && tile == 2) {
                
                board[row][col] = 1;
                board[row][col + 1] = 2;
                board[row][col + 2] = 0;
                
                // record starting location of empty tile
                open[0] = row;
                open[1] = col + 2;
                
                return;
            }
            
            // for games where d is even, just record location of open tile
            else if (even_odd == 1 && tile == 0) {
                open[0] = row;
                open[1] = col;
                
                return;
            }
            
            // each tile decreases in value by the number of tiles that have come before it (calculated by adding tiles previous in current row, to the d * number of rows already completed - tracked by 'row_mod')
            board[row][col] = tile;
            
        }
    }
    
    return;
}


/**
 * Prints the board in its current state.
 */
void draw(void)
{
    printf("\n");
    for (int row = 0; row < d; row++) {
        for (int col = 0; col < d; col++) {
            
            int tile = board[row][col];
            
            // if tile is negative, freakout
            if (tile < 0) {
                // &&&& TODO implement disco
                return;
            }
            // print tile + 3x space if single digit int
            else if ( tile > 0 && tile < 10) {
                printf(" %i    ", tile);
            }
            else if (tile == 0) {
                printf(" #    ");
            }
            // print tile + 2x space if double digit int
            else if (tile > 9 && tile < 100) {
                printf("%i    ", tile);
            }
            else {
                return;
            }
        }
        
        printf("\n\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // find coordinates for the user's tile
    tileSearch(tile);
    
    // make sure we don't freak out
    if (tile_coord[0] != -1 && tile_coord[1] != -1) {
        
        // if tile is on same row as open space
        if (tile_coord[0] == open[0]) {
            
            // check if tile directly adjacent to the open space
            if (tile_coord[1] == open[1] - 1) {
                return tileSwap(tile);
            }
            else if ( tile_coord[1] == open[1] + 1) {
                return tileSwap(tile);
            }
            // if not, invalid move
            else
                return false;
        }
        // if tile is on row above open space
        else if (tile_coord[0] == open[0] - 1) {
            
            // check if tile is directly above the open space
            if (tile_coord[1] == open[1]) {
                return tileSwap(tile);
            }
            // if not, invalid move
            else
                return false;
        }
        // if tile is on row below open space
        else if (tile_coord[0] == open[0] + 1) {
            
            // check if tile is directly below open space
            if (tile_coord[1] == open[1]) {
                return tileSwap(tile);
            }
            // if not, invalid move
            else
                return false;
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    
    int board_size = d * d;
    
    int expect_tile = 1;
    
    // check empty space first--if that's not in the right place, we don't need to check the rest
    if (board[d - 1][d - 1] != 0) {
        return false;
    }
    
    // check each tile
    for (int row = 0; row < d; row++ ) {
        for (int col = 0; col < d; col++, expect_tile++) {
            
            // if we've done this enough times to be looking at the last tile, it should be empty
            if (expect_tile == board_size) {
                if (board[row][col] == 0) {
                    return true;
                }
                else
                    return false;
            }
            // general case, checks all tiles except empty space
            if (board[row][col] != expect_tile) {
                return false;
            }
        }
    }
    return false;
}


/**
 * Searches board linearly for user's tile because after the user's first turn 
 * we cannot assume the board is sorted. Updates
 * 'tile_coord' variable array. 
 */
 void tileSearch(int tile) {
     

     // search each row of the board
     for (int i = 0; i < d; i++) {
         // and check each tile in the columns of that row
         for (int j = 0; j < d; j++) {
             
             if (board[i][j] == tile) {
                 tile_coord[0] = i;
                 tile_coord[1] = j;
                 return;
             }
         }
     }
     return;
}


/**
 * Swaps user's chosen tile with the open space. Returns true if successful.
 */
bool tileSwap () {
    
    // move the tile value into the open space
    board[open[0]][open[1]] = board[tile_coord[0]][tile_coord[1]];
    
    // move the empty space
    board[tile_coord[0]][tile_coord[1]] = 0;
    
    // update location of open space
    open[0] = tile_coord[0];
    open[1] = tile_coord[1];
    
    return true;
    
}