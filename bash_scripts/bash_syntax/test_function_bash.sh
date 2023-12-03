#SHELL-FUNCTIONS

test_function()
{
	echo "TESTING:FUNCTION"
}

test_function_1()
{
	read -p "ENTER NUMBER:" var_1
	echo "TESTING:FUNCTION(PARAMS)-->" $var_1
}

var_2=""

test_function_2()
{
	read -p "ENTER STRING:" var_2
	var_2=$(echo $var_2| cut -d' ' -f1,3)
}


test_function_3()
{
	read -p "ENTER NUMBER:" var_3
	echo $var_3
}

test_function
test_function_1

test_function_2
echo "TESTING:FUNCTION(PARAMS)-->RETURNS>>" $var_2 

return_val=$(test_function_3)
echo "TESTING:FUNCTION(PARAMS)-->RETURNS>>" $return_val
#BASH-FUNCTIONS
