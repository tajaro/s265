#!/usr/bin/python

class seng265_formatter:

	def __init__(self, filename="", lines=[]):
		
		self.opt = {
			'fmt' : False,
			'pgwdth' : 0,
			'mrgn' : 0
		}

		if filename:
			inputfile = open(filename, 'r')
			self.lines = inputfile.readlines()
		else:
			self.lines = lines

		self.output = []
		self.format_lines()

	def update_options(self, line):
		"""
		Update self.opt with newfound formatting option.
		"""
		if line.startswith("?pgwdth"):	
			self.opt['fmt'] = 1
			li = line.split(' ')
			self.opt['pgwdth'] = int(li[1])
		elif line.startswith("?mrgn"):
			li = line.split(' ')
			if li[1].startswith(('+', '-')):
				self.opt['mrgn'] += int(li[1])
			else:
				self.opt['mrgn'] = int(li[1])
			if self.opt['mrgn'] < 0:
				self.opt['mrgn'] = 0
			elif self.opt['mrgn'] > (self.opt['pgwdth']  - 20):
				self.opt['mrgn'] = self.opt['pgwdth'] - 20
		elif line.startswith("?fmt"):
			li = line.split(' ')
			if li[1].startswith('on'):
				self.opt['fmt'] = 1
			elif li[1].startswith('off'):
				self.opt['fmt'] = 0

	def format_lines(self):
		"""
		Format input lines.
		"""
		fmt_line = ''
	
		for line in self.lines:

			line = line.rstrip()

			if line.startswith('?'):
				self.update_options(line)
				continue

			if self.opt['fmt'] == 0:
				self.output.append(line)				
			else:
				if not line:
					if fmt_line:
						self.output.append(fmt_line)
						fmt_line = ''
					self.output.append('')
				else:
					words = line.split()
					for word in words:
						if (len(fmt_line) + len(word) + 1) > self.opt['pgwdth']:
							self.output.append(fmt_line)
							fmt_line = ''
						elif fmt_line:
							fmt_line += ' '
						if not fmt_line:
							fmt_line = fmt_line.rjust(self.opt['mrgn'])
						fmt_line += word
		
		if self.opt['fmt'] == 1 and fmt_line:
			self.output.append(fmt_line)

	def getlines(self):
		"""
		Return formatted lines.
		"""
		return self.output		

