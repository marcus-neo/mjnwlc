#!/bin/bash

./prog
RETCODE=$?

if [[ "$RETCODE" == 246 ]] ; then

	echo "Success";
else
	echo "Failure";

fi
