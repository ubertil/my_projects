(*
* @Author: uberti_l
* @Date:   2017-05-16 14:06:27
* @Last Modified by:   uberti_l
* @Last Modified time: 2017-05-16 14:45:09
*)

open Train
open Trip
open Link
open Time

exception Found of int
exception No_way
type cost = Nan | Cost of float
type adj_mat = cost array array
type 'a graph = { mutable ind : int; size : int; nodes : 'a array; m : adj_mat }
type comp_state = { paths : int array; already_treated : bool array; distances : cost array; source : int; nn : int}

module type DIJKSTRA =
    sig
        val printTrips : Trip.trip list -> unit
        val init_graph : unit -> string graph
    end

module Dijkstra : DIJKSTRA =
    struct
        let create_graph n s = 
            { ind = 0; size = s; nodes = Array.make s n; m = Array.make_matrix s s Nan }

        let belongs_to n g =
            let rec aux i =
                (i < g.size) && ((g.nodes.(i) = n) || (aux (i + 1)))
            in aux 0

        let index n g =
            let rec aux i =
                if i >= g.size then raise Not_found
                else if g.nodes.(i) = n then i else aux (i + 1)
            in aux 0

        let add_node n g =
            if g.ind = g.size then failwith "Graph is full"
            else if belongs_to n g then failwith "Node alreay exists"
            else (g.nodes.(g.ind) <- n; g.ind <- g.ind + 1)

        let add_edge e1 e2 c g =
            try
                let x = index e1 g and y = index e2 g in g.m.(x).(y) <- Cost c
            with Not_found -> failwith "Node does not exist"

        let init_graph () =
            let g = create_graph "nothing" 48 in
                List.iter (fun x -> add_node x g) ["Paris"; "Lyon"; "Dijon"; "Lille"; "Nancy"; "Brest";
                                                    "Rennes"; "London"; "Liege"; "Cologne"; "Le Mans";
                                                    "Essen"; "Marseille"; "Brussels"; "Le Havre"; "Nantes";
                                                    "Bordeaux"; "Strasbourg"; "Toulouse"; "Amsterdam"; "Montpellier"];
                List.iter (fun (a,b ,c) -> add_edge a b c g)
                ["Paris", "Lyon", 427.;
                "Lyon", "Paris", 427.;
                "Dijon", "Lyon", 192.;
                "Lyon", "Dijon", 192.;
                "Paris", "Lille", 225.;
                "Lille", "Paris", 225.;
                "Paris", "Nancy", 327.;
                "Nancy", "Paris", 327.;
                "Dijon", "Nancy", 226.;
                "Nancy", "Dijon", 226.;
                "Brest", "Rennes", 248.;
                "Rennes", "Brest", 248.;
                "Lille", "London", 269.;
                "London", "Lille", 269.;
                "Liege", "Cologne", 118.;
                "Cologne", "Liege", 118.;
                "Le Mans", "Paris", 201.;
                "Paris", "Le Mans", 201.;
                "Cologne", "Essen", 81.;
                "Essen", "Cologne", 81.;
                "Lyon", "Marseille", 325.;
                "Marseille", "Lyon", 325.;
                "Brussels", "Liege", 104.;
                "Liege", "Brussels", 104.;
                "Paris", "Le Havre", 230.;
                "Le Havre", "Paris", 230.;
                "Rennes", "Le Mans", 163.;
                "Le Mans", "Rennes", 163.;
                "Le Mans", "Nantes", 183.;
                "Nantes", "Le Mans", 183.;
                "Paris", "Bordeaux", 568.;
                "Bordeaux", "Paris", 568.;
                "Lille", "Brussels", 106.;
                "Brussels", "Lille", 106.;
                "Nancy", "Strasbourg", 149.;
                "Strasbourg", "Nancy", 149.;
                "Paris", "Strasbourg", 449.;
                "Strasbourg", "Paris", 449.;
                "Dijon", "Strasbourg", 309.;
                "Strasbourg", "Dijon", 309.;
                "Toulouse", "Bordeaux", 256.;
                "Bordeaux", "Toulouse", 256.;
                "Brussels", "Amsterdam", 211.;
                "Amsterdam", "Brussels", 211.;
                "Montpellier", "Toulouse", 248.;
                "Toulouse", "Montpellier", 248.;
                "Marseille", "Montpellier", 176.;
                "Montpellier", "Marseille", 176.];
            for i = 0 to g.ind - 1 do g.m.(i).(i) <- Cost 0.0 done;
            g

        let create_state () = 
            { paths = [||]; already_treated = [||]; distances = [||]; nn = 0; source = 0}

        let a_cost c = match c with 
            | Nan -> false 
            | _ -> true

        let float_of_cost c = match c with
            | Nan -> failwith "float_of_cost"
            | Cost x -> x

        let add_cost  c1 c2 = match (c1,c2) with 
            | Cost x, Cost y -> Cost (x +. y)
            | Nan, Cost y -> c2
            | Cost x, Nan -> c1 
            | Nan, Nan ->  c1

        let less_cost  c1 c2 = match (c1,c2) with 
            | Cost x, Cost y -> x < y
            | Cost x, Nan -> true
            | _, _ ->  false

        let first_not_treated cs =
            try
                for i=0 to cs.nn-1 do
                if not cs.already_treated.(i) then raise (Found i)
                done;
                raise Not_found;
            with Found i -> i

        let least_not_treated p cs =
            let ni = ref p
            and nd = ref cs.distances.(p) in
                for i=p+1 to cs.nn-1 do
                if not cs.already_treated.(i) then
                if less_cost cs.distances.(i)  !nd then
                ( nd := cs.distances.(i);
                ni := i )
                done;
            !ni,!nd

        let one_round cs g =
            let p = first_not_treated cs in
                let np, nc = least_not_treated p cs in
                    if not (a_cost nc) then raise No_way
                    else
                    begin
                        cs.already_treated.(np) <- true;
                        for i = 0 to cs.nn -1 do
                        if not cs.already_treated.(i) then
                        if a_cost g.m.(np).(i) then
                        let ic = add_cost cs.distances.(np) g.m.(np).(i) in
                            if less_cost ic cs.distances.(i)   then (
                            cs.paths.(i) <- np;
                            cs.distances.(i) <- ic
                        )
                        done;
                        cs
                    end

        let dij s g = 
            if belongs_to s g then 
            begin
                let i = index s g in 
                    let cs = { paths = Array.make g.ind (-1) ;
                        already_treated = Array.make g.ind false;
                        distances = Array.make g.ind Nan;
                        nn = g.ind;
                        source = i}  in
                        cs.already_treated.(i) <- true; 
                for j=0 to g.ind-1 do 
                    let c = g.m.(i).(j) in 
                    cs.distances.(j) <- c;
                    if a_cost c then cs.paths.(j) <- i 
                done;
            try
                for k = 0 to cs.nn-2 do 
                ignore(one_round cs g);
                ignore(k);
            done;
            cs
            with No_way -> cs
            end
   else failwith "Dijkstra: Unknown node"

        let find_path_to f (g, st) dest train date len =
            if belongs_to dest g then
            let d = index dest g in
                let rec aux is date =
                    if is != st.source then
                        let old = st.paths.(is) in 
                        aux old (Time.travelTime date (float_of_int (Train.getSpeed train)) (float_of_cost st.distances.(d)));
                    in
                        Printf.printf "%s " dest;
                        if (len != 1) then
                            Printf.printf "%s %s\n" (Time.promptTime (Time.travelTime date (float_of_int (Train.getSpeed train)) (float_of_cost st.distances.(d))))
                                                  (Time.promptTime ((Time.travelTime date (float_of_int (Train.getSpeed train)) (float_of_cost st.distances.(d))) +. (Time.travelTime 0. 60. 10.)))
                        else
                            Printf.printf "%s (,)\n" (Time.promptTime (Time.travelTime date (float_of_int (Train.getSpeed train)) (float_of_cost st.distances.(d))));
                        aux d ((Time.travelTime date (float_of_int (Train.getSpeed train)) (float_of_cost st.distances.(d))) +. (Time.travelTime 0. 60. 10.))

        let g = init_graph ()
        
        let rec all_way g train date = function
            | [] -> ()
            | this::next -> if (next != []) then
                            find_path_to (fun x y -> Printf.printf "%s" y) (g, (dij this g)) (List.hd next) train date (List.length next);
                            all_way g  train date next

        let rec printTrips = function
            | [] -> ()
            | this::next -> Printf.printf "%s %d\n" (Train.getName (Trip.getTrain this)) (Trip.getId this);
                            Printf.printf "%s (,) %s\n" (List.hd (Trip.getDestination this)) (Time.promptTime (Trip.getDate this));
                            all_way g (Trip.getTrain this) (Trip.getDate this) (Trip.getDestination this); printTrips next
    end
