# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/26 23:06:58 by wmaykit           #+#    #+#              #
#    Updated: 2019/06/09 23:54:10 by cwitting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#for del

DEL = Fillit_v2.4

all:
	make -C ./$(DEL) fclean
	rm -rf ./team/$(DEL)
	cp -r ./$(DEL) .
	git add *
	git commit -m "$(shell echo $(DEL))"
	git push

check:
	git log
