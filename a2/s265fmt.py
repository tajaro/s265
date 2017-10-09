#!/usr/bin/python3

import argparse
import sys

def update_options(line, fmt, pgwdth, mrgn):
	if line.startswith("?pgwdth"):	
		fmt = 'on'
		li = line.split(' ')
		pgwdth = li[1]
	if line.startswith("?mrgn"):
		li = line.split(' ')
		mrgn = li[1]
	if line.startswith("?fmt"):
		li = line.split(' ')
		if li[1] is 'on':
			fmt = 'on'
		elif li[1] is 'off':
			fmt = 'off'

def main():
	parser = argparse.ArgumentParser()
	parser.add_argument('filename', nargs='?', help='file to be processed')

	args = parser.parse_args()

	if not(args.filename):
		print('No file specified')
		sys.exit(1)

	fp = open(file=args.filename, mode="r")
	
	contents = fp.readlines()

	fmt = 'off'
	pgwdth = 0
	mrgn = 0

	for line in contents:
		if fmt is 'off':
			if line.startswith('?'):
				update_options(line, fmt, pgwdth, mrgn)
			else:
				print(line, end = "")
		elif fmt is 'on':
			if line.startswith('?'):
				update_options(line, fmt, pgwdth, mrgn)
			else:
				pass
	
	fp.close()

if __name__ == "__main__":
	main()
