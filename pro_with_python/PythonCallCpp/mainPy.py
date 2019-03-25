import ctypes

adder = ctypes.cdll.LoadLibrary('./libmainC.so')

adder.SayHello()
