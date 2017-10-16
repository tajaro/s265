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
	elif line.startswith("?mrgn"):
		li = line.split(' ')
		if li[1].startswith(('+', '-')):
			mrgn += int(li[1])
		else:
			mrgn = int(li[1])
		if mrgn < 0:
			mrgn = 0
		elif mrgn > (pgwdth - 20):
			mrgn = pgwdth - 20
	elif line.startswith("?fmt"):
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
	
	fmt_line = ''
	
	contents = fp.readlines()
	for line in contents:
		line = line.rstrip()
		if line.startswith('?'):
			update_options(line)
			continue
		if fmt == 0:
			print(line)
		else:
			if not line:
				if fmt_line:
					print(fmt_line)
					fmt_line = ''
					num_chars = 0	
				print('')
			else:
				words = line.split()
				for word in words:
					if (len(fmt_line) + len(word) + 1) > pgwdth:
						print(fmt_line)
						fmt_line = ''
					elif fmt_line:
						fmt_line += ' '
					if not fmt_line:
						fmt_line = fmt_line.rjust(mrgn)
					fmt_line += word
	if fmt == 1 and fmt_line:
		print(fmt_line)
	fp.close()

if __name__ == "__main__":
	main()
