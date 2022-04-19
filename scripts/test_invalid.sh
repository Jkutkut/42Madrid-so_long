#!/bin/sh

# Colors:
NC='\033[0m' # No Color
RED='\033[1;31m';
YELLOW='\033[1;33m';
GREEN='\033[1;32m';
BLUE='\033[1;34m';

main() {
	# Check timeout command exist
	if [ ! -x "$(command -v timeout)" ]; then
		echo "timeout command not installed/not found."
		echo "You can install it with:"
		echo "    brew install coreutils"
		return
	fi

	if [ "$1" = "checkLeaks" ]; then
		checkLeaks=true
		shift
	else
		checkLeaks=false
	fi

	if [ "$1" = "bonus" ]; then
		echo "Test invalid Bonus"
		make bonus
	else
		echo "Test invalid"
		make
	fi &&

	for i in $(ls maps/invalid/*.ber); do
		f=$(basename $i | sed 's/\.ber//' | sed 's/invalid_//');
		echo "$f: \c"

		result=$(timeout -k9 1 ./so_long $i 2>&1)
		isError=$(echo "$result" | grep "Error")
		# isTimeout=$(echo $result | cat -e)
		isTimeout=$(echo $result)
		if [ ! "$isError" = "" ]; then
			echo "${GREEN}OK${NC} \c"
		# elif [ ! "$isTimeout" = "" ]; then
		# 	echo "${RED}timeout${NC}"
		else
			echo "${RED}KO${NC} \c"
			break
		fi
		if $checkLeaks; then
			isLeakFree=$(echo "$result" | grep "0 leaks for 0 total")
			if [ "$isLeakFree" = "" ]; then
				echo "${RED}[LEAKS KO]${NC}"
				echo "$result"
			else
				echo "${GREEN}[LEAKS OK]${NC}"
			fi
		else
			echo
		fi
	done ||
	{
		echo "${RED}Error:${NC}"
		echo "    Not able to execute the test"
	}
}

main $@