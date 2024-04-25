#include <limits.h>	//����INT_MAX��ULONG_MAX����
#include <windows.h>	//����GetTickCount()����,�䷵�شӿ��������ھ����ĺ�����
#include <stdlib.h>   //����rand��srand����
#include <time.h>     //����time����
#include <iostream>
using namespace std;
class TRandom
{	
public:
	//ȱʡʹ��ϵͳʱ��(�����󾭹��ĺ�����)Ϊ����
	TRandom (long seed=0)   { mSeed=(seed?seed: GetTickCount());  } 

	//Ҳ���Զ����Լ�������
	void Seed(long seed=0)	{ mSeed=(seed?seed: GetTickCount( )); }     

	//ȡ��һ�����������
	int  Integer()  			  { return Next();}        

	//ȡ��һ����ָ����Χ�ڵ��������
	int  Integer(int min,int max) { return min+Next()%(max-min+1);} 

    	//ȡ��һ������ģ�0��1֮��ģ�С��
	double Real() 				{return double(Next())/double(INT_MAX);}
private:
    	//ʹ�õ����㷨
	void Change() 		{mSeed=(314159265*mSeed+13579)%ULONG_MAX;}

    	//ȡ��α�����������������������е���һ���������
	int  Next() { 
                int loops=mSeed%3;	
                for (int i=0;i<=loops;i++)  
                    Change ();
		return int(mSeed/2); 
            }
	unsigned long  mSeed;   //�����������������
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
