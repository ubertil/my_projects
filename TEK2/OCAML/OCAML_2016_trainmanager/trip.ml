(*
* @Author: uberti_l
* @Date:   2017-05-11 13:30:13
* @Last Modified by:   uberti_l
* @Last Modified time: 2017-05-16 10:58:47
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

module Trip : TRIP =
	struct
		type trip = (Train.train * int * float * string list)
		let newTrip 		(a, b, c, d) = (a, b, c, d)
		let getTrain		(a, _, _, _) = a
		let getId			(_, b, _, _) = b
		let getDate			(_, _, c, _) = c
		let getDestination 	(_, _, _, d) = d
	end