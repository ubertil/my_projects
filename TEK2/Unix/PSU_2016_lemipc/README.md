# LemiPC

## Description

Lemipc is a program based on the shared memory system and semaphores. Fighters from each team join a random cell from the game board individualy and then fights to conquer the map.

A player die when he is surrended by at least two ennemies.

A game starts when at least 2 players from 2 differents teams are present on the map.

You can exit any client using CTRL + C.

Warning : Exiting from the host will terminate all others process.
See man entry in ```doc/lemipc.1.in``` or type ```make man && man lemipc```

## Prerequisites
- SFML

## Usage
```make re && make man && ./lemipc path_to_key team_numer [--mode=MODE]```


### Credits
*Developed by Nicolas Wadel (IA) and me (GFX, architecture)*