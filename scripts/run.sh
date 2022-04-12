#!/bin/bash

runleak() {
	echo "valgrind --leak-check=yes ./$@"
	valgrind \
		--leak-check=yes --track-origins=yes \
		--show-leak-kinds=all \
		./$@
	# valgrind \
	# 	--leak-check=yes --track-origins=yes \
	# 	--leak-check=full --show-leak-kinds=all \
	# 	./$@
}

make
clear
if [ "$1" = "n" ]; then
	../so_long maps/map_subject_02.ber ||
	echo "Error"
else
	runleak so_long maps/map_subject_01.ber
fi
