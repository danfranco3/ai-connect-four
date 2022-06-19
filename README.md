# Introduction

Hello!

This is a University project where you can play connect four with your computer!

Using either minmax or alpha-beta pruning, the AI will beat you.

Also, one thing to notice is the heuristic used for this project does not favor quicker wins.

If X can win in moves 13 and 17, there is no incentive for it to win earlier.

# Instructions

You can play with three different depths (shallow, medium or deep) for both algorithms. This exists because of the different depths for the minmax search.

To compile the program please run

            g++ .\main.cpp .\play_game.cpp .\utility.cpp .\game.cpp .\interaction.cpp -o connectfour.exe

And then run with either minmax or alphabeta and the depth.

You can also define #DEBUG in the play_game.cpp file if you want to see the number of nodes explored and the time taken to reach the solution. 

Example of run:

                .\connectfour.exe minmax shallow

or

                .\connectfour.exe alphabeta medium