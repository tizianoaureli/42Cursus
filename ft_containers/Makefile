SRCS			= main.cpp
SRCS2			= test.cpp
SRCS3			= testosterone.cpp

OBJ				= $(SRCS:.cpp=.o)
OBJ2			= $(SRCS2:.cpp=.o)
OBJ3			= $(SRCS3:.cpp=.o)


CC				= clang++
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -std=c++98
NAME			= containers
NAME2			= containers2
NAME3			= containers3


%.o:			%.cpp
				$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME) $(NAME2) $(NAME3)

run:
				./containers 
				./containers2
				./containers3

diff:
				diff mySTL.txt originalSTL.txt myTESTosterone.txt

clone:
				git clone  https://github.com/mli42/containers_test.git
				
test:			
				cd containers_test && ./do.sh

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(NAME2):		$(OBJ2)
				$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2)

$(NAME3):		$(OBJ3)
				$(CC) $(CFLAGS) -o $(NAME3) $(OBJ3)

clean:
				$(RM) $(OBJ) $(OBJ2) $(OBJ3) $(OBJ_BONUS)

fclean:			clean
				$(RM) $(NAME) $(NAME2) $(NAME3) $(NAME_BONUS) mySTL.txt originalSTL.txt myTESTosterone.txt

re:				fclean $(NAME) $(NAME2) $(NAME3)

g:				fclean $(OBJS)
				$(CC) -g -o $(NAME) ${SRCS} ${LIBS} 

.PHONY:			all clean fclean re g