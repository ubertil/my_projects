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

        module Contact : CONTACT
