#!/bin/sh
BIN=$(which ../trade_moulinette.php)
TRADE=$(which ../trade)
DRAW=0
OUT="graph"$$
DIR="../stock_exchange"

if [ -z $1 ] || [ $# -gt 2 ]; then
    echo "Usage : $0 money draw_graph={0/1}" >&2
    echo "money : Starting stash of money to invest." >&2
    echo "draw_graph={0/1}: Set to 1 if you want to draw graph." >&2
    exit 1
fi
if [ "$BIN" = "" ]; then
    echo "Error: Program trade_moulinette needs to be in the root folder."
    exit 1
fi
if [ "$TRADE" = "" ]; then
    echo "Error: Could not find binary trade."
    exit 1
fi
if [ $# -eq 2 ] && [ $2 = "draw_graph=1" ]; then
    GNUPLOT=$(which gnuplot)
    if [ "$GNUPLOT" = "" ]; then
	echo "Gnuplot is required to draw graph." >&2
	echo "Please install it or remove the draw_graph option." >&2
	exit 1
    else
	DRAW=1
    fi
elif [ $# -eq 2 ]; then
     echo "[+] Ignoring second argument"
     echo "[+] Setup complete"
fi

echo "[+] Launching trade algorithm on stocks from source dir $DIR"
FILES=($(ls $DIR))
NB_FILES=${#FILES[@]}
IDX=0
while [ "$IDX" -lt "$NB_FILES" ]
do
    echo ""
    echo "[+] ${FILES[$IDX]}"
    $BIN -p ../trade -f $DIR/${FILES[$IDX]} -m $1
    if [ $DRAW -eq 1 ]; then
	$($GNUPLOT .conf &)
    fi
    IDX=$((IDX + 1))
done
exit 0
