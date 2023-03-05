NAMESERVER = server
NAMECLIENT = client
LIB = ft_printf/libftprintf.a
SRCSERVER = server.c
SRCCLIENT = client.c \
			utils.c
FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)

all: $(LIB) $(NAMESERVER) $(NAMECLIENT)

$(LIB):
	make -C ./ft_printf

$(NAMESERVER) : $(OBJSERVER)
	$(CC) $(OBJSERVER) -o $(NAMESERVER) $(LIB)

$(NAMECLIENT) : $(OBJCLIENT)
	$(CC) $(OBJCLIENT) -o $(NAMECLIENT) $(LIB)

clean:
	rm -rf $(OBJSERVER) $(OBJCLIENT)
	rm -rf ./ft_printf/ft_printf_format.o
	rm -rf ./ft_printf/ft_printf.o



fclean: clean
	rm -rf $(NAMESERVER) $(NAMECLIENT)
	rm -rf ./ft_printf/libftprintf.a

re:fclean all

.PHONY : re fclean clean all