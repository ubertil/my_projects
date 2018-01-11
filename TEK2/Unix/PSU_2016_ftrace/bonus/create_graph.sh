#!/bin/sh

BIN=$(which dot)
OUT="graph"$$

if [ "$BIN" = "" ]
then
    echo "Need 'dot' to be installed on your computer"
fi
if [ $# != 1 ]
then
    echo "Usage : $0 output_file"
    echo "output_file : File containing ftrace output (usually ending in .dot)"
    exit 1
fi
echo "[+] Generating PNG file..."
dot -Tpng $1 -o $OUT.png
if [ $? -eq 0 ]
then
    echo "[+] File $OUT was created !"
    read -p "Would you like to display it ? (Y/n) : " ANSWER
    if [ "$ANSWER" = "Y" ] || [ "$ANSWER" = "y" ]
    then
       display $OUT.png
    fi
    exit 0
fi
echo "/!\ Something went wrong !"
exit 1
