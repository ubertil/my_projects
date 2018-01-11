open Contact

module type EVENT =
        sig
                type event
                val newEvent : (string * string * string * Contact.contact list) -> event
                val getDate : event -> string
                val getTime : event -> string
                val getDuration : event -> string
                val getListContact : event -> Contact.contact list
        end

module Event : EVENT =
        struct
                type event = (string * string * string * Contact.contact list)
                let newEvent            (a, b, c, d) = (a, b, c, d)
                let getDate             (a, _, _, _) = a
                let getTime             (_, b, _, _) = b
                let getDuration         (_, _, c, _) = c
                let getListContact      (_, _, _, d) = d
        end
