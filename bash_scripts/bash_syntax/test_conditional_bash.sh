#SHELL-CONDITIONAL

read -p "Enter Number:" var_1
read -p "Enter Character:" var_2
read -p "Enter Character:" var_3

if [ $var_1 -eq 1 ]; then
	if [ $var_2 = "H" ]; then
		echo "H-->Hello"
	else
		echo "H-->xxxx"
	fi
elif [ $var_1 -gt 1 ]; then
	if [ $var_2 != "P" ]; then
		echo "P-->xxxx"
	else
		echo "P-->Pray"
	fi
elif [ $var_1 -lt 1 ]; then
	if [ $var_2 != "Q" ] && [ $var_3 = "S" ]; then
		echo "Q-->Quick"
	else
		if [ $var_2 = "Q" ] || [ $var_3 != "S" ]; then
			echo "S-->Saved"
		else
			echo "S-->xxxx"
		fi
	fi
else
	if [ $var_2 -ge 5 ]; then
		echo $var_2+3
	elif [ $var_2 -le 5 ]; then
		echo $var_2-3
	else
		echo $var_2
	fi
fi

#BASH-CONDITIONAL

if [[ $var_1 -eq 1 && $var_2 = "K" ]]; then
	echo "K-->Kite"
elif [[ $var_1 -ne 1 || $var_2 != "J" ]]; then
	echo "O-->Ok"
else
	echo "None"
fi

#BASH-CONDITIONAL-ADDITIONAL-FLAGS

read -p "Enter Number:" var_4
read -p "Enter File Path:" var_5

if [[ -v var_4 ]]; then
	echo "Variable:SET"
fi

if [[ -e $var_5 ]]; then
	echo "File-Path:Exist"
else
	echo "None"
fi


#SHELL-CONDITIONAL-ADDITIONAL-FLAGS

read -p "Enter Number" var_6

if [ -n var_6 ]; then
	echo "Variable:EMPTY"
else
	echo "None"
fi

#BASH-REGEX-STRINGS

read -p "Enter String:" var_7

if [[ $var_7 =~ ^H.*$ ]]; then
	echo "String starts with H"
else
	echo "None"
fi
