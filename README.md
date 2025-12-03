# Memory Quiz Game (Assignment 3)

## About the Project
This is my own game created in C language for Assignment 3.  
The idea is to test memory by showing a random sequence of numbers that the player must repeat.

---

## Game Rules
1. Player starts with 3 lives.
2. A random sequence of numbers (1–9) appears each round.
3. Player must type the same sequence correctly.
4. Wrong input reduces lives.
5. Score increases for each correct round.
6. High score is saved automatically.

---

## Controls
- Type numbers using keyboard.
- Press ENTER after each input.
- Menu navigation with 1–4 keys.

---

## Features
- Score and lives system
- Increasing difficulty (longer sequences)
- High score saved using file handling
- Menu system with Help and Rules
- Console sounds for correct/wrong answers

---

## What I Learned
- Random number generation with `rand()`
- File handling in C (`fopen`, `fprintf`, `fscanf`)
- Using arrays for storing sequences
- Loops and conditions for game flow
- Menu system implementation

---

## How to Run
1. Save the code as `memory_game.c`.
2. Compile using GCC:
   ```bash
   gcc memory_game.c -o game.exe


   ## made by Hemant jadon
