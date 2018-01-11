(*
* @Author: uberti_l
* @Date:   2017-05-09 13:24:11
* @Last Modified by:   uberti_l
* @Last Modified time: 2017-05-11 13:19:10
*)

open Train

module type TRIP =
	sig
		type trip
		val newTrip 		:	(Train.train * int * float * string list) -> trip
		val getTrain		:	trip -> Train.train
		val getId			:	trip -> int
		val getDate			:	trip -> float
		val getDestination 	:	trip -> string list
	end

module Trip : TRIP