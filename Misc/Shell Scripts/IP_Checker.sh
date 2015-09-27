# IP_Checker.sh
#
# Runs netstat -anp tcp multiple times every 5 seconds

for i in {0..1000}
do 
	DELAY=5

    # Print date
    DATE=$(date)
    echo $DATE

	# Command run
	netstat -anp tcp

	echo "Delaying for $DELAY seconds"
	sleep $DELAY # Delay for 5 seconds
	echo "====================================================================="
done