#include<iostream>
#include<cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include<string>
#include <fstream>
using namespace std;
const int Level_Akhari=15;
clock_t init, final;
float total_time=0;

int random(int n)
{
return (rand()%n);
}

void sleep(long wait)
{
    clock_t start = clock();
    while (clock() - start < wait);
    
}

void Write_UserAndPass()
{
	string UserName,PassWord;
	fstream UP("Date/ULP.txt",ios::out|ios::app);
	if(!UP)
	{
		cerr<<"File can not open.";
		exit(1);
	}
	else
	{
		cout<<"UserName : ";
		cin>>UserName;
		cout<<"PassWord : ";
		cin>>PassWord;
		UP<<UserName<<" "<<PassWord<<endl;
	}
	UP.close();
}

void Read_UserAndPass()
{
	string UN_SakhteShode,Pass_SakhteShode,UNP_TMP;
	cout<<"UserName : ";
	cin>>UN_SakhteShode;
	cout<<"PassWord : ";
	cin>>Pass_SakhteShode;
	UNP_TMP=UN_SakhteShode+" "+Pass_SakhteShode;
    string tmp;
    string UserName,PassWord;
    fstream UP("Date/ULP.txt",ios::in);
    if(!UP)
    {
        cerr<<"File can not open.";
        exit(1);
    }	
    else
    {
    	while(UP>>UserName>>PassWord)
    	{
    		tmp=UserName+" "+PassWord;
    		if(tmp==UNP_TMP)
    		{
    			break;
    		}
    	}
    	if(tmp!=UNP_TMP)
    	{
    		cout<<"Etelate dade shode tavasote shoma moshkel darad lotfan jahat estef Dobare,DobareVarede Barname Shavid";
    		exit(1);
    	}
    }
}
void Tabe_Jame(int shomare_level,string str[],int n,int tedadeKhorooji,int zamne_marhale,int TedadeCharDarHarLevel,int percent)
{  
    string x="";
	bool avalin_bar_gardeshe_halghe=true;
    int sanie=0;
   string pass="no";
	int cnt_Correct=0,cnt_inval=0;
	string str_vasete[tedadeKhorooji];
	string str_voroodi[tedadeKhorooji];
	cout<<"\nLEVELE"<<shomare_level<<"\n\n";
	do
	{
	cout<<"*if you're ready press any key and then press enter* ";
    cin>>x;
    cout<<"\n";
	for(int i=0;i<tedadeKhorooji;i++)
	{
		for(int j=0;j<TedadeCharDarHarLevel;j++)
		{
		
		str_vasete[i]+=str[random(n)];
	    }
	   	cout<<str_vasete[i]<<" ";
	}
	cout<<"\n";	
    init=clock();
	for(int j=0;j<tedadeKhorooji;j++)
	{
	  cin>>str_voroodi[j];
    }
    final=clock()-init;
    sanie= (double)final / ((double)CLOCKS_PER_SEC);
  //End Timer------------------------------------------------------------------
for(int k=0;k<tedadeKhorooji;k++){
	  if(str_voroodi[k]==str_vasete[k])
	  {
	  	cnt_Correct+=1;
	  }
	  else
	  {
	  	cnt_inval+=1;
	  }
	  str_vasete[k]="";//reset
	}
	cout<<"\n\nTime:"<<sanie<<" s"<<"\t"<<"true="<<cnt_Correct<<"\tfalse="<<cnt_inval<<"\t";
	int Formula=((cnt_Correct*3-cnt_inval)*100/(tedadeKhorooji*3));
	cnt_inval=0;
	cnt_Correct=0;
    int tmp_sanie;
    tmp_sanie=sanie;
    sanie=0;
    
	if(Formula>=percent && tmp_sanie<=zamne_marhale)
	{
	if(shomare_level<=Level_Akhari-1)
	{
	pass="ok";
	cout<<"\t%"<<Formula<<"  Next Level\n\n";
    }
    else
	{
	cout<<"\t You Win";	
    }
	}
	else{
		cout<<"\t%"<<Formula<<"  Try agin\n\n";
		avalin_bar_gardeshe_halghe=false;
		continue;
	}
  }while(pass!="ok");
   cout<<"\n--------------------------------------------------------------------------------\n";    
}

void TMT_VERSION_1()
{
   srand(time(0));
   int LevelBin;
   int Level=1;
   do{
   cout<<"Wich level you want to paly?  ";
   cin>>Level;
   cout<<"\n--------------------------------------------------------------------------------\n";   
   if(Level>15)
   cout<<"bazi 15 marhalei ast.\n" ;
   }while(Level>15);
   if(Level==1)
   {
   string str1[9]{"a","s","d","f","g","h","f","k","l"};
   Tabe_Jame(1,str1,9,18,40,1,70);
   Level+=1;
   }
   if(Level==2)
   {
   string str2[10]{"q","w","e","r","t","y","u","i","o","p"};
   Tabe_Jame(2,str2,10,19,40,1,70);
   Level+=1;
   }
   if(Level==3)
   {
   string str3[7]{"z","x","c","v","b","n","m"};
   Tabe_Jame(3,str3,7,20,40,1,70);
   Level+=1;
   } 
   if(Level==4)
   {
   string str4[26]{"q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","f","k","l","z","x","c","v","b","n","m"};
   Tabe_Jame(4,str4,26,18,50,2,68);
   Level+=1;
   }
       if(Level==5)
   {
   string str5[10]{"q","w","e","r","t","y","u","i","o","p"};
   Tabe_Jame(5,str5,10,20,50,2,68);
   Level+=1;
   } 
        if(Level==6)
   {
   string str6[7]{"z","x","c","v","b","n","m"};
   Tabe_Jame(6,str6,7,21,50,2,68);
   Level+=1;
   }
   if(Level==7)
   {
   string str7[9]{"a","s","d","f","g","h","f","k","l"};
   Tabe_Jame(7,str7,9,22,50,2,68);
   Level+=1;
   }
   if(Level==8)
   {
   string str8[26]{"q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","f","k","l","z","x","c","v","b","n","m"};
   Tabe_Jame(8,str8,26,19,60,3,80);
   Level+=1;
   }
   if(Level==9)
   {
   string str9[36]{"q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","f","k","l","z","x","c","v","b","n","m","1","2","3","4","5","6","7","8","9","0"};
   Tabe_Jame(9,str9,36,20,60,3,80);
   Level+=1;
   }
   if(Level==10)
   {
   string str10[26]{"q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","f","k","l","z","x","c","v","b","n","m"};
   Tabe_Jame(10,str10,26,21,60,3,80);
   Level+=1;
   }
   if(Level==11)
   {
   string str11[36]{"A","S","D","F","G","H","J","K","L","P","O","I","U","Y","T","R","E","W","Q","Z","X","C","V","B","N","M","1","2","3","4","5","6","7","8","9","0"};
   Tabe_Jame(11,str11,36,25,62,1,90);
   Level+=1;
   }
   if(Level==12)
   {
   string str12[62]{"A","S","D","F","G","H","J","K","L","P","O","I","U","Y","T","R","E","W","Q","Z","X","C","V","B","N","M","1","2","3","4","5","6","7","8","9","0","q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","f","k","l","z","x","c","v","b","n","m"};
   Tabe_Jame(12,str12,62,25,60,2,85);
   Level+=1;
   }
   if(Level==13)
   {
   string str13[62]{"A","S","D","F","G","H","J","K","L","P","O","I","U","Y","T","R","E","W","Q","Z","X","C","V","B","N","M","1","2","3","4","5","6","7","8","9","0","q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","f","k","l","z","x","c","v","b","n","m"};
   Tabe_Jame(13,str13,62,27,62,3,85);
   Level+=1;
   }
   if(Level==14)
   {
   string str14[62]{"A","S","D","F","G","H","J","K","L","P","O","I","U","Y","T","R","E","W","Q","Z","X","C","V","B","N","M","1","2","3","4","5","6","7","8","9","0","q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","f","k","l","z","x","c","v","b","n","m"};
   Tabe_Jame(14,str14,62,25,67,4,85);
   Level+=1;
   }
   if(Level==15)
   {
   string str15[62]{"A","S","D","F","G","H","J","K","L","P","O","I","U","Y","T","R","E","W","Q","Z","X","C","V","B","N","M","1","2","3","4","5","6","7","8","9","0","q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","f","k","l","z","x","c","v","b","n","m"};
   Tabe_Jame(15,str15,62,30,75,5,85);
   }
}
int main()
{
	int acount;
	cout<<"Aya Mikhahid Acount 1(Jadid Besazid) Ya Az 2(Acount Sakhte shode etefade Konid)?ba neveshtane 1 ya 2 maloom konid\n";
	cin>>acount;
	if(acount==1)
	{
		Write_UserAndPass();
		TMT_VERSION_1();
		exit(1);
	}
	else if(acount==2)
	{
		Read_UserAndPass();
		TMT_VERSION_1();
		exit(1);
	}
	exit(1);
}
