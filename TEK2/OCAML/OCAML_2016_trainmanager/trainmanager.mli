(*
* @Author: uberti_l
* @Date:   2017-05-09 13:24:11
* @Last Modified by:   uberti_l
* @Last Modified time: 2017-05-10 11:13:43
*)

open Train
open Trip

module type TRAINMANAGER =
  sig
    val addTrip     	: Trip.trip list -> Train.train list * string * string * int * string * string -> Trip.trip list
    val removeTrip   	: Trip.trip list -> string -> Trip.trip list
    val printTrips		: Trip.trip list -> unit
    val printHelp		: unit -> unit
  end

module Trainmanager : TRAINMANAGER