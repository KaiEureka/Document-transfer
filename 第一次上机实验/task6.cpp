#include <limits.h>	//声明INT_MAX和ULONG_MAX常量
#include <windows.h>	//声明GetTickCount()函数,其返回从开机到现在经过的毫秒数
#include <stdlib.h>   //声明rand和srand函数
#include <time.h>     //声明time函数
#include <iostream>
using namespace std;
class TRandom
{	
public:
	//缺省使用系统时间(开机后经过的毫秒数)为种子
	TRandom (long seed=0)   { mSeed=(seed?seed: GetTickCount());  } 

	//也可以定义自己的种子
	void Seed(long seed=0)	{ mSeed=(seed?seed: GetTickCount( )); }     

	//取得一个随机的整数
	int  Integer()  			  { return Next();}        

	//取得一个在指定范围内的随机整数
	int  Integer(int min,int max) { return min+Next()%(max-min+1);} 

    	//取得一个随机的（0到1之间的）小数
	double Real() 				{return double(Next())/double(INT_MAX);}
private:
    	//使用调和算法
	void Change() 		{mSeed=(314159265*mSeed+13579)%ULONG_MAX;}

    	//取得伪随机数发生器的随机数序列中的下一个随机整数
	int  Next() { 
                int loops=mSeed%3;	
                for (int i=0;i<=loops;i++)  
                    Change ();
		return int(mSeed/2); 
            }
	unsigned long  mSeed;   //随机数发生器的种子
}T;
class dice
{
	public:
		dice(){
			U=T.Integer(1,6);
		}
		void roll(){
			U=T.Integer(1,6);
		}
		void report()
		{
			cout<<"当前面是"<<U<<endl; 
			cout<<"对面是"<<7-U<<endl; 
			cout<<"侧面是";
			for(int i=1;i<=6;i++)if(i!=U&&i!=7-U)cout<<i<<' '; 
			cout<<endl; 
		}
		int getU(){return U;
		}
	private:
		int U;
}D;
int main()
{
	int ans=0;
	for(int i=1;i<=100;i++)
	{
		D.roll();D.report();
		ans+=D.getU();
	}
	cout<<ans<<endl;
	return 0;
 } 
