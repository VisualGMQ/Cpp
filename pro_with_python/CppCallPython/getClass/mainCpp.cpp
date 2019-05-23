#include <Python.h>
#include <string>
#include <iostream>
using namespace std;

int main(){
	Py_Initialize();
	PyObject* modul = nullptr, *func = nullptr, *args = nullptr, *Class = nullptr;
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./')");
	modul = PyImport_ImportModule("mainPy");
	Class = PyObject_GetAttrString(modul, "testClass");
	PyObject* instance = nullptr;
	args = Py_BuildValue("(s)", "VisualGMQ");
	instance = PyEval_CallObject(Class, args);	
	PyObject *m_func = nullptr;
	m_func = PyObject_GetAttrString(instance, "printName");
	PyEval_CallObject(m_func, nullptr);
	Py_Finalize();	
	return 0;
}
