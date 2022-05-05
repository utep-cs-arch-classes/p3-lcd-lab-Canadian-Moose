Project 3: Frogger
====================

This program will connect to an MSP430 board in order to manipulate the LED screen, switches, and buzzer.
<br>The user will become the 'player' in a game of Frogger. 

## Features

Upon loading the screen, the player will be presented with some lanes of `moving cars` and a frog at the bottom of the screen. 
<br>The player may (from left to right): 
- press `switch 1` to move the frog `left` 
- press `switch 2` to move the frog `up`
- press `switch 3` to move the frog `down`
- press `switch 4` to move the frog `right`

The frog will make a `beep` when it is moved. 

Upon reaching the safe zone at the top of the screen, the win state will be triggered. 
<br>A "You Win" message will be displayed and a countdown will begin. 
<br>At the end of the countdown the game will reset at a `higher difficulty`, 
<br>or the player can press `any switch` to end the countdown and reset the game. 

If the frog's position would result in a `collision` with a vehicle, the player will lose a life and be reset to the starting position. 
<br>The player will begin with 3 lives, and once lives reach zero the Game Over state is triggered. 
<br>A "Game Over" message will be displayed and a countdown will begin. 
<br>At the end of the countdown the game will reset at a the `same difficulty`, 
<br>or the player can press `any switch` to end the countdown and reset the game. 

## Credits

>Project by: Natasha Rovelli
>
>CS3432 Spring2022
>
>Instructor: Pruitt 
>
>Due: 05/05/2022 10pm
>


To learn more about the project visit: 
 - [../README.md](../README.md)
