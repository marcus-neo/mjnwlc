#!/bin/bash

for i in bin/testbench/*.bin ; do
	if [ -f "$i" ] ; then

		cp $i bin/test/temp.bin;

		filename=$(basename $i .bin);
		if [ -f "bin/testanswer/$filename.txt" ] ; then
			dos2unix bin/testanswer/$filename.txt;
			output=$(<bin/testanswer/$filename.txt);
			echo $filename;
			echo $output;
		else
			echo "bin/testanswer/$filename.txt does not exist!"
			rm bin/test/temp.bin;
			exit 0
		fi

		if [ -z "$1" ] ; then
		    ./prog
		else
	    		if [ -f "$1" ] ; then
				./$1
		    	else
				echo "The file $1 does not exist!"
				exit 0
	    		fi
		fi
		RETCODE=$?
		echo $RETCODE

		if [[ "$RETCODE" == "$output" ]] ; then

			echo "Success";
		else
			echo "Failure";

		fi

		rm bin/test/temp.bin;
		echo $filename;


	else
		echo "bin/testbench contains no binary files!"
		exit 0

	fi
done

