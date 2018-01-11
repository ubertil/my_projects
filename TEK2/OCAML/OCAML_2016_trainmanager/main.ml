(*
* @Author: uberti_l
* @Date:   2017-05-10 10:59:29
* @Last Modified by:   uberti_l
* @Last Modified time: 2017-05-16 14:32:02
*)

open Trainmanager
open Train
open Link
open Utils

exception Stop_Interpreter

let t_TGV = Train.newTrain ("TGV", 230, 
							[Link.newLink ("Paris", "Lyon", 427);
							Link.newLink ("Dijon", "Paris", 192);
							Link.newLink ("Paris", "Lille", 225);
							Link.newLink ("Paris", "Nancy", 327);
							Link.newLink ("Dijon", "Nancy", 226);
							Link.newLink ("Le Mans", "Paris", 201);
							Link.newLink ("Lyon", "Marseille", 325);
							Link.newLink ("Paris", "Le Havre", 230);
							Link.newLink ("Rennes", "Le Mans", 163);
							Link.newLink ("Le Mans", "Nantes", 183);
							Link.newLink ("Paris", "Bordeaux", 568);
							Link.newLink ("Nancy", "Strasbourg", 149);
							Link.newLink ("Paris", "Strasbourg", 449);
							Link.newLink ("Dijon", "Strasbourg", 309);
							Link.newLink ("Toulouse", "Bordeaux", 256);
							Link.newLink ("Montpellier", "Toulouse", 248);
							Link.newLink ("Marseille", "Montpellier", 176)]
						);;

let t_Thalys = Train.newTrain ("Thalys", 210, 
								[Link.newLink ("Paris", "Lille", 225);
								Link.newLink ("Liege", "Cologne", 118);
								Link.newLink ("Cologne", "Essen", 81);
								Link.newLink ("Brussels", "Liege", 104);
								Link.newLink ("Lille", "Brussels", 106);
								Link.newLink ("Brussels", "Amsterdam", 211)]
							);;

let t_Eurostar = Train.newTrain ("Eurostar", 160,
								[Link.newLink ("Paris", "Lille", 225);
								Link.newLink ("Lille", "London", 269);
								Link.newLink ("Lille", "Brussels", 106)]
							);;

(* Init Random generator *)
Random.self_init;;

let trains = [t_TGV; t_Thalys; t_Eurostar];;
let trips = [];;

(* Main function *)
let rec main trips =
	let input trips = match (read_line()) with
		| "list" -> Trainmanager.printTrips trips; trips
		| "quit" -> raise Stop_Interpreter
		| "help" -> Trainmanager.printHelp (); trips
		| x -> if ((Utils.strncmp x "delete" 6) && ((Array.length (Array.of_list (Str.split (Str.regexp " +") x))) = 2)) then
					try Trainmanager.removeTrip trips (Array.of_list (Str.split (Str.regexp " +") x)).(1) with _ -> trips
 				else if ((Utils.strncmp x "create" 6) && ((Array.length (Array.of_list (Str.split (Str.regexp " +") x))) = 5)) then 
 					try 
 						Trainmanager.addTrip trips (trains, x, (Array.of_list (Str.split (Str.regexp " +") x)).(1), ((Random.int 8999) + 1000), (Array.of_list (Str.split (Str.regexp " +") x)).(2), (Array.of_list (Str.split (Str.regexp " +") x)).(4))
					with _ -> trips;
				else if (x = "") then trips
				else begin print_string "Unknown command '"; print_string x; print_endline "'"; trips; end 
	in try main (input trips) with _ -> ()
;;

(* Launch program *)
let _ = main trips;;
