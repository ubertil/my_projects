			PATHFINDING ALGORITHM

This project was made in 2 weeks by me (uberti_l) and 3 partners (wadel_n, trogno_n and grella_c).

Team developpement : Me and grella_c : Graph construction, error parsing, graphical interface
		     trogno_n and wadel_n : Optimization , pathfinding and feeding algorithms


The aim of this program was to automatically bring all the ants to the exit with the less movement possible with only one ant per room.
We choosed to use pathfinding (Djiksta) combined with feeding algorithm to have probably one of the best efficient way to send all the ants to the exit.


Test maps are located in test folders and are formated like so:


1 - Nbr of ants (must be greater than 0)


2 - Rooms like so (room_name pos_x pos_y)

/!\ Rooms cannot be redifined and a name cannot be used twice (same goes for the position)
    You need to declare a start room and an end room, both with the special command ##start and ##end
    
    
3 - Links between room following this format : Room-AnotherRoom


	Type this to build the program : make re



A graphical interface is available in the bonus folder if you have the liblapin 1.7 (made by Jason Brillante - Epitech)

	Usage : ./lem-in < map.txt


Bonus usage(display the results in a more friendly way) : ./lem-in < map.txt | ./visu (/!\ liblapin 1.7 is required)
