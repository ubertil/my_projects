# Arcade

## Description

Arcade is a small arcade machine developed in modern C++. The twist is that you can change the graphical library at runtime using numkeys. Games and graphical libraries are .so files loaded thanks to the same interface.

2 games are available:
- Pacman
- Snake

3 graphical libraries are available:
- OpenGL
- SFML
- LibCaca (yes)

A leaderboard system is also available after playing a few games. Settings are also available but very limited. I hope you'll like the old arcade style vibes !

## Prerequisites
- make and g++ installed
- OpenGL
- LibCaca (yes this is a thing and God it's awful ...)
- SFML

## Usage

Type ```make``` which will build all the ressources for the projects
Then to play : ```./arcade ./path_to_graphical_lib```

Ex : ```./arcade ./lib/lib_arcade_opengl.so```

### Documentation
See ```doc``` folder on how to build your own version and run them

### Credits
*Developed by Nicolas Trognot (Graphic, Games) and me (Graphics, menu, interface, dynamic loading)*