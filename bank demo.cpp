#include<bits/stdc++.h>//2026.8.16 zhangjing
#include<thread>
#include<chrono>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e6+5;
map<string,int>user;
map<string,int>now_time;
map<string,int>Password;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ifstream fin("zl.txt");
	int flag=0;
	fin>>flag;
	string mima;
	fin>>mima; 
	int n;
	fin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		string password;
		int m;
		int t;
		fin>>s>>password>>m>>t;
		user[s]=m;
		now_time[s]=t;
	}
	fin.close();
	if(flag==0)
	{
		cout<<"ÇëÊäÈë¹ÜÀíÔ±ÃÜÂë£º(Ä¬ÈÏ000):"<<flush; 
		cin>>mima; 
	}
	while(1)
	{
		cout<<"1.×¢²á\n2.µÇÂ¼\n3.×¢Ïú\n4.´æÇ®\n5.²éÑ¯\n6.ÍË³ö:"<<flush;
		int op;
		cin>>op;
		if(op<=0||op>=7)
		{
			cout<<"´íÎó£¡"<<flush;
			this_thread::sleep_for(chrono::seconds(1));
			system("cls"); 
		}
		else
		{
			if(op==1)
			{
				cout<<"ÇëÊäÈëÓÃ»§Ãû£º"<<flush;
				string name;
				cin>>name;
				cout<<"ÇëÊäÈëÃÜÂë£º"<<flush;
				string password;
				cin>>password;
				cout<<"OK!"<<flush;
				user[name]=0;
				now_time[name]=time(nullptr);
			}
			else if(op==6)
			{
				break;
			}
			this_thread::sleep_for(chrono::seconds(1));
			system("cls");
		}
	}
	ofstream fout("zl.txt");
	fout<<1<<endl<<mima<<endl<<user.size()<<endl;
	for(auto i:user)
	{
		fout<<i.first<<" "<<Password[i.first]<<" "<<i.second<<" "<<now_time[i.first]<<endl;
	}
	return 0;
}

