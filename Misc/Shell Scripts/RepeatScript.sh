# RepeatScript.sh
#
# Test script for running nmap multiple times.
# 7/28/15
#
# N.B. need to change permissions so the script can execute. chmod u+x <scriptname>

for i in 1 2 3 4 5
do 
	DELAY=5

	nmap -sP 192.168.1.*

	echo "Delaying for $DELAY seconds"
	sleep $DELAY # Delay for 5 seconds
done