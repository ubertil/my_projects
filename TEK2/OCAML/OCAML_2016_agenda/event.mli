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

module Event : EVENT
