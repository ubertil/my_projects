(*
* @Author: uberti_l
* @Date:   2017-05-12 17:02:39
* @Last Modified by:   uberti_l
* @Last Modified time: 2017-05-15 11:56:06
*)

exception Invalid_Date_Format

module type TIME =
  sig
    val promptTime      : float -> string
    val getTime         : string -> float
    val travelTime      : float -> float -> float -> float
  end

module Time : TIME =
    struct
        let promptTime time =
            let tm = Unix.localtime time in
                Printf.sprintf "(%02d-%02d-%04d,%02d:%02d)"
                tm.Unix.tm_mday
                (tm.Unix.tm_mon + 1)
                (tm.Unix.tm_year + 1900)
                tm.Unix.tm_hour
                tm.Unix.tm_min  

        let travelTime time v d = time +. (3600. *. d /. v)

        let set_date str date =
            let regex = Str.regexp 
            "\\([0-9][0-9]\\)-\\([0-9][0-9]\\)-\\([0-9][0-9][0-9][0-9]\\)" in
            if ((Str.string_match regex str 0) = false) then raise Invalid_Date_Format;
            let date_setter chaine date = fst (Unix.mktime 
            { 
                Unix.tm_sec = date.Unix.tm_sec;
                Unix.tm_min = date.Unix.tm_min;
                Unix.tm_hour = date.Unix.tm_hour;
                Unix.tm_mday = int_of_string (Str.matched_group 1 str);
                Unix.tm_mon = int_of_string (Str.matched_group 2 str) - 1;
                Unix.tm_year = int_of_string (Str.matched_group 3 str) - 1900;
                Unix.tm_wday = date.Unix.tm_wday;
                Unix.tm_yday = date.Unix.tm_yday;
                Unix.tm_isdst = date.Unix.tm_isdst;
            })
            in date_setter str date

        let set_hour str date =
            let regex = Str.regexp
            "\\([0-9][0-9]\\):\\([0-9][0-9]\\)" in
            if ((Str.string_match regex str 0) = false) then raise Invalid_Date_Format;
            let hour_setter chaine date = fst (Unix.mktime
            {
                Unix.tm_sec = date.Unix.tm_sec;
                Unix.tm_min = int_of_string (Str.matched_group 2 str);
                Unix.tm_hour = int_of_string (Str.matched_group 1 str);
                Unix.tm_mday = date.Unix.tm_mday;
                Unix.tm_mon = date.Unix.tm_mon;
                Unix.tm_year = date.Unix.tm_year;
                Unix.tm_wday = date.Unix.tm_wday;
                Unix.tm_yday = date.Unix.tm_yday;
                Unix.tm_isdst = date.Unix.tm_isdst;
            })
            in hour_setter str date

        let getTime str =
            let rec block i date = function
                | [] -> if (i != 5) then raise Invalid_Date_Format else fst (Unix.mktime date)
                | this::next -> if (i = 2) then 
                                    block (i + 1) (Unix.localtime (set_date this date)) next
                                else if (i = 3) then 
                                    block (i + 1) (Unix.localtime (set_hour this date)) next
                                else
                                    block (i + 1) date next
            in block 0 (Unix.localtime 0.) (Str.split (Str.regexp "[ \t]+") str)
    end
