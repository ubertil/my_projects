#!/bin/sh

add_in_list ()
{
    add_value=$1
    add_list=$2
}

display_list ()
{
    param=$1
    echo "param : $param"
    value=${param%,*}
    list=${param#*,}
    while [ $list != "0" ] && [ $list ]
    do
	echo $value
	param=$list
	echo "param : $param"
	value=${param%,*}
	list=${param#*,}
	exit 0
    done
}
