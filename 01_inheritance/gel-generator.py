from gi.repository import GObject

class Generator(GObject.Object):
	#
	# __g_type__ is a special class member that defines
	# the name of the class. It does all the magic.
	#
	__g_type__ = 'Generator'

	#
	# __init__ is the standard way to initalize object in python,
	# GObject and his derivates also use __init__
	#
	def __init__(self):

		# Call GObject.Object init
		GObject.Object.__init__(self)

		# Setup internal state
		self._counter = 0

	#
	# This is an usable method for our class
	#
	def get_next(self):
		ret = self._counter
		self._counter = self._counter + 1
		return ret

if __name__ == '__main__':
	gen = Generator()

	for i in xrange(0, 43):
		print gen.get_next()

