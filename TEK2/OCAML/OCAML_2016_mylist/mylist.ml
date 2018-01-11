(*---------------OCAML_2016_mylist---------------*)
(*-------by louis-emile.uberti-ares@epitech.eu---*)
(*---------------------2017----------------------*)

type 'a my_list =
	| Item of ('a * 'a  my_list)
	| Empty

let cons to_add list1 = Item(to_add, list1)
;;

let rec length = function
	| Empty -> 0
	| Item(a, b) -> length b + 1
;;

let hd = function
	| Empty -> raise(Failure "hd")
	| Item(a, b) -> a
;;

let tl = function
	| Empty -> raise(Failure "tl")
	| Item(a, b) -> b
;;

let rec nth list n =
	if (n < 0) then raise(Invalid_argument "List.nth")
	else
	match list with
		| Empty -> raise(Failure "nth")
		| Item(a, b) -> if (n = 0) then a else nth b (n - 1)
;;

let rev list =
	let rec revlist old_next = function
		| Empty -> old_next
		| Item(a, b) -> revlist(Item(a, old_next)) b
	in revlist Empty list
;;

let append list1 list2 =
	let rec append_to_list next = function
		| Empty -> next
		| Item(a, b) -> append_to_list (Item(a, next)) b
	in append_to_list list2 (rev list1)
;;

let rec rev_append list1 list2 = match list1 with
	| Empty -> list2
	| Item(a, b) -> rev_append b (Item(a, list2))
;;

let rec concat = function
	| Empty -> Empty
	| Item(a, b) -> append a (concat b)
;;

let flatten = concat
;;

let rec iter func = function
	| Empty -> ()
	| Item(a, b) -> func a ; iter func b
;;

let rec map func = function
	| Empty -> Empty
	| Item(a, b) -> let new_value = func a in Item(new_value, map func b)
;;

let rec fold_left op value = function
	| Empty -> value
	| Item(a, b) -> fold_left op (op value a) b
;;

let rec fold_right op value = function
	| Empty -> value
	| Item(a, b) -> op a (fold_right op value b)
;;

let rec for_all func = function
	| Empty -> true
	| Item(a, b) -> func a && for_all func b
;;

let rec exists func = function
	| Empty -> false
	| Item(a, b) -> func a || exists func b
;;

let rec mem to_compare = function
	| Empty -> false
	| Item(a, b) -> a = to_compare || mem to_compare b
;;

let rec memq to_compare = function
	| Empty -> false
	| Item(a, b) -> a == to_compare || memq to_compare b
;;

let filter func list1 =
	let rec filter_list list1 = function
		| Empty -> rev list1
		| Item(a, b) -> if func a then filter_list (Item(a, list1)) b else filter_list list1 b
	in filter_list Empty list1
;;

let find_all = filter
;;

let rec split = function
	| Empty -> (Empty, Empty)
	| Item((a, b), c) -> let (start_new, end_new) = split c in (Item(a, start_new), Item(b, end_new))
;;

let rec combine list1 list2 = match (list1, list2) with
	| (Empty, Empty) -> Empty
	| (Item(a, start_new), Item(b, end_new)) -> Item((a, b), combine start_new end_new)
	| _ -> raise(Invalid_argument "List.combine")
;;

let partition func list1 =
	let rec partition_list is_true is_false = function
		| Empty -> (rev is_true, rev is_false)
		| Item(a, b) -> if func a then partition_list (Item(a, is_true)) is_false b else partition_list is_true (Item(a, is_false)) b
	in partition_list Empty Empty list1
;;
