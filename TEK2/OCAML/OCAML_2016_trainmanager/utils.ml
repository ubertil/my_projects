(*
* @Author: uberti_l
* @Date:   2017-05-12 11:05:50
* @Last Modified by:   uberti_l
* @Last Modified time: 2017-05-12 11:53:50
*)

module type UTILS =
	sig
		val strncmp : string -> string -> int -> bool
	end

module Utils : UTILS = 
	struct
		let strncmp str1 str2 n = try match (String.sub str1 0 n) with
			| x -> if (x = str2) then true else false
		with _ -> false 
	end