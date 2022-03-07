#!/bin/bash

runleak() {
	echo "valgrind --leak-check=yes ./$@"
	valgrind --leak-check=yes ./$@
}

clear
runleak so_long maps/map_subject_01.ber
