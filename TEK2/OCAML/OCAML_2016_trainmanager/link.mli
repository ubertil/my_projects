(*
* @Author: uberti_l
* @Date:   2017-05-10 11:13:30
* @Last Modified by:   uberti_l
* @Last Modified time: 2017-05-10 11:13:30
*)

module type LINK = 
	sig
		type link
		val newLink			: (string * string * int) -> link
		val getFirstNode	: link -> string
		val getLastNode		: link -> string
		val getDistance		: link -> int
	end

module Link : LINK