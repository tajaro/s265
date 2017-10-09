#!/usr/bin/python3

import argparse
import sys

fmt = 0
pgwdth = 0
mrgn = 0

def update_options(line):
	global fmt, pgwdth, mrgn
	if line.startswith("?pgwdth"):	
		fmt = 1
		li = line.split(' ')
		pgwdth = int(li[1])
	if line.startswith("?mrgn"):
		li = line.split(' ')
		mrgn = int(li[1])
	if line.startswith("?fmt"):
		li = line.split(' ')
		if li[1].startswith('on'):
			fmt = 1
		elif li[1].startswith('off'):
			fmt = 0

def main():
	parser = argparse.ArgumentParser()
	parser.add_argument('filename', nargs='?', help='file to be processed')

	args = parser.parse_args()

	if not(args.filename):
		print('No file specified')
		sys.exit(1)

	fp = open(file=args.filename, mode="r")
	
	num_chars = 0
	fmt_line = ''
	
	contents = fp.readlines()
	for line in contents:
		line = line.rstrip()
		if fmt == 0:
			if line.startswith('?'):
				update_options(line)
			else:
				print(line)
		elif fmt == 1:
			if line.startswith('?'):
				update_options(line)
			elif not line:
				if num_chars != 0:
					print(fmt_line)
					fmt_line = ''
					num_chars = 0	
				print('')
			else:
				words = line.split()
				for word in words:
					if (num_chars + len(word) + 1) > pgwdth:
						print(fmt_line)
						fmt_line = ''
						num_chars = 0
					if num_chars == 0:
						fmt_line = fmt_line.rjust(mrgn)
						fmt_line += word
						num_chars += mrgn
					else:
						fmt_line += (' ' + word)
						num_chars += 1
					num_chars += len(word)
	if fmt == 1:
		print(fmt_line)
	fp.close()

if __name__ == "__main__":
	main()
