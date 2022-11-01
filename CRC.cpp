#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int i,j,x,y;
	
	int f_size;
	cout<<"Enter size of frame: "<<endl;
	cin>>f_size;
	
	int f[20];
	
	cout<<"Enter Frame: ";
	for(i=0;i<f_size;i++){
		cin>>f[i];
	}
	
	int gen_size;
	cout<<"Enter size of Generator: ";
	cin>>gen_size;
	
	int g[20];
	
	cout<<"\n Enter Generator: ";
	for(i=0;i<gen_size;i++){
		cin>>g[i];
	}
	
	cout<<"\n Sender Side: ";
	cout<<"\n Frame: ";
	for(i=0;i<f_size;i++){
		cout<<f[i];
	}
	cout<<"\n Generator: ";
	for(i=0;i<gen_size;i++){
		cout<<g[i];
	}
	
	int r_size = gen_size-1;
	cout<<"\n Number of 0's to be added: "<<r_size;
	for(i=f_size;i<f_size+r_size;i++){
		f[i]=0;
	}
	
	int temp[20];
	for(i=0;i<20;i++){
		temp[i]=f[i];
	}
	
	cout<<"\n Message after adding 0's: ";
	for(i=0;i<f_size+r_size;i++){
		cout<<temp[i];
	}
	
	//division
	for(i=0;i<f_size;i++){
		j=0;
		x=i;
		//check whether it is divisible or not
		if(temp[x]>=g[j]){
			for(j=0,x=i;j<gen_size;j++,x++){
				if((temp[x]==1 && g[j]==1) || (temp[x]==0 && g[j]==0)){
					temp[x]=0;
				}
				else{
					temp[x]=1;
				}
			}
		}
	}
	
	//CRC
	int crc[15];
	for(i=0,j=f_size;i<r_size;i++,j++){
		crc[i]=temp[j];
	}
	cout<<"\n CRC bits: ";
	for(i=0;i<r_size;i++){
		cout<<crc[i];
	}cout<<"\n Transmitted Frame: ";
	int tf[15];
	for(i=0;i<f_size;i++){
		tf[i]=f[i];
	}
	for(i=f_size,j=0;i<f_size+r_size;i++,j++){
		tf[i]=crc[j];
	}
	for(i=0;i<f_size+r_size;i++){
		cout<<tf[i];
	}
	
	cout<<"\n Receiver: ";
	cout<<"\n Receiver Frame: ";
	for(i=0;i<f_size+r_size;i++){
		cout<<tf[i];
	}
	for(i=0;i<f_size+r_size;i++){
		temp[i]=tf[i];
	}
	
	//division
	for(i=0;i<f_size+r_size;i++){
		j=0;
		x=i;
		if(temp[x]>=g[j]){
			for(j=0,x=i;j<gen_size;j++,x++){
				if((temp[x]==1 && g[j]==1) || (temp[x]==0 && g[j]==0)){
					temp[x]=0;
				}
				else{
					temp[x]=1;
				}
			}
		}
	}
	cout<<"\n Remainder: ";
	int rem[15];
	for(i=f_size,j=0;i<f_size+r_size;i++,j++){
		rem[j]=temp[i];
	}
	for(i=0;i<r_size;i++){
		cout<<rem[i];
	}
	
	int flag = 0;
	for(i=0;i<r_size;i++){
		if (rem[i]!=0){
			flag =1;
		}
	}
	if(flag ==0){
		cout<<"\n CORRECT";
	}
	else{
		cout<<"\n INCORRECT";
	}
	getch();
}