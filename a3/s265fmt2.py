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

	#seng265_formatter(
	print ("Hello World")

if __name__ == "__main__":
	main()
