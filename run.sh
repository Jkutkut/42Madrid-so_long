#!/bin/bash

runleak() {
	echo "valgrind --leak-check=yes ./$@"
	valgrind \
		--leak-check=yes --track-origins=yes \
		--leak-check=full --show-leak-kinds=all \
		./$@
}

make
clear
runleak so_long maps/map_subject_01.ber
