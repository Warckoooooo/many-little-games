# Many Little Games

## Project Overview
This C++ project is a collection of several small games, including:
1. **Tic Tac Toe**
2. **Guess the Number**
3. **Crontab Game**

The project is structured to allow easy addition of more games in the future. Each game has its own source file and header file. The main program presents a menu to the user to choose which game to play.

## Project Structure
The project is organized into the following directories and files:

```bash
many-little-games
├── Makefile
├── README.md
└── src
    ├── guessthecrontab.cpp
    ├── guessthecrontab.h
    ├── guessthenumber.cpp
    ├── guessthenumber.h
    ├── main.cpp
    ├── tictactoe.cpp
    ├── tictactoe.h
```

### Files Description
- **`main.cpp`**: Contains the main menu and the logic to launch the selected game.
- **`guessthenumber.cpp` and `guessthenumber.h`**: Implementation of the "Guess the Number" game.
- **`guessthecrontab.cpp` and `guessthecrontab.h`**: Implementation of the "Guess the Crontab Game".
- **`tictactoe.cpp` and `tictactoe.h`**: Implementation of the "Tic Tac Toe" game.
- **`Makefile`**: Automates the compilation process for the project.

## Compilation Instructions

### Prerequisites
- **C++ Compiler**: Ensure that `g++` or another C++ compiler is installed on your system.

### Compiling the Project
1. Navigate to the root directory of the project where the `Makefile` is located.
2. Run the following command in the terminal to compile the project:

    ```bash
    make
    ```

   This command will compile all the `.cpp` files in the `src/` directory and generate an executable named `games`.

### Running the Program

After compilation, you have two options to run the program:

1. **Manual Run**:
   Run the program by executing the following command:

    ```bash
    ./games
    ```

2. **Using Make**:
   Alternatively, you can compile and run the program in one step using:

    ```bash
    make run
    ```

### Cleaning the Build
To remove the compiled object files and the executable, run:

```bash
make clean
```

## How to Play

1. **Launch the program**: After running `./games`, a menu will appear.
2. **Choose a game**: Enter the number corresponding to the game you want to play.
3. **Follow the instructions**: Each game has its own set of instructions that will guide you through the gameplay.
4. **Exit the program**: Select the "Quit" option from the menu to exit the program.

## Adding New Games
To add a new game:
1. Create a new `.cpp` file and its corresponding `.h` file in the `src/` directory.
2. Implement the game logic in the new `.cpp` file.
3. Add a prototype for the game function in the corresponding `.h` file.
4. Include the new header file in `main.cpp`.
5. Add a menu option and a case in the `switch` statement in `main.cpp` to launch the new game.
