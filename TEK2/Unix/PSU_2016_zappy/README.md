# Zappy

## Description

Zappy is a "game" coded in C. The goal of this game is pretty complex yet simple : 
- Different teams are playing on a server which is representing a small world
- Each team goal is to evolve. Evolving requires you to gather specific conditions like having a specific number of stones or teammates around you
- The first team to reach the max level wins

*Zappy is made of 3 parts*:
- zappy_server which hosts the game
- zappy_graphics which is the graphical observer of the game
- zappy_ai is our IA (which doesn't fully work due to a small mistake ...)

## Prerequisites
- SDL
- Epoll (so this will only work on POSIX system)

## Usage

Type ```make``` which will build all the ressources for the projects
Then to play : ```./launch_game.sh```

### Documentation
See ```resources/protocole.pdf``` to understand the rules

### Credits
*Developed by WTF (Web Team Framework)*