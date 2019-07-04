#include <json/json.h>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void writeJson(){
    Json::Value root;
    root["name"] = Json::Value("VisualGMQ");
    root["age"] = Json::Value(20);
    Json::Value info;
    info["school"] = "AnHuiLiGongDaXue";
    info["credit"] = "2017303119";
    info["male"] = true;
    root["info"] = info;
    root["friend"].append("XianFen");
    root["friend"].append("CaiChuanXun");
    root["friend"].append("WuTao");
    Json::StreamWriterBuilder swb;
    Json::StreamWriter* sw = swb.newStreamWriter();
    ofstream ofile("ret1.json");
    sw->write(root, &ofile);
    ofile.close();
}

void ReadJson(){
    Json::CharReaderBuilder crb;
    Json::CharReader* cr = crb.newCharReader();
    ifstream ifile("test.json");
    ifile.seekg(0, ios::end);
    int len = ifile.tellg();
    ifile.seekg(0, ios::beg);
    char buffer[1024] = {'\0'};
    ifile.read(buffer, len);
    Json::Value root;
    JSONCPP_STRING err;
    cr->parse(&buffer[0], &buffer[len], &root, &err);
    //注意，std::boolalpha是控制符，ios::boolalpha才是常量
    cout<<boolalpha<<root.isObject()<<","<<root.isArray()<<endl;
    Json::Value ele1 = root.get("hello",Json::Value("no value"));
    cout<<ele1.asCString()<<endl;
    cout<<root.type()<<endl;
}

int main(){
    ReadJson();
    return 0;
}