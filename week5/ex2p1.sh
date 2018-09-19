while :
do
	echo $(( $(tail -n 1 file) + 1)) >> file 
done
