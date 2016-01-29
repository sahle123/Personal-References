# nmap_nomad.py
#
#	Des:	Port scanner that uses the Nmap module for 
#			the actual port scanning.
#	Status: Functional - WIP
#
#	Ref: Violent Python, TJ O'Conner (Modified)
#
#	LU: 12/23/15

import nmap
import argparse


def nmapScan(tgtHost, tgtPort):

	nmObj = nmap.PortScanner()
	nmObj.scan(tgtHost, tgtPort)

	state = nmObj[tgtHost]['tcp'][int(tgtPort)]['state']

	print "[*] " +tgtHost+ " tcp/" +tgtPort+ " "+state

def parseInput():

	parser = argparse.ArgumentParser(description="Modified port scanner" +\
		" that utilizes nmap. Still WIP. Please use IP addresses ONLY!!!")

	parser.add_argument("-H", dest="tgtHost", type=str, \
		help="specifiy target host IP address")

	parser.add_argument("-p", dest="tgtPort", type=str, \
		help="specify target port[s] separated by commas")

	leOptions = parser.parse_args()

	if(leOptions.tgtHost == None) | (leOptions.tgtPort == None):
		print parser.print_help()
		exit(0)

	else:
		print "[*] DEBUG: parserInputs() ran successfully"
		tgtPorts = str(leOptions.tgtPort).split(', ')

		for ports in tgtPorts:
			nmapScan(leOptions.tgtHost, ports)

def main():
	parseInput()
	return

if __name__ == '__main__':
	main()