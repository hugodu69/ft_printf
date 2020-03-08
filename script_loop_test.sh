
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# script to launch a lot of time a program to see if it always output the same result #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

let i=0

# launch the output, write it into the file temoin.txt, and echo the content
./a.out test > temoin.txt
echo '\033[32mfile temoin.txt contain this :\033[0m'
cat temoin.txt

# ask if the output was a good one, if so continue the script, otherwise retry
question=
while [ -z $question ]
do
	echo '\033[32mis the output correct ? ok to continue ? n/y\033[0m'
	read question
	if [[ $question == 'n' ]]
	then
		./a.out test > temoin.txt
		echo '\033[32mfile temoin.txt contain now this :\033[0m'
		cat temoin.txt
	else
		break
	fi
	question=
done

# launch the program in a loop and compare the output to the first one
./a.out test > exemple.txt
while diff temoin.txt exemple.txt
do
	let i++
	echo '\033[1;34m'$i'\033[0m'
	./a.out test > exemple.txt
done

# clean the files created by the script
rm temoin.txt exemple.txt
