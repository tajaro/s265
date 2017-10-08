#!/usr/bin/python

import argparse
import sys

def main():
	parser = argparse.ArgumentParser()
	parser.add_argument('filename', nargs='?', help='file to be processed')

	args = parser.parse_args()

	if not(args.filename):
		print('No file specified')
		sys.exit(1)

	fp = open(name=args.filename, mode="r")
	
	contents = fp.readlines()

	for line in contents:
		print(line, end = "")
	
	fp.close()

if __name__ == "__main__":
	main()
