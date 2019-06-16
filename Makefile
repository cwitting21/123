# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/26 23:06:58 by wmaykit           #+#    #+#              #
#    Updated: 2019/06/16 04:17:11 by cwitting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#for del

DEL = Fillit_v2.5

all:
	make -C ./$(DEL) fclean
	git add *
	git commit -m "$(shell echo $(DEL))"
	git push

check:
	git log
