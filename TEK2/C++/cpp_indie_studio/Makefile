##
## Makefile for hyper_sprint in /home/papadi_a/work/epitech/Tek2/CPP/cpp_indie_studio
##
## Made by alexis papadimitriou
## Login   <papadi_a@epitech.net>
##
## Started on  Sun Jun 18 16:44:09 2017 alexis papadimitriou
## Last update Sun Jun 18 17:35:09 2017 alexis papadimitriou
##

CXX		=	g++

RM		=	rm -f

CXXFLAGS	+=	-std=c++14 -Wall -Wextra -O3 -I./include

LIBS		=	-L./lib/Linux -L./lib/Linux/libopenal -L./lib/Linux/libsndfile \
			-lpthread \
			-lGL \
			-lX11 \
			-lXxf86vm \
			-lIrrlicht \
			-lopenal \
			-lsndfile \
			-lfreetype \
			-lharfbuzz

SRCS		=	$(wildcard srcs/*.cpp) \
			$(wildcard srcs/Font/*.cpp) \
			$(wildcard srcs/Game/*.cpp) \
			$(wildcard srcs/GUI/*.cpp) \
			$(wildcard srcs/Input/*.cpp) \
			$(wildcard srcs/Physic/*.cpp) \
			$(wildcard srcs/Sound/*.cpp) \
			$(wildcard srcs/Utils/*.cpp)

OBJS		=	$(SRCS:.cpp=.o)

NAME		=	hyper_sprint

all		:	$(NAME)


$(NAME)		:	$(OBJS)
			$(CXX) $(OBJS) $(LIBS) -o $(NAME)

install		:
			mkdir ~/.hsprint_root
			mkdir ~/.hsprint_root/bin
			mkdir ~/.hsprint_root/lib
			cp lib/Linux/*.a lib/Linux/*.so lib/Linux/libopenal/* lib/Linux/libsndfile/* ~/.hsprint_root/lib
			cp hyper_sprint ~/.hsprint_root/bin
			cp -rf resources config ~/.hsprint_root
			echo "alias hyper_sprint='cd ~/.hsprint_root/bin;./hyper_sprint;cd -'" >> ~/.bashrc


uninstall	:
			rm -rf ~/.hsprint_root

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
