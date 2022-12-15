# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 15:09:02 by rchiewli          #+#    #+#              #
#    Updated: 2022/12/15 21:19:03 by rchiewli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
BNAME	= xx
CFLAGS	= -pthread -Wall -Wextra -Werror
CC		= gcc
FILES	= action.c\
			ini.c\
			routine.c\
			util1.c

MFILES	= main.c

BFILES	= xxx.c

OBJ	= $(FILES:%.c=%.o) $(MFILES:%.c=%.o)

BOBJ = $(FILES:%.c=%.o) $(BFILES:%.c=%.o)

all: $(NAME)

chkr: $(BNAME)

# ft_pf:
# 	@make -C ft_pf/

$(NAME): $(OBJ) philo.h
	@say -v kyoko こんにちは マクドナルド ミルク バス ビール スターバックス
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# $(BNAME): $(BOBJ)
# 	# @say -v kyoko こんにちは マクドナルド ミルク バス ビール スターバックス
# 	@make -C dt_dpf/
# 	@make -C libftfinal/
# 	$(CC) $(CFLAGS) $(BOBJ) dt_dpf/libftprintf.a libftfinal/libft.a -o $(BNAME)

# debug:
# 	@make -C dt_dpf/
# 	@make -C libftfinal/
# 	$(CC) -g $(CFLAGS) $(FILES) dt_dpf/libftprintf.a libftfinal/libft.a -o debug


love:
	@printf "No one to \e[1;31m make love \e[0m with you."

cheer:
	@say -v kanya หนึ่ง สอง /
	@say -v kanya หนึ่งสองสาม /
	@say -v kanya หนึ่งสอง /
	@say -v kanya หนึ่งสอง /
	@say -v kanya หนึ่ง /

badvoice:
	@say -v kanya ยายมอยเลี้ยงหมี และยายมีเลี้ยงหอย/
	@say -v kanya ส่วนนางลีขายหอย และนางมอยขายหมี/
	@say -v kanya ยานัตถุ์ของหมอมีแก้ฝีแก้หิด แต่การแพทย์ของหมอชิดแก้หิดแก้ฝี/
	@say -v kanya เอาหูหมีมาใส่ในหูหมู หนูเอาหูหมูมาใส่หูหมี หูหมู หูหนี เอาหูหมีมาใส่หูหมู/
	@say -v kanya แต่ถ้าเธอเอาไปผัดเห็ดมันจะเป็นเห็ดหูหนู/

norm:
	@say -v kanya เช็คนอม หน่อยนะค่ะ /
	norminette -R checkforbiddensourceheader $(FILES)
	norminette -R checkdefine philo.h

clean:
	@say -v kanya อาบฟอกตัว ขัดทั่วกาย งามพริ้งพรายง่ายดายเหลือใจ /
	@rm -f $(OBJ)
	@rm -rf debug

fclean: clean
	@rm -f  $(NAME)

re: fclean all

re2: clean debug

.PHONY: clean fclean all re norm love cheer badvoice chkr
