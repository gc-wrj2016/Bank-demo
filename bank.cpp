#include<bits/stdc++.h>
#include<Windows.h>
#include<conio.h> 
#define int long long
using namespace std;
string truekey;
bool key()
{
	cout<<"请输入密码：";
	string mima;
	while(1)
	{
		char x=getch();
		if(x!='\r')
		{
			mima+=x;
			cout<<"*";
		}
		else
		{
			cout<<"\n";
			break;
		}
	}
	return mima==truekey;
}
map<string,double>m;
signed main()
{
	double money=0,cnt;
	string name;
	ifstream testFile("test.txt");
	if (testFile >> cnt) {
		for(int i = 1; i <= cnt; i++) {
			testFile >> name >> money;
			m[name] = money;
		}
		testFile>>truekey;
		testFile.close();
	}
	system("chcp 65001");
	ios::sync_with_stdio(true);
	while(1)
	{
		
		system("cls");
		cout<<"请输入操作（序号）：\n1.查询\n2.花钱\n3.存钱\n4.注册\n5.注销\n10086.退出\n";
		double tmp;
		cin>>tmp;
		cin.clear();
		while(cin.get()!='\n');
		if(tmp==10086)
		{
			break;
		}
		if(tmp==666888)
		{
			string mima;
			while(1)
			{
				char x=getch();
				if(x!='\r')
				{
					mima+=x;
					cout<<"*";
				}
				else
				{
					cout<<"\n";
					break;
				}
			}
			truekey=mima;
			continue;
		}
		if(tmp==1)
		{
			cout<<"请输入名字：";
			string cname;
			cin>>cname;
			if(m.count(cname))
			{
				cout<<"余额："<<m[cname];
			}
			else
			{
				cout<<"查询对象不存在!";
			}
			Sleep(1000);
			continue;
		}
		if(tmp==2)
		{
			cout<<"请输入名字：";
			string hname,mima;
			cin>>hname;
			if(m.count(hname)==0)
			{
				cout<<"花钱对象不存在!";
			}
			else
			{
				if(key())
				{
					int hu;
					cout<<"请输入花费的钱：";
					cin>>hu;
					if(hu>m[hname])
					{
						cout<<"余额不足！";
					}
					else
					{
						m[hname]-=hu;
						cout<<"扣费完成！";
					}
				}
				else
				{
					cout<<"密码错误！";
				}
			}
			Sleep(1000);
			continue;
		}
		if(tmp==3)
		{
			cout<<"请输入名字：";
			string cname,mima;
			cin>>cname;
			if(m.count(cname)==0)
			{
				cout<<"存钱对象不存在!";
			}
			else
			{
				if(key())
				{
					double cu;
					cout<<"请输入存的钱：";
					cin>>cu;
					m[cname]+=cu;
					cout<<"存钱完成！";
				}
				else
				{
					cout<<"密码错误！";
				}
			}
			Sleep(1000);
			continue;
		}
		if(tmp==4)
		{
			cout<<"用户名：";
			string users;
			cin>>users;
			if(m.count(users)==1)
			{
				cout<<"此用户存在！";
			}
			else
			{
				cout<<"注册成功！";
				m[users]=0;
			}
			Sleep(1000);
			continue;
		}
		if(tmp==5)
		{
			cout<<"注销用户名：";
			string users;
			cin>>users;
			if(m.count(users)==0)
			{
				cout<<"用户不存在!";
			}
			else
			{
				cout<<"确认？是（y）否（n）:";
				char a;
				cin>>a;
				if(a=='y')
				{
					m.erase(users);
					cout<<"注销成功！";
				}
			}
			Sleep(1000);
			continue;
		}
	}
	freopen("test.txt","w",stdout);
	cout<<m.size()<<'\n';
	for(auto i=m.begin();i!=m.end();i++)
	{
		cout<<i->first<<" "<<i->second<<'\n';
	}
	cout<<truekey;
	return 0;
}