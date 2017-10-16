#!/usr/bin/python

class seng265_formatter:

	def __init__(self, filename="", lines=[]):
		
		self.opts = {
			'fmt' : False,
			'pgwdth' : 0,
			'mrgn' : 0
		}

		self.state = {
			'line_no' : 0,
			'char_no' : 0
		}

		if filename:
			inputfile = open(filename, 'r')
			self.lines = inputfile.readlines()
		else:
			self.lines = lines

		self.output = []

	def update_options(self):
		pass
	
	def format_lines(self):
		self.output = self.lines

	def getlines(self):
		return self.output		

