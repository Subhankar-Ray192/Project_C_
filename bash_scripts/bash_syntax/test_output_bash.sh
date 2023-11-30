#SHELL-OUTPUT

echo -e "HELLO WORLD!"

#SHELL-OUTPUT

printf "HELLO WORLD!\n"


# BASH-OUTPUT

var_1="HELLO WORLD!"

read var_2 <<< $var_1
echo "TEST-1:" $var_2

# BASH-VARIABLE-INFO-OUTPUT

declare -p var_1
