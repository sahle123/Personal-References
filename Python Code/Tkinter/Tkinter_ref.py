# Tkinter_ref.py
#
#	Des:	My personal reference for Tkinter. 
#
#	Some handy references: 	
#		1 - http://www.python-course.eu/tkinter_labels.php
#		2 - http://effbot.org/tkinterbook/
#		3 - http://stackoverflow.com/questions/14824163/how-to-get-the-input-from-the-tkinter-text-box-widget
#
#	LU:		02/08/16
#

import Tkinter
import platform


## Global Variables
SYSTEM_OS = None
#

# ----------------------------------------------------------------------------
class NomadButtons():
	global SYSTEM_OS

	def __init__(self, master=None):
		myFrame = Tkinter.Frame(master) # myFrame contains the root frame.
		myFrame.pack()


		### Labels and Text fields Section ###
		self.label_field = Tkinter.Label(myFrame, text="String to encode/decode")
		#self.label_field.grid(row=1, column=0, sticky="e")
		self.label_field.pack()
		self.entry_field = Tkinter.Entry(myFrame)
		self.entry_field.pack()


		### Buttons Section ###
		# Callback! button
		self.basic_button = Tkinter.Button(myFrame, text="Callback!", \
			command=self.class_callback)
		self.basic_button.pack(side="left")

		# Enter button
		self.enter_button = Tkinter.Button(myFrame, text="Enter", \
			command=self.retrieve_input)
		self.enter_button.pack(side="left")

		# Quit button
		self.quit_button = Tkinter.Button(myFrame, text="Quit", \
			command=myFrame.quit)
		self.quit_button.pack(side="left")


		### Key Rebindings Section ###
		if str(SYSTEM_OS) != "Darwin":
			myFrame.bind_class("Entry", "<Control-Key-a>", self.hotkey_select_all)
		else:
			myFrame.bind_class("Entry", "<Command-Key-a>", self.hotkey_select_all)


	def class_callback(self):
		print "[+] Inside class_callback"

	def retrieve_input(self):
		user_input = self.entry_field.get()
		print "[DEBUG] entry_field type: " + str(type(self.entry_field))
		print "[+] user_input: " + str(user_input)


	# Hotkeys section
	def hotkey_select_all(self, event):
		#print "HOTKEYS and junk"
		#print str(platform.system())
		event.widget.select_range("0", "end")

# ----------------------------------------------------------------------------
def getOS_platform():
	global SYSTEM_OS
	SYSTEM_OS = platform.system()

	if SYSTEM_OS == None:
		print "[-] Could not determine your OS. Quitting..."
		exit(0)

# ----------------------------------------------------------------------------
def basic_callback(event):
	print "[+] Callback!"


# ----------------------------------------------------------------------------
def main():

	getOS_platform()

	root = Tkinter.Tk()
	myClass = NomadButtons(root)
	root.mainloop()
	

if __name__ == "__main__":
	main()

# ----------------------------------------------------------------------------
"""
# Create Tkinter root frame. 
	root = Tkinter.Tk()
	root.geometry("480x300")

	# Creating 2 frame inside of root
	topFrame = Tkinter.Frame(root)
	bottomFrame = Tkinter.Frame(root, bg="#affaffaff")

	# Input the top and bottom frames into root so that it will render 
	# in mainloop
	topFrame.pack(side="top")
	bottomFrame.pack(side="bottom", fill="both")

	# Create a button in the bottonFrame
	button1 = Tkinter.Button(bottomFrame, text="Bottom Button")
	button1.grid(row="1")
	button1.bind("<Button-1>", basic_callback) # Left mouse click
	button1.pack(side="right", padx="20")


	label_field = Tkinter.Label(topFrame, text="String to encode/decode")
	label_field.grid(row=0, column=0, sticky="e")
	entry_field = Tkinter.Entry(topFrame)
	entry_field.grid(row=0, column=1)


	# Initiate main loop and events
	root.mainloop()
"""