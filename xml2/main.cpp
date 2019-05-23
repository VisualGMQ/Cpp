#include <iostream>
#include "libxml/xmlmemory.h"
#include "libxml/parser.h"
using namespace std;

int main(int agrc, char ** argv){
		xmlDocPtr doc = xmlParseFile("./testXml.xml");
		if(doc == nullptr)
			cout<<"can't open the doc"<<endl;
		xmlNodePtr root = xmlDocGetRootElement(doc);
		if(root == nullptr)
			cout<<"can't get the root of the doc"<<endl;
		else 
			cout<<root->name<<endl;
		root = root->xmlChildrenNode;
		while(root != nullptr){
			cout<<root->name<<endl;
			root = root->next;
			xmlChar* key = xmlNodeListGetString(doc, root->xmlChildrenNode, 1);
			if(key != nullptr){
				cout<<key<<endl;
			}
		}
		xmlFreeDoc(doc);
		return 0;
}
