#!/bin/sh

SERVER_BIN=$(which ./zappy_server 2> /dev/null)
IA_BIN=$(which ./zappy_ai 2> /dev/null)
GRAPHIC_BIN=$(which ./zappy_graphic 2> /dev/null)
DIM_X=10
DIM_Y=10

if [ "$SERVER_BIN" = "" ] || [ "$IA_BIN" = "" ] || [ "$GRAPHIC_BIN" = "" ]; then
   echo "Missing binaries" >&2
   echo "Please type 'make re' to build the project" >&2
   exit 1
fi

if [ $# != 5 ] ; then
    echo "USAGE : $0 PORT NB_PLAYERS FREQ TEAM1 TEAM2" >&2
    echo "See usage for zappy_server for further explanation" >&2
    exit 1
fi

PORT=$1
NB_PLAYERS=$2
FREQ=$3
TEAM1=$4
TEAM2=$5

echo "[+] Launching server on port $PORT..."
$SERVER_BIN -n $TEAM1 $TEAM2 -x $DIM_X -y $DIM_Y -f $FREQ -c $NB_PLAYERS -p $PORT 2> /dev/null &

if [ $? -eq 0 ]; then
    echo "[+] Server started !"
    echo "[+] Connecting all players..."
    IDX=0
    echo ""
    echo "[+] $TEAM1 :"
    while [ "$IDX" -lt "$NB_PLAYERS" ]
    do
	$IA_BIN -n $TEAM1 -p $PORT &
	if [ $? -lt 0 ]; then
	    echo "[+] Could not start client. Aborting" >&2
	fi
	echo "New client for team $TEAM1"
	IDX=$((IDX + 1))
    done
    IDX=0
    echo ""
    echo "[+] $TEAM2 :"
    while [ "$IDX" -lt "$NB_PLAYERS" ]
    do
	$IA_BIN -n $TEAM2 -p $PORT 2> /dev/null &
	if [ $? -lt 0 ]; then
	    echo "[+] Could not start client. Aborting" >&2
	fi
	echo "New client for team $TEAM2"
	IDX=$((IDX + 1))
    done
    echo "[+] All players are connected !"
    echo "[+] Launching graphical client..."
    $GRAPHIC_BIN $PORT
    if [ $? -lt 0 ]; then
	echo "[+] Could not launch graphical client !" >&2
	exit 1
    fi
else
    echo "[+] Could not launch server ! Check your settings" >&2
    exit 1
fi
