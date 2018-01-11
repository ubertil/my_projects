(*
* @Author: uberti_l
* @Date:   2017-05-10 11:13:30
* @Last Modified by:   uberti_l
* @Last Modified time: 2017-05-11 13:11:05
*)

module type LINK = 
	sig
		type link
		val newLink			: (string * string * int) -> link
		val getFirstNode	: link -> string
		val getLastNode		: link -> string
		val getDistance		: link -> int
	end

module Link : LINK =
	struct
		type link = (string * string * int)
		let newLink			(a, b, c) = (a, b, c)
       	let getFirstNode   	(a, _, _) = a
       	let getLastNode		(_, b, _) = b
       	let getDistance 	(_, _, c) = c
	end
	