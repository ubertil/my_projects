my_list="5,my_list2"
my_list2="12,my_list3"
my_list3="7,my_list4"
my_list4="42,0"

echo "Display list :"
display_list "$my_list"

echo "Add elem in list"
add_in_list 2 "$my_list"
add_in_list 3 "$my_list"
add_in_list 4 "$my_list"
add_in_list 5 "$my_list"

echo "Display list :"
display_list "$my_list"

