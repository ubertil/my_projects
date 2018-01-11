NAME	=	trainmanager


ML	=	time.ml \
		utils.ml \
		link.ml \
		train.ml \
		trip.ml \
		dijkstra.ml \
		trainmanager.ml \
		main.ml \


MLI	=	time.mli \
		utils.mli \
		link.mli \
		train.mli \
		trip.mli \
		dijkstra.mli \
		trainmanager.mli \


CMI = $(MLI:.mli=.cmi)
CMO = $(ML:.ml=.cmo)
CMX = $(ML:.ml=.cmx)

LIBS = str.cma unix.cma

OCAMLDPE = ocamldep
CAMLFLAGS = #-w Aelz -warn-error A
OCAMLC = ocamlc $(CAMLFLAGS)
OCAMLOPT = ocamlopt $(CAMLFLAGS)

all:		.depend $(CMI) $(NAME)

byte:		.depend $(CMI) $(NAME).byte


$(NAME):	$(CMX)
		@$(OCAMLOPT) -o $@ $(LIBS:.cma=.cmxa) $(CMX)
		@echo "[OK] $(NAME) linked"

$(NAME).byte:	$(CMO)
		@$(OCAMLC) -o $@ $(LIBS) $(CMO)
		@echo "[OK] $(NAME).byte linked"

%.cmx:		%.ml
		@$(OCAMLOPT) -c $<
		@echo "[OK] [$<] builded"

%.cmo:		%.ml
		@$(OCAMLC) -c $<
		@echo "[OK] [$<] builded"

%.cmi:		%.mli
		@$(OCAMLC) -c $<
		@echo "[OK] [$<] builded"

documentation:  $(CMI)
		@$(OCAMLDOC) $(MLI)
		@echo "[OK] Documentation"


re:		fclean all


clean:
		@/bin/rm -f *.cm* *.o .depend *~
		@echo "[OK] Clean"


fclean:		clean
		@/bin/rm -f $(NAME) $(NAME).byte
		@echo "[OK] Fclean"


.depend:
		@/bin/rm -f .depend
		@$(OCAMLDPE) $(MLI) $(ML) > .depend
		@echo "[OK] Dependencies"
