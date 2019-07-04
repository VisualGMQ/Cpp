#include <iostream>
#include <string>
#include <tinyxml2.h>
using namespace std;
using namespace tinyxml2;

int main(int agrc, char ** argv){
	XMLDocument doc;
	XMLDeclaration* declaration =  doc.NewDeclaration("version=3.2 encoding=UTF-8");
	doc.InsertFirstChild(declaration);
	XMLElement* root = doc.NewElement("root");
	root->SetAttribute("author", "VisualGMQ");
	root->SetAttribute("age", 20);
	//root->SetText("this is a text");
	XMLElement* ele1 = doc.NewElement("data");
	ele1->SetText("2019.06.25");
	root->InsertFirstChild(ele1);
	XMLComment* comment = doc.NewComment("this is a comment");
	root->InsertEndChild(comment);
	doc.Error
	doc.InsertEndChild(root);
	doc.SaveFile("ret.xml");
	return 0;
}
