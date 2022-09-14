#
#

NOM=libmlx.a
SRC= mlx_shaders mlx_new_window mlx_init_loop mlx_new_image mlx_xpm mlx_int_str_to_wordtab
SRC+= mlx_png mlx_mouse
OBJ=$(addsuffix .o, $(SRC))
CFLAGS+=-O2 -w

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

%o:	%c
	@$(CC) $(CFLAGS) -c $^ -o $@

all: $(NOM)

$(NOM):	$(OBJ)
	ar -rcs $(NOM) $(OBJ)

clean:
	rm -f $(OBJ) *~
	rm -f mlx_app

fclean:	clean
		rm -f $(NOM)

re: clean all
