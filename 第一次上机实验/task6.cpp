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
			cout<<"��ǰ����"<<U<<endl; 
			cout<<"������"<<7-U<<endl; 
			cout<<"������";
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
