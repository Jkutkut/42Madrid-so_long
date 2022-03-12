#!/bin/sh

# Colors:
NC='\033[0m' # No Color
RED='\033[1;31m';
YELLOW='\033[1;33m';
GREEN='\033[1;32m';
BLUE='\033[1;34m';

for i in $(ls maps/invalid/*.ber); do
	f=$(basename $i | sed 's/\.ber//' | sed 's/invalid_//');
	echo "$f: \c"

	result=$(timeout -k9 1 ./so_long $i 2>&1)
	isError=$(echo "$result" | grep "Error")
	isTimeout=$(echo $result | cat -e)
	if [ ! "$isError" = "" ]; then
		echo "${GREEN}OK${NC}"
	elif [ ! "$isTimeout" = "" ]; then
		echo "${RED}timeout${NC}"
	else
		echo "${RED}KO${NC}"
		break
	fi
done
