#include <iostream>
#include "person.pb.h"
#include <google/protobuf/message.h>
using namespace std;
using namespace tutorial;
using namespace google::protobuf;
int main()
{
	Person pTest;
	pTest.set_id(5656560);
	pTest.set_name("kelunce");
	pTest.set_email("lichengman2323@163.com");

	//���л�����һ,ת��Ϊ�ַ���
	string output;
	pTest.SerializeToString(&output);
	cout<<"SerializeToString: "<<output<<endl;

	//���л�������,ת��Ϊchar����
	int nLen = pTest.ByteSize();
	char *buff = new char[nLen];
	pTest.SerializeToArray(buff,nLen);
	cout<<"length of array: "<<strlen(buff)<<endl;
	delete []buff;

	//�����л�
	Person pTest1;
	pTest1.ParseFromString(output);
	cout<<"ParseFromString: "<<pTest1.email()<<endl;

	//����
	const Reflection* pReflection = pTest1.GetReflection();
	vector<const FieldDescriptor*> fields;
	pReflection->ListFields(pTest1,&fields);

	system("pause");

	/*
	5656 kelunce lichengman2323@163.com  �ռ�����33/36
	5656560  kelunce lichengman2323@163.com  �ռ�����36/38
	*/
	return 0;
}