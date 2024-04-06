#include<iostream>
#include<string>
#define Max 1000//便于后期维护 使用宏定义
using namespace std;
struct Person//联系人结构体
{
	string m_Name;//姓名
	int m_sex;//性别 男1女2其余错
	int m_age;//年龄
	string m_phone;//电话
	string m_add;//住址

};
struct Addressbooks//通讯录结构体
{
	struct Person personArray[Max];//保存联系人数组
	int m_size = 0;//当前存储的联系人数量

};
void AddPerson(Addressbooks* abs)
{
	//判断电话本是否满了
	if (abs->m_size == Max)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;

		cout << "请输入性别(男性请输入1，女性请输入2）：" << endl;

		//性别
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入"<< endl;
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age > 0 || age < 150)
			{
				abs->personArray[abs->m_size].m_age = age;
				break;
			}
			cout << "输入有误，请重新输入";
		}

		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_add = address;

		//更新通讯录人数
		abs->m_size++;

		cout << "添加成功!" << endl;
		system("pause");
		system("cls");
	}
}
void ShowPerson(Addressbooks* abs)//封装显示联系人函数
{
	if (abs->m_size == 0)
	{
		cout << "无联系人信息！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名:" << abs->personArray[i].m_Name <<' ';
			cout << "性别:" << (abs->personArray[i].m_sex == 1 ? "男" : "女" )<< ' ';
			cout << "年龄" << abs->personArray[i].m_age << ' ';
			cout << "家庭地址" << abs->personArray[i].m_add << ' ';
			cout << "电话号码" << abs->personArray[i].m_phone << endl;
			
		}
	}
	system("pause");
	system("cls");
}
int Person_is_exist(Addressbooks* abs,string name)//联系人是否存在
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
void deletePerson(Addressbooks* abs)
{
	cout << "请输入要删除的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = Person_is_exist(abs, name);
	for (int i = ret; i < abs->m_size; i++)
	{
		if (i != -1)
		{
			abs->personArray[i] = abs->personArray[i = 1];
			cout << "已找到联系人，正在删除......" << endl;
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "查无此人！" << endl;
		}
	}
	abs->m_size--;
	system("pause");
	system("cls");
}
void Findperson(Addressbooks* abs)//封装查找联系人函数
{
	cout << "请输入要查找联系人的姓名：" << endl;
	string name;
	cin >> name;
	int ret = Person_is_exist(abs, name);
	if (ret != -1)
	{
		cout << "姓名:" << abs->personArray[ret].m_Name << ' ';
		cout << "性别:" << (abs->personArray[ret].m_sex == 1 ? "男" : "女") << ' ';
		cout << "年龄" << abs->personArray[ret].m_age << ' ';
		cout << "家庭地址" << abs->personArray[ret].m_add << ' ';
		cout << "电话号码" << abs->personArray[ret].m_phone << endl;
	}
	else
	{
		cout << "查无此人!" << endl;
	}
	system("pause");
	system("cls");
}
void Changeperson(Addressbooks* abs)
{
	cout << "请输入要修改的联系人的姓名：" << endl;
	string name;
	cin >> name;
	int ret = Person_is_exist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		cout << "请输入修改后的性别：" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		cout << "请输入修改后的年龄：" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age > 0 || age < 150)
			{
				abs->personArray[ret].m_age = age;
				break;
			}
			cout << "输入有误，请重新输入";
		}

		//联系电话
		cout << "请输入修改后的联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[ret].m_phone = phone;

		//家庭住址
		cout << "请输入修改后的家庭住址：" << endl;
		string add;
		cin >> add;
		abs->personArray[ret].m_add = add;
		cout << "修改成功!" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}
void Cleanperson(Addressbooks* abs)
{
	cout << "清空后无法恢复，确认要执行该操作吗？确认请输入‘y’" << endl;
	char a;
	cin >> a;
	if (a == 'y')
	{
		abs->m_size = 0;
		cout << "通讯录已清空！" << endl;
	}
	else
	{
		cout << "已取消该操作！" << endl;
	}
	system("pause");
	system("cls");
}
void showMenu()
{
	cout << "*****1.添加联系人*****" << endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****0.退出系统*******" << endl;
}
int main()
{
	Addressbooks abs;//创建通讯录结构体变量
	abs.m_size = 0;//初始化通讯录当前人员个数
	int select = 0;
	showMenu();//调用menu函数
	while (true)
	{
		//showMenu();//调用menu函数
		cin >> select;
		switch (select)
		{
		case 1://1.添加联系人
			AddPerson(&abs);//利用地址传递可以修饰实参
			break;
		case 2://2.显示联系人
			ShowPerson(&abs);
			break;
		case 3://3.删除联系人
			deletePerson(&abs);
			break;
		case 4://4.查找联系人
			Findperson(&abs);
			break;
		case 5://5.修改联系人
			Changeperson(&abs);
			break;
		case 6://6.清空联系人
			Cleanperson(&abs);
			break;
		case 0://0.退出系统
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}