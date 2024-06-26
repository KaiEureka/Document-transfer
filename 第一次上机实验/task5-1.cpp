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
int main()
{
	int card[100];
	for(int i=0;i<=53;i++)card[i]=i;
	for(int i=0;i<=100;i++)
	{
		int a=T.Integer(0,53),b,t;
		do{
			b=T.Integer(0,53);	
		} while(b==a);
		t=card[a];card[a]=card[b];card[b]=t;
	}
	for(int i=0;i<=53;i++)cout<<card[i]<<' '<<endl;
 } 
