#include <Python.h>
#include <iostream>
using namespace std;

void NoArgsFunctionCall(){
	Py_Initialize();
	PyObject* modul = nullptr,*func = nullptr;
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./')");	
	modul = PyImport_ImportModule("mainPy");
	func = PyObject_GetAttrString(modul,"Hello");
	PyEval_CallObject(func, nullptr);
	Py_Finalize();
}

void argsFunctionCall(){
	Py_Initialize();
	PyObject* modul = nullptr, *func = nullptr;
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./')");
	modul = PyImport_ImportModule("mainPy");
	func = PyObject_GetAttrString(modul, "sum");
	PyObject* args = nullptr;
	args = Py_BuildValue("ii", 3 ,2);
	PyObject* result = nullptr;
	result = PyEval_CallObject(func, args);
	int i;
	PyArg_Parse(result, "i", &i);
	cout<<"the result is:"<<i<<endl;
	Py_Finalize();
}

int main(){
	NoArgsFunctionCall();
	argsFunctionCall();
	return 0;
}
