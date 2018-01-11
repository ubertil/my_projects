(*
* @Author: uberti_l
* @Date:   2017-05-09 13:24:11
* @Last Modified by:   uberti_l
* @Last Modified time: 2017-05-12 16:50:51
*)

exception Invalid_Date_Format

module type TIME =
  sig
    val promptTime     	: float -> string
    val getTime   		: string -> float
    val travelTime		: float -> float -> float -> float
  end

module Time : TIME