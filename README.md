# Nibble Game

## Project Description:
Nibble Game is a classic "snake" game inspired by popular games from the 70s and the version available on Nokia phones. The project is implemented using the SFML library, which efficiently handles graphics and events.

## Technologies
This project utilizes the following libraries:

- **SFML** – graphics and event handling
- **ranges** – sorting
- **threads** – multithreading
- **filesystem** – file and folder management
- **regex** – regular expressions handling
- **concept** – defining template requirements

## Game Mechanics

### Menu
When the game starts, the player is presented with the main menu, which includes:

- **Start Game** – begins a new game
- **Game Speed** – adjusts the game speed (range 1-30)
- **Lives** – selects the number of lives
- **Exit Game** – exits the application
![menu](https://github.com/user-attachments/assets/298f335a-be1c-4c92-b551-f6b0ab965869)


### Objective
The player controls a snake, collecting food while avoiding obstacles. The main goal is to achieve the highest possible score.

### Controls
- **Arrow keys** (up, down, left, right) – control the snake's movement

### Game Rules
- The snake starts as a double segment.
- Food values range from 1 to 9 – when eaten, the snake grows, and the score increases by the food value × 100.
- The game ends when the number of lives reaches 0.
- Colliding with obstacles or itself decreases a life and deducts 1000 points.

### Hall of Fame
The highest scores are saved in the `leaderboards.txt` file and displayed in descending order.
![halloffame](https://github.com/user-attachments/assets/211efb05-2aaa-49bf-b3a0-dd75dcb8198a)

## Code Structure

### Classes

#### Object (base class)
- **position**, **thickness** – object position and thickness
- `setPosition()`, `setThickness()`, `getPosition()`, `getThickness()` – basic methods
- `draw()` – virtual method for rendering the object

#### Frame (game frame) – inherits from Object
- `getCenterPosition()` – returns the frame center position
- `draw()` – renders the frame

#### Obstacle (game obstacle) – inherits from Object
- **length**, **direction** – obstacle length and direction
- `checkCollision(head)`, `draw()`, `getLength()`, `getDirection()`

#### Point (game point) – inherits from Object
- `checkCollision(snake, obstacles)` – checks point collision
- `resetValue()`, `generatePoint()` – generates a new point

#### Snake (player-controlled snake) – inherits from Object
- **segments**, **direction**, `move()`, `grow()`, `resetSnake()`, `checkCollision()`, `checkCollisionWithObstacles()`, `draw()`

#### Game (main game class)
- **score**, **lives**, **level**, **game_speed**, **leaderBoard**
- `gameStart()`, `gameEnd()` – controls the game flow

## Running and Testing

- Start the program.
- The snake responds correctly to movement controls.
- Food spawns correctly and disappears when eaten.
- The game ends when the snake collides.
- The menu functions properly.

![nibble2](https://github.com/user-attachments/assets/77d9a688-0c63-44f8-bf4d-749df778626b)
![nibble4](https://github.com/user-attachments/assets/300e2a7f-0ce5-4e4b-a929-6ce044108f39)
![nibble3](https://github.com/user-attachments/assets/ac3372bc-faba-4960-aa62-6a543c83d9d7)


## Conclusions
This project provided valuable experience in object-oriented programming, including:

- Inheritance, polymorphism, and class relationships
- Event handling with SFML
- Code structure planning
- Testing and debugging using GitHub

Regular testing and version control ensured a stable and reliable application.
