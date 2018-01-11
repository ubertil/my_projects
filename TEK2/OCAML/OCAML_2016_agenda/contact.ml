module type CONTACT =
        sig
                type contact
                val newContact          : (string * string * int * string * string) -> contact
                val getFirstName        : contact -> string
                val getLastName         : contact -> string
                val getAge              : contact -> int
                val getEmail            : contact -> string
                val getPhone            : contact -> string
        end

module Contact : CONTACT =
        struct
                type contact = (string * string * int * string * string)
                let newContact          (a, b, c, d, e) = (a, b, c, d, e)
                let getFirstName        (a, _, _, _, _) = a
                let getLastName         (_, b, _, _, _) = b
                let getAge              (_, _, c, _, _) = c
                let getEmail            (_, _, _, d, _) = d
                let getPhone            (_, _, _, _, e) = e
        end
