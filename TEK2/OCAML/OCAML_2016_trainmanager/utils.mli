(*
* @Author: uberti_l
* @Date:   2017-05-12 11:05:50
* @Last Modified by:   uberti_l
* @Last Modified time: 2017-05-12 11:08:37
*)

module type UTILS =
	sig
		val strncmp : string -> string -> int -> bool
	end

module Utils : UTILS