if [ -z "$2" ] # check if two args provided 
then
	echo "Two arguments needed"
        exit 
fi

echo "First arg:  $1"
echo "Second arg: $2"

current=($(find . -maxdepth 1 -name "*.$1" -type f -readable -writable))
if [ -z "$current" ]
then 
	echo "no file with extention '.$1' found"
	exit
fi
new=($(find . -maxdepth 1 -name "*.$1" -type f -readable -writable | sed "s/.$1/.$2/"))

for ((i=0; i<${#current[*]}; i++));
do
	mv ${current[i]} ${new[i]}
	echo "file name '${current[i]}' has changed to '${new[i]}'"
done
