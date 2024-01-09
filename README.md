# CMPE 126 Project
## About
The objective of this project is to create a chess board with the following restrictions:
- Classes that demonstrate inheritance and polymorphism
- Use of stack and queue
- Hashing
- STL

## Project
Our project is a simple chess game that stores player data on a txt file. The game consists of a classic 8x8 board with all of the traditional chess pieces. There are 4 options for the user to explore, including player history and the ability to search the player database. The program ends after each option is completed

## Display
User inputs and the board are inputed and displayed through the console UI. The board is refreshed and printed after every move, including undoes.

## Functions
There are 4 options for the user to choose:
1. "Start a new chess game" - This option creates an instance of a chess match and asks the user for the two players that will be playing. If the player already exists in the database, then that player's stats will change. If the player does not exist, then that player will be added to the database after the match is finished
2. "Look up player stats" - This option will search the database for a player with the name given by the user. If that player exists in the database, the player's stats will be displayed on the console. If that player does not exist, an error will be thrown
3. "Print all players" - This option will display all the player's stats, starting with the most recently played players.
4. "Look up players with W/L Ratio" - This option will display players with the win/loss ration given by the user. This is done using a separate chaining hashing technique, and each key represents a win/loss ratio from 0.00 to 1.00 in increments of 0.01
