#SHELL-STRING-FUNCTION

my_string="Hello World!"

echo
echo "INPUT-STRING:" $my_string

echo
#DELIMITER-ROW-FIELD-EXTRACTION
substring=$(echo $my_string| cut -d' ' -f2)
echo "R-FIELD:" $substring

#DELIMETER-COLUMN-FIELD-EXTRACTION
substring=$(echo $my_string| cut -c2-7)
echo "C-FIELD(2,7):" $substring

#DELIMETER-COLUMN-SPECIFIC-CHARACTERS-EXTRACTION
substring=$(echo $my_string| cut -c3,5,8)
echo "C-FIELD(3,5,8):" $substring

my_string_3="apple:orange:mango"

#DELIMITER-ROW-SPECIFIC-CHARACTER-EXTRACTION
substring=$(echo $my_string_3| cut -d':' -f1,3)
echo "R-FIELD(1,3):" $substring

echo
#my_string_1="apple,orange,banana"
#awk -F',' '{ for(i=1;i<=NF;i++) print $i }' <<<$my_string_1

if echo "$my_string" | grep -q "Hello"; then
	echo "String contains Hello"
fi

echo
uppercase=$(echo $my_string | tr '[:lower:]' '[:upper:]')
lowercase=$(echo $my_string | tr '[:upper:]' '[:lower:]')

echo "Uppercase:" $uppercase
echo "Lowercase:" $lowercase

#BASH-STRING-FUNCTION


