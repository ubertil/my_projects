# GKrellm

## Description

GKrellM is a single process stack of system monitors which supports applying themes to match its appearance to your window manager, Gtk, or any other theme.
Here, we built our custom version in C++ which monitors different things on your computer like network usage, RAM, etc.

Everything you'll see is handmade, even the font ! (See ```.font.txt```to laugh)
And in less than 48 hours !

## Prerequisites
- make and g++ installed
- SDL installed
- Ncurses

## Usage
```make re && ./my_gkrellm```

I recommend switching off the RAM module using ```--noRAM``` argument
See ```./my_gkrellm --help``` for more options

### Credits
*Developed by Alexis Papadimitriou (SDL graphics) and me (Modules, interface)*