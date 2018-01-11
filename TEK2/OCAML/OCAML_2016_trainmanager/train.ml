(*
* @Author: uberti_l
* @Date:   2017-05-10 10:22:27
* @Last Modified by:   uberti_l
* @Last Modified time: 2017-05-12 14:54:34
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

module Train : TRAIN =
        struct
                type train = (string * int * Link.link list)
                let newTrain            (a, b, c) = (a, b, c)
                let getName             (a, _, _) = a
                let getSpeed            (_, b, _) = b
                let getLinkList         (_, _, c) = c
        end
