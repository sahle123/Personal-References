# lsof_repeat.sh
#
# 	Runs "lsof -i 4tcp" every 5 seconds on terminal
# 
#	LU: 01/23/16
#
# N.B. need to change permissions so the script can execute. chmod u+x <scriptname>

while true
do 
	DELAY=5
	lsof -i 4tcp
	echo "Delaying for $DELAY seconds. Use ctrl-C to quit."
	sleep $DELAY # Delay for 5 seconds
done