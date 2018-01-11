open Contact
open Event

type field = All | Id | FirstName | LastName | Age | Email | Phone
type field_event = AllEv | IdEv | Date | Time | Duration | Contact

exception Add_Contact_With_Invalid_Data
exception Remove_Impossible_On_An_Empty_List
exception Remove_Using_An_Invalid_Id

module type AGENDA =
  sig
    val addContact     : Contact.contact list -> string * string * int * string * string -> Contact.contact list
    val getContactId   : Contact.contact list -> field -> string -> int
    val removeContact  : Contact.contact list -> int -> Contact.contact list
    val replaceContact : Contact.contact list -> int -> string * string * int * string * string -> Contact.contact list
    val printContacts  : Contact.contact list -> field -> string -> unit

    val addEvent        : Event.event list -> string * string * string * Contact.contact list -> Event.event list
    val getEventId      : Event.event list -> field_event -> string -> int
    val removeEvent     : Event.event list -> int -> Event.event list
    val printEvents     : Event.event list -> field_event -> string -> unit
  end

module Agenda : AGENDA =
        struct
                let rec checkString container string_to_find idx = match container with
                        | x when String.length x < String.length string_to_find -> false
                        | x when idx + String.length string_to_find > String.length x -> false
                        | x when String.sub (String.lowercase x) idx (String.length string_to_find) =
                                String.lowercase string_to_find -> true
                        | _ -> checkString container string_to_find (idx + 1)

                let is_int_from_char = function
                        | c when c >= '0' && c <= '9' -> true
                        | _ -> false

                let addContactCheckAge = function
                        | x when x >= 0 && x <= 120 -> x
                        | _ -> raise Add_Contact_With_Invalid_Data
                let addContactCheckFirstName = function
                        | "" -> raise Add_Contact_With_Invalid_Data
                        | s -> String.capitalize (String.trim s)

                let addContactCheckLastName = function
                        | "" -> raise Add_Contact_With_Invalid_Data
                        | s -> String.uppercase (String.trim s)

                let addContactCheckEmail = function
                        | s when try String.index s '@' > 0 &&
                                String.index_from s (String.index s '@') '.' > (String.index s '@') + 1 &&
                                String.index_from s (String.index s '@') '.' < String.length s - 1
                            with Not_found -> raise Add_Contact_With_Invalid_Data -> s
                        | _ -> raise Add_Contact_With_Invalid_Data 

                let addContactCheckPhone s = match s with
                        | x when String.length x = 14 &&
                                 x.[0] = '0' &&
                                 is_int_from_char x.[1] = true &&
                                 x.[2] = ' ' &&
                                 is_int_from_char x.[3] = true &&
                                 is_int_from_char x.[4] = true &&
                                 x.[5] = ' ' &&
                                 is_int_from_char x.[6] = true &&
                                 is_int_from_char x.[7] = true &&
                                 x.[8] = ' ' &&
                                 is_int_from_char x.[9] = true &&
                                 is_int_from_char x.[10] = true &&
                                 x.[11] = ' ' &&
                                 is_int_from_char x.[12] = true &&
                                 is_int_from_char x.[13] = true -> x
                        | _ -> raise Add_Contact_With_Invalid_Data

                let addContact l (a, b, c, d, e) =
                        List.sort (compare) ((Contact.newContact  (addContactCheckFirstName a, addContactCheckLastName b, 
                                              addContactCheckAge c, addContactCheckEmail d,
                                              addContactCheckPhone e))::l)


                let getContactId mylist myfield mystring = 
                        let rec aux idx mylist myfield mystring = match mylist with
                                | hd::tl when (myfield = All || myfield = FirstName) &&
                                              checkString (String.lowercase (Contact.getFirstName hd))
                                              (String.lowercase mystring) 0 = true -> idx
                                | hd::tl when (myfield = All || myfield = LastName) &&
                                              checkString (String.lowercase (Contact.getLastName hd))
                                              (String.lowercase mystring) 0 = true -> idx
                                | hd::tl when (myfield = All || myfield = Email) &&
                                              checkString (String.lowercase (Contact.getEmail hd))
                                              (String.lowercase mystring) 0 = true -> idx
                                | hd::tl when (myfield = All || myfield = Phone) &&
                                              checkString (String.lowercase (Contact.getPhone hd))
                                              (String.lowercase mystring) 0 = true -> idx
                                | hd::tl when (myfield = All || myfield = Age) &&
                                              checkString (string_of_int (Contact.getAge hd))
                                              mystring 0 = true -> idx
                                | hd::tl when (myfield = All || myfield = Id) &&
                                              checkString (string_of_int idx) mystring 0 = true -> idx
                                | [] -> -1
                                | hd::tl -> aux (idx + 1) tl myfield mystring
                in aux 0 mylist myfield mystring


                let removeContact mylist pos = match mylist with
                        | [] -> raise Remove_Impossible_On_An_Empty_List
                        | x when pos < 0 ||
                                 pos >= List.length mylist -> raise Remove_Using_An_Invalid_Id
                        | _ -> let rec aux idx newlist mylist pos = match mylist with
                                        | a::b when idx != pos -> aux (idx + 1) (a::newlist) b pos
                                        | a::b when idx == pos -> aux (idx + 1) newlist b pos
                                        | _ -> List.sort (compare) newlist
                                in aux 0 [] mylist pos


                let replaceContact mylist pos z = addContact (removeContact mylist pos) z
                
                
                let formatString s maxlen = match s with
                | x when String.length x >= maxlen -> String.sub x 0 maxlen
                | x -> x

                let printContacts mylist myfield mystring =
                        let rec printSpace total length = match length with
                                | x when x = total -> ()
                                | _ -> begin
                                        print_string " ";
                                        printSpace total (length + 1)
                                end
                        in let printContact idx mycontact =
                                print_string (formatString (string_of_int idx) 4);
                                printSpace 4 (String.length (formatString (string_of_int idx) 4));
                                print_string (formatString (Contact.getFirstName mycontact) 16);
                                printSpace 16 (String.length (formatString (Contact.getFirstName mycontact) 16));
                                print_string (formatString (Contact.getLastName mycontact) 16);
                                printSpace 16 (String.length (formatString (Contact.getLastName mycontact) 16));
                                print_int (Contact.getAge mycontact);
                                printSpace 4 (String.length (string_of_int (Contact.getAge mycontact)));
                                print_string (formatString (Contact.getEmail mycontact) 32);
                                printSpace 32 (String.length (formatString (Contact.getEmail mycontact) 32));
                                print_endline (Contact.getPhone mycontact)
                        in
                        let rec aux idx mylist myfield mystring = match mylist with
                                | hd::tl when mystring = "" -> begin
                                        printContact idx hd; aux (idx + 1) tl myfield mystring
                                  end
                                | hd::tl when (myfield = All || myfield = FirstName) &&
                                  (checkString (Contact.getFirstName hd) mystring 0 = true) -> begin
                                        printContact idx hd; aux (idx + 1) tl myfield mystring
                                  end
                                | hd::tl when (myfield = All || myfield = LastName) &&
                                  (checkString (Contact.getLastName hd) mystring 0 = true) -> begin
                                        printContact idx hd; aux (idx + 1) tl myfield mystring
                                  end
                                | hd::tl when (myfield = All || myfield = Age) &&
                                  (checkString (string_of_int (Contact.getAge hd)) mystring 0 = true) -> begin
                                        printContact idx hd; aux (idx + 1) tl myfield mystring
                                  end
                                | hd::tl when (myfield = All || myfield = Email) &&
                                  (checkString (Contact.getEmail hd) mystring 0 = true) -> begin
                                        printContact idx hd; aux (idx + 1) tl myfield mystring
                                  end
                                | hd::tl when (myfield = All || myfield = Phone) &&
                                  (checkString (Contact.getPhone hd) mystring 0 = true) -> begin
                                        printContact idx hd; aux (idx + 1) tl myfield mystring
                                  end
                                | [] -> ()
                                | hd::tl -> aux (idx + 1) tl myfield mystring
                 in aux 0 mylist myfield mystring


                let addEvent l (a, b, c, d) =
                        List.sort (compare) ((Event.newEvent (a, b, c, d))::l)

                let getEventId mylist myfield mystring =
                        let rec aux idx mylist myfield mystring = match mylist with
                                | hd::tl when (myfield = AllEv || myfield = Date) &&
                                              checkString (String.lowercase (Event.getDate hd))
                                              (String.lowercase mystring) 0 = true -> idx
                                | hd::tl when (myfield = AllEv || myfield = Time) &&
                                              checkString (String.lowercase (Event.getTime hd))
                                              (String.lowercase mystring) 0 = true -> idx
                                | hd::tl when (myfield = AllEv || myfield = Duration) &&
                                              checkString (String.lowercase (Event.getDuration hd))
                                              (String.lowercase mystring) 0 = true -> idx
                                | hd::tl when (myfield = AllEv || myfield = IdEv) &&
                                              checkString (string_of_int idx) mystring 0 = true -> idx
                                | [] -> -1
                                | hd::tl -> aux (idx + 1) tl myfield mystring
                in aux 0 mylist myfield mystring

                let removeEvent mylist pos = match mylist with
                        | [] -> raise Remove_Impossible_On_An_Empty_List
                        | x when pos < 0 ||
                                 pos >= List.length mylist -> raise Remove_Using_An_Invalid_Id
                        | _ -> let rec aux idx newlist mylist pos = match mylist with
                                        | a::b when idx != pos -> aux (idx + 1) (a::newlist) b pos
                                        | a::b when idx == pos -> aux (idx + 1) newlist b pos
                                        | _ -> List.sort (compare) newlist
                                in aux 0 [] mylist pos

                let printEvents mylist myfield mystring =
                        let rec printEmail = function
                                | [] -> ()
                                | a::b -> begin
                                        print_string (Contact.getEmail a);
                                        print_string " ";
                                        printEmail b
                                end
                        in let rec printSpace total length = match length with
                                | x when x = total -> ()
                                | _ -> begin
                                        print_string " ";
                                        printSpace total (length + 1)
                                end
                        in let printEvent idx myevent =
                                print_string (formatString (string_of_int idx) 4);
                                printSpace 4 (String.length (formatString (string_of_int idx) 4));
                                print_string (formatString (Event.getDate myevent) 16);
                                printSpace 16 (String.length (formatString (Event.getDate myevent) 16));
                                print_string (formatString (Event.getTime myevent) 16);
                                printSpace 16 (String.length (formatString (Event.getTime myevent) 16));
                                print_string (formatString (Event.getDuration myevent) 16);
                                printSpace 16 (String.length (formatString (Event.getDuration myevent) 16));
                                printEmail (Event.getListContact myevent);
                                print_endline "";
                                print_endline ""
                        in
                        let rec aux idx mylist myfield mystring = match mylist with
                                | hd::tl when mystring = "" -> begin
                                        printEvent idx hd; aux (idx + 1) tl myfield mystring
                                  end
                                | hd::tl when (myfield = AllEv || myfield = Date) &&
                                  (checkString (Event.getDate hd) mystring 0 = true) -> begin
                                        printEvent idx hd; aux (idx + 1) tl myfield mystring
                                  end
                                | hd::tl when (myfield = AllEv || myfield = Time) &&
                                  (checkString (Event.getTime hd) mystring 0 = true) -> begin
                                        printEvent idx hd; aux (idx + 1) tl myfield mystring
                                  end
                                | hd::tl when (myfield = AllEv || myfield = Duration) &&
                                  (checkString (Event.getDuration hd) mystring 0 = true) -> begin
                                        printEvent idx hd; aux (idx + 1) tl myfield mystring
                                  end
                                | [] -> ()
                                | hd::tl -> aux (idx + 1) tl myfield mystring
                 in aux 0 mylist myfield mystring
                          
        end
