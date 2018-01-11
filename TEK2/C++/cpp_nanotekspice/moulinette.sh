#!/bin/bash
RESULT=0
PIPE=pipe
# Shell patern à changer suivant votre shell
SHELLPATERN="> "
OUT=out
NANO="./nanotekspice.$$"
MKFIFO=$(which mkfifo)
TAIL=$(which tail)
bin=$(which ./nanotekspice)
if [ "$bin" = "" ]
then
    echo "Besoin du binaire './nanotekspice'"
    exit
fi

cp nanotekspice $NANO

kill_nano()
{
  if [ `pidof $NANO | wc -l` -ne 0 ] ; then
    killall -9 $NANO 2>&1 > /dev/null
  fi
  if [ `pidof mytail | wc -l` -ne 0 ] ; then
    killall mytail 2>&1 > /dev/null
  fi
  rm -f $PIPE $OUT 2>&1 > /dev/null
}

launch_nano()
{
  $MKFIFO $PIPE
  cp $TAIL mytail 2>&1 >/dev/null
  (./mytail -f $PIPE 2>/dev/null | $NANO "$@" > $OUT 2>&1 &) >/dev/null 2>/dev/null
}

test_map()
{
    kill_nano 2>&1 > /dev/null
    launch_nano $1 2>&1 > /dev/null
    FILENAME=$(echo $1 | cut -f1 -d' ')
    echo -n "[+] $FILENAME : "
    sleep 0.3
    cat $OUT | tr -d "$SHELLPATERN"' ' | tr '\n' , | tr -d ',' | grep "$2" 2>&1 >/dev/null
    if [ $? -eq 0 ]; then
	RESULT=$((RESULT+1))
	if [ "$LOG" == "1" ] ; then
	    echo "$FILENAME : OK" >> $FILE
	fi
	echo "OK"
    else
	if [ "$LOG" == "1" ] ; then
	    echo "$FILENAME : KO" >> $FILE
	    echo "Expected :" >> $FILE
	    echo "$2" >> $FILE
	    echo "-----------" >> $FILE
	    echo "Got :" >> $FILE
	    cat $OUT | tr -d "$SHELLPATERN"' '  >> $FILE
	fi
	echo "KO"
    fi
}

echo " ==/ Moulinette Nanotekspice Uberti_l / Grella_c \=="
echo
echo "[+] $USER, souhaitez-vous enregistrez vos résultats (O/N)?"
read LOG
if [ "$LOG" == "O" ]; then
    LOG=1
    DATE=($(date -u +%m:%d:%y))
    FILE="result_$DATE"
    touch $FILE
    echo "Moulinette du $DATE" >> $FILE
    echo >> $FILE
    echo "Moulinette du $DATE"
    echo "[+] Log activé dans le fichier $FILE"
fi

echo "[+] Début des tests..."
echo

## EASY TEST
if [ "$LOG" == "1" ]; then
    echo "Easy map :" >> $FILE
fi
echo "Easy map :"
test_map "chipsets/inf.nts i=1" "out=1"
test_map "chipsets/easy/adder.nts a0=0 a1=0 a2=0 a3=0 b0=0 b1=0 b2=0 b3=0 cin=0" "cout=0o0=0o1=0o2=0o3=0"
test_map "chipsets/easy/and.nts a=0 b=0" "s=0"
test_map "chipsets/easy/counter.nts" "notest"
test_map "chipsets/easy/d_latch.nts" "notest"
test_map "chipsets/easy/decoder.nts" "notest"
test_map "chipsets/easy/johnson.nts" "notest"
test_map "chipsets/easy/nand.nts a=0 b=0" "s=1"
test_map "chipsets/easy/nor.nts a=0 b=0" "s=1"
test_map "chipsets/easy/not.nts i0=1 i1=0 i2=1 i3=0" "o0=0o1=1o2=0o3=1o4=-1o5=-1"
test_map "chipsets/easy/or.nts a=0 b=1" "s=1"
test_map "chipsets/easy/xor.nts a=1 b=0" "s=1"


## MEDIUM TEST
if [ "$LOG" == "1" ]; then
    echo >> $FILE
    echo "Medium map :" >> $FILE
fi
echo
echo "Medium map :"
test_map "chipsets/medium/5input_and.nts a=1 b=1 c=1 d=0 e=1" "s=0"
test_map "chipsets/medium/5input_nand.nts a=1 b=1 c=1 d=0 e=1" "s=1"
test_map "chipsets/medium/5input_nor.nts a=1 b=1 c=1 d=0 e=1" "s=0"
test_map "chipsets/medium/5input_or.nts a=1 b=1 c=1 d=0 e=1" "s=1"
test_map "chipsets/medium/mandion.nts a=0 b=1 c=1" "s=1"

## HARD TEST
if [ "$LOG" == "1" ]; then
    echo >> $FILE
    echo "Hard map :" >> $FILE
fi
echo
echo "Hard map :"
test_map "chipsets/hard/romxor.nts" "notest"


echo "Resultats : $RESULT/19"
if [ "$LOG" == "1" ]; then
    echo >> $FILE
    echo "Resultats : $RESULT/18" >> $FILE
    echo "Voir les logs pour plus d'informations"
fi

kill_nano
rm -f $PIPE $OUT $NANO mytail 2>&1 > /dev/null
