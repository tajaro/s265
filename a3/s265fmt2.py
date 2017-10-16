#!/usr/bin/python

import sys
import argparse
from formatting import seng265_formatter

def main():
	parser = argparse.ArgumentParser()
	parser.add_argument('filename', nargs='?', help='file to be processeed')

	args = parser.parse_args()

	if not(args.filename):
		print('No file specified')
		sys.exit(1)

	myobj = seng265_formatter(filename=args.filename)
	myobj.format_lines()
	
	print(myobj.getlines())

if __name__ == "__main__":
	main()
