

	#SHELL-COMMAND-LINE-INPUT

	var_1=$1
	echo "TEST-1:" $var_1

	#SHELL-READ-INPUT:

	echo -n "NON-PROMTED:"
	read var_2
	echo "TEST-2.0:" $var_2

	read -p "PROMPTED:" var_3
	echo "TEST-2.1:" $var_3


if [ "$BASH" ]; then

	#BASH-SELECT-INPUT

	select option in "1" "2" "3"
	do
		case $option in
			"1") echo "TEST-3.1";;
			"2") echo "TEST-3.2";;
			"3") echo "TEST-3.3";;
			*) echo "TEST-3.INV";;
		esac
		break
	done
fi


