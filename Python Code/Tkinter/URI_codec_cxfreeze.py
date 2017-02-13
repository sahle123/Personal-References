# URI_codec_cxfreeze.py
#
# Trying to get this to compile with either pyinstaller or cx_Freeze.
# cx_Freeze docs: http://cx-freeze.readthedocs.io/en/latest/script.html#script
#
#	Status:	Functional - WIP
#
#
#	LU: 08/30/16

from cx_Freeze import setup, Executable

import urllib
import codecs
import platform 	# To get machine's OS platform
import Tkinter 		# For GUI

# Global Vars/Consts
ENCODER_USED = 'utf-8'
SYSTEM_OS = None
##

# ------------------------------------
# Note that MainWindow.master is the parent class, which is Tkinter
class NomadMainWindow():
	global SYSTEM_OS

	def __init__(self, master=None):
		#Tkinter.Frame.__init__(self, master)
		#self.master.minsize(width=360, height=210)
		myRootFrame = Tkinter.Frame(master)
		myRootFrame.master.resizable(width=False, height=False)
		myRootFrame.pack()
		myRootFrame.master.title("URI encoder/decoder - Nomadic_09")

		### Labels and Text fields section ###
		self.description_label = Tkinter.Label(myRootFrame, text="String to encode/decode", width="70")
		self.description_label.pack()
		self.entry_field = Tkinter.Entry(myRootFrame, borderwidth="2", width="60")
		self.entry_field.pack()

		### Buttons section ###
		self.encode_button = Tkinter.Button(myRootFrame, text="Encode", \
			command=self.encode_input)
		self.encode_button.pack(side="left")
		self.decode_button = Tkinter.Button(myRootFrame, text="Decode", \
			command=self.decode_input)
		self.decode_button.pack(side="left")
		self.clear_button = Tkinter.Button(myRootFrame, text="Clear", \
			command=self.clear_entry)
		self.clear_button.pack(side="left", padx="25")
		self.quit_button = Tkinter.Button(myRootFrame, text="Quit", \
			command=myRootFrame.quit)
		self.quit_button.pack(side="right")

		### Key Rebindings section ###
		# 'Select all' hotkey
		if str(SYSTEM_OS) != "Darwin":
			myRootFrame.bind_class("Entry", "<Control-Key-a>", self.hotkey_select_all)
		else: # For Mac users
			myRootFrame.bind_class("Entry", "<Command-Key-a>", self.hotkey_select_all)

	### Methods section ###
	def encode_input(self):
		print "[*] encode_input method call"
		user_input = str(self.entry_field.get())
		result = URIcodec(user_input, True)
		self.clear_entry()
		self.entry_field.insert("0", result)

	def decode_input(self):
		print "[*] decode_input method call"
		user_input = str(self.entry_field.get())
		result = URIcodec(user_input, False)
		self.clear_entry()
		self.entry_field.insert("0", result)

	def clear_entry(self):
		self.entry_field.delete("0", "end")

	### Key rebind methods section ###
	def hotkey_select_all(self, event):
		event.widget.select_range("0", "end")
# ------------------------------------

# ----------------------------------------------------------------------------
# Dependencies: platform
def getOS_platform():
	global SYSTEM_OS
	SYSTEM_OS = platform.system()

	if SYSTEM_OS == None:
		print "[-] Could not determine your OS. Quitting..."
		exit(0)

# ----------------------------------------------------------------------------
# Dependencies: Tkinter
def myGUI():

	# Create root window. If this closes, so does all else.
	windowRoot = Tkinter.Tk()

	# This variable will house most of the page. Most of the page will be built by the constructor
	w_frontPage = NomadMainWindow(windowRoot)

	# Start the window events and rendering.
	windowRoot.mainloop()

# ----------------------------------------------------------------------------
# Dependencies: urllib, codecs
def URIcodec(user_input, is_encode):
	global ENCODER_USED

	if is_encode:
		result = urllib.quote(user_input.encode(ENCODER_USED), '^')
		print "[+] Encoded: " + result
		return str(result)
	else:
		result = urllib.unquote(user_input)
		print "[+] Decoded: " + result
		return str(result)

	# Should not reach here.
	print "[-] Error: Something went awry in URIcodec. Quitting..."
	exit(0)

# ----------------------------------------------------------------------------
def main():
	print "Starting URI_codec.py\n"
	getOS_platform()
	myGUI()

if __name__ == "__main__":
	main()

# ----------------------------------------------------------------------------
