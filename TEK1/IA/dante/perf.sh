#!/bin/sh

GEN=./$1
TYPE=$2
PROG="./solver"
FILE="trace_"
TRACE=$FILE$(date +%s)
bin=`which ./solver`
bin2=`which $GEN`
TIME=$(mktemp)
MAZES=$(mktemp)
if [ -z $1 ] || [ -z $2 ] || [ "$TYPE" != "parfait" ] && [ "$TYPE" != "imparfait" ]
then
    echo "Usage : ./perf.sh your_maze_generator {parfait,imparfait}"
    exit
fi
if [ "$bin" = "" ] || [ "$bin2" = "" ]
then
    echo "Can't find one of your binary"
    exit
fi
get_all_mazes()
{
    echo "Generating all mazes for tests. Please wait..."
    $GEN 10 10 $TYPE > maze1.txt
    $GEN 100 100 $TYPE > maze2.txt
    $GEN 500 500 $TYPE > maze3.txt
    $GEN 1000 1000 $TYPE > maze4.txt
    echo "Generation done ! Starting tests..."
}

my_init()
{
    echo "Hello $USER, ready to test your solver's time performance ?"
    echo "Sweet ! Let's test them !"
}

do_test()
{
    param=$1
    time -o "${TIME}" -f "%e" $PROG $param 2>&1 >/dev/null
    printf "Number of seconds used by solver : %s\n" $(cat "${TIME}")
}

launch_test()
{
    echo "--> Little Maze"
    echo "10 * 10"
    do_test "maze1.txt"
    echo " "
    echo "--> Medium Maze"
    echo "100 * 100"
    do_test "maze2.txt"
    echo " "
    echo "--> Hard Maze !"
    echo "500 * 500"
    do_test "maze3.txt"
    echo " "
    echo "--> A-Maze-Ing !"
    echo "1000 * 1000"
    do_test "maze4.txt"
    echo " "
}

mytrace()
{
    echo ""
    sleep 1
    echo ">============ RESULTS =============<"
    echo ""
    cat "$TRACE"
    echo ""
}

my_init
get_all_mazes
launch_test > "$TRACE"
mytrace
rm maze1.txt maze2.txt maze3.txt maze4.txt
