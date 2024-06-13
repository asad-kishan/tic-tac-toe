
# Tic-Tac-Toe Game

This is a simple implementation of the classical game Tic-Tac-Toe in C. The game allows two players to take turns marking spaces on a 3x3 grid untill one achives a winning pattern or the grid is filled, resulting a draw.

## Compile and Run 

- Compile the program using a C compiler. For example, using GCC:
```bash
gcc tictactoe.c -o tictactoe
```
- Run the compiled executable:
```bash
./tictactoe
```
or
```
tictactoe
```

## How To play 

1. The game starts with an empty 3x3 grid displayed on the screen.
2. Players make turns marking empty spaces with their respective symbols('x' or 'a').
3. Each player enters the row and column number of the space they want to mark when prompted.
4. Game continues untill one player achives the winning pattern or grid is filled.
5. If all three spaces of a row, column and diagonal is filled with same symbol('x' or 'a'), is a winning pattern.

## Code Structure 

1. `main()`: Initializes the game board and at the end prints the result.
2. `tictactoe()`: Implements the core logic of the game, allowing players to take turns and checking for a winner after each move.
3. `visual()`: Displays the current state of the game board.
4. `winner()`:  Checks for a winner by examining rows, columns, and diagonals of the game board.

## Assumptions:

- The program assumes that the user inputs the valid row and column numbered between (1-3)
- There's no error handling implemented for invalid inputs for simplicity.


## License

This project is licensed under the [MIT](https://choosealicense.com/licenses/mit/) License.

