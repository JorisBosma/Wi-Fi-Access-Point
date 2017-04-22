#!/bin/bash
# Get the different strength levels on different positions


# getSignal()
# Returns the signal strength of the connected Wi-Fi
# -100 is the weakest signal and 0 is the strongest signal
getSignal() {
	local STRENGTH=$(iw wlp2s0 station dump | grep 'signal avg:' | awk '{print $3;}')
	echo $STRENGTH
	# return $STRENGTH
}



# writeToFile()
# Writes the first argument and the second argument to numbers.txt
writeToFile() {
	echo $1 $2 >> numbers.txt
}



# resetFile()
# Copies the content of /dev/null into numbers.txt
# Since /dev/null contains nothing, the file will be empty.
resetFile() {
	cp /dev/null numbers.txt
}


# scanAndTurn()
# Gets the signal strength and writes it to numbers.txt
# It executes this x times.
scanAndTurn() {
	for (( c=1; c <=6; c++ ))
	do
		STRENGTH=$(getSignal)
		echo $STRENGTH
		writeToFile $c $STRENGTH
		# Turn the position (C++ program)
		sleep 10
	done
}



# readFileLines()
# Reads all lines in numbers.txt and returns the number that is the closest to 0.
readFileLines() {
	local STRENGTH=-100

	LINES=$(cat numbers.txt)
	for line in $LINES
	do
		typeset -i TEMP_VAR=$line
		if [[ $TEMP_VAR -lt 0 ]] && [[ ! -z $TEMP_VAR ]];
		then
			if [ $TEMP_VAR -gt $STRENGTH ];
			then
				STRENGTH=$TEMP_VAR
			fi
		fi
	done

	echo $STRENGTH
}



# removeNegative()
# Returns the input without the negative sign
# [Parameter] A value which contains a negative sign
removeNegative() {
	if [ $1 -ge 0 ];
	then
		# The given argument does not contain a negative sign.
		echo "[Main] The given argument does not contain a negative sign"
	else
		local ARGUMENT_LENGTH=$(expr length $1)
		local RESPONSE=100

		case $ARGUMENT_LENGTH in
			2 ) RESPONSE=$(echo $1 | cut -c 1-)
			    ;;
			3 ) RESPONSE=$(echo $1 | cut -c 2-)
			    ;;
			4 ) RESPONSE=$(echo $1 | cut -c 3-)
			    ;;
		esac
	fi

	echo $RESPONSE
}


# getIndex()
# Returns the index which contains the closest strength signal to 0.
# [Parameter] A value which is the closest to 0.
getIndex() {
	local INDEX=$(cat numbers.txt | grep $1 | head -n 1 | awk '{print $1;}')
	echo $INDEX

}


# main()
# Main program
main() {
	resetFile
	scanAndTurn

	BEST_STRENGTH_NEGATIVE=$(readFileLines)
	BEST_STRENGTH_POSITIVE=$(removeNegative $BEST_STRENGTH_NEGATIVE)

	NEW_VAR=$(getIndex $BEST_STRENGTH_POSITIVE)
	echo $NEW_VAR
}

main
