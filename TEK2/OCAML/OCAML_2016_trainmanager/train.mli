(*
* @Author: uberti_l
* @Date:   2017-05-09 13:24:11
* @Last Modified by:   uberti_l
* @Last Modified time: 2017-05-10 11:13:43
*)

open Link

module type TRAIN =
        sig
                type train
                val newTrain            : (string * int * Link.link list) -> train
                val getName             : train -> string
                val getSpeed            : train -> int
                val getLinkList         : train -> Link.link list
        end

module Train : TRAIN