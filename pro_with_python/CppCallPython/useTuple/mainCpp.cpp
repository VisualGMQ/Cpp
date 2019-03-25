#include <Python.h>
#include <iostream>
using namespace std;

int main(){
	Py_Initialize();
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./')");
	PyObject* modul = nullptr, *func = nullptr;
	modul = PyImport_ImportModule("mainPy");
	func = PyObject_GetAttrString(modul, "printTuple");
	PyObject* pytuple = nullptr;
	pytuple = PyTuple_New(3);
	PyTuple_SetItem(pytuple, 0, Py_BuildValue("i", 200));
	PyTuple_SetItem(pytuple, 1, Py_BuildValue("s", "VisualGMQ"));
	PyTuple_SetItem(pytuple, 2, Py_BuildValue("b", true));
	PyObject_CallObject(func, pytuple);
	Py_DECREF(pytuple);
	Py_Finalize();
	return 0;
}
