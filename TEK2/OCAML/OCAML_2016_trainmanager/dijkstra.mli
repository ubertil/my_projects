(*
* @Author: uberti_l
* @Date:   2017-05-16 14:06:27
* @Last Modified by:   uberti_l
* @Last Modified time: 2017-05-16 14:19:44
*)

open Trip

exception Found of int;;
exception No_way;;
type cost = Nan | Cost of float
type adj_mat = cost array array
type 'a graph = { mutable ind : int; size : int; nodes : 'a array; m : adj_mat }
type comp_state = { paths : int array; already_treated : bool array; distances : cost array; source : int; nn : int}

module type DIJKSTRA =
	sig
		val printTrips : Trip.trip list -> unit
		val init_graph : unit -> string graph
	end

module Dijkstra : DIJKSTRA