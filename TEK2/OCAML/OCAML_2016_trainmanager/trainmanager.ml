(*
* @Author: uberti_l
* @Date:   2017-05-09 13:24:11
* @Last Modified by:   uberti_l
* @Last Modified time: 2017-05-16 14:31:36
*)

open Trip
open Link
open Train
open Dijkstra
open Time

exception Add_Train_With_Invalid_Data
exception Remove_Impossible_On_An_Empty_List

module type VAL =
  sig
    type t
    val length : t -> int
  end

module type SERIALIZE =
  sig
    type t_in
    type t_out
    val serialize : t_in -> t_out
    val unserialize : t_out -> t_in
  end

module type MAKESERIALIZE = functor (Val : VAL) -> SERIALIZE with type t_in = Val.t

module Useless : MAKESERIALIZE = functor (Val : VAL) ->
  struct
    type t_in = Val.t
    type t_out = (Val.t * int)
    let serialize v = (v, Val.length v)
    let unserialize (v, _) = v
  end

module StringSerialize = Useless (String)

let uselessf () =
  StringSerialize.serialize ""

let fake = StringSerialize.unserialize (uselessf ());;
print_string fake;;

module type TRAINMANAGER =
  sig
    val addTrip    	: Trip.trip list -> Train.train list * string * string * int * string * string -> Trip.trip list
    val removeTrip 	: Trip.trip list -> string -> Trip.trip list
    val printTrips  : Trip.trip list -> unit
    val printHelp   : unit -> unit
  end

module Trainmanager : TRAINMANAGER =
	struct
      let rec addTripCheckTrain trains name = match trains with
        | [] -> raise Add_Train_With_Invalid_Data 
        | hd::tl -> if (name = (Train.getName hd)) then hd else addTripCheckTrain tl name

      let addTripCheckDestination trips dest_array to_go name id= 
        let rec auxCheck saved_trips trips dest_array to_go idx = match trips with
          | [] -> raise Add_Train_With_Invalid_Data
          | hd::tl -> if ((List.length to_go) = (Array.length dest_array)) then begin print_string "Trip created: "; print_string name; print_string " "; print_endline (string_of_int id); to_go; end
                      else if (((Link.getFirstNode hd) = dest_array.(idx)) || ((Link.getLastNode hd) = dest_array.(idx))) then auxCheck saved_trips saved_trips dest_array (to_go @ [dest_array.(idx)]) (idx + 1)
                      else auxCheck saved_trips tl dest_array to_go idx
        in auxCheck trips trips dest_array to_go 0

			let addTrip l (trains, cmd, a, b, c, d) =
				List.rev ((Trip.newTrip ((addTripCheckTrain trains a), b, 
                  (Time.getTime cmd),
                  (addTripCheckDestination (Train.getLinkList (addTripCheckTrain trains a)) (Array.of_list (Str.split (Str.regexp "[,]+") d)) [] a b)))::(List.rev l))

      let printHelp () =
        print_endline "List of availables commands :";
        print_endline "\thelp : Display this page";
        print_endline "\tdelete ID : Delete train with ID";
        print_endline "\tlist : Display all trains informations";
        print_endline "\tcreate [TGV | Eurostar | Thalys] DATE TIME DESTINATION : Create a new trip";
        print_endline "\tquit : Quit this program"

			let removeTrip mylist to_match = match mylist with
        | [] -> raise Remove_Impossible_On_An_Empty_List
        | _ -> let rec aux idx newlist mylist to_match = match mylist with
          | a::b when (Train.getName (Trip.getTrain a)) ^ (string_of_int (Trip.getId a)) <> to_match -> aux (idx + 1) (a::newlist) b to_match
          | a::b when (Train.getName (Trip.getTrain a)) ^ (string_of_int (Trip.getId a)) = to_match -> aux (idx + 1) newlist b to_match
          | _ -> List.rev newlist
        in aux 0 [] mylist to_match

      let printTrips mylist = 
        Dijkstra.printTrips mylist
	end