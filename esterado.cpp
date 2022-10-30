//Checksum
// C++ implementation of checksum

#include<bits/stdc++.h>
using namespace std;

//Function to find the 1's complement of a binary

string ones_complement(string num)
{
	for (int i=0;i<num.length();i++){
		if (num[i] == '0'){
			num[i] = '1';
	}
		else
			num[i] = '0';
	}
	
	return num;
	
}

// Function to return the checksum value

string checkSum(string num, int size1){
	int n = num.length();
	if(n%size1!=0){
		int size2 = size1 - (n%size1);
		for (int i = 0; i<size2;i++){
			num = '0' +num;
		}
	}
	//addition of all binary with corresponding carry
	string res = "";
	
	//first line of data stored in res varialble
	for(int i = 0; i<size1;i++){
		res+=num[i];
	}
	//calculating the lines/addition of binary data
	for (int i =size1;i<n;i+=size1){
	//storing data of the next block
	string next = "";
	
	for (int j=i;j<i+size1;j++){
		next+=num[j];
	}
	//Stores binary addition of two lines
	string add = "";
	int sum = 0, carry = 0;
	//calculate the binary addition of the current two lines of x size
	for (int x = size1 -1; x>=0;x-- ){
		sum += (next[x] - '0') + (res[x] - '0');
		carry = sum/2;
		if(sum == 0){
			add = '0' + add;
			sum = carry;
		}
		else if (sum == 1){
			add = '1' +add;
			sum =carry;
		}
		else if (sum == 2){
			add = '0' + add;
			sum =carry;
		}
		else{
			add = '1'+ add;
			sum = carry;
		}
	}
	//After adding binary of two blocks with carry
	//if carry is equal to 1 then apply binary addition
	string final = "";
	
	if (carry == 1){
		for (int len = add.length() - 1; len>=0; len--){
			if(carry ==0){
				final = add[len] +final;
			}
			else if (((add[len]-'0') + carry)%2 == 0){
				final = "0" +final;
				carry =1;
			}
			else {
				final = "1" +final;
				carry = 0;
			}
		}
		
		res = final;
	}
	else{
		res = add;
	}
  }
  
  //retutn 1's complement of result value
  return ones_complement(res);
}
//function to check if the received message is the same with the senders message

bool check (string sent, string receive, int size1){
	
	//checksum value of the senders message
	string s_checksum = checkSum(sent,size1);
	
	//checksum value for the receiver's message
	string r_checksum = checkSum(receive+s_checksum,size1);
	
	// if receivers checksum value is 0
	if(count(r_checksum.begin(), r_checksum.end(), '0') == size1){
		return true;
	}
	else{
		return false;
	}
}


//source code
int main(){
	string sent = "10000101011000111001010011101101";
	string receive = "10000101011000111001010011101101";
	int size1 = 8;
	
	if(check(sent,receive,size1)){
		cout<<"No error";
	}
	else{
		cout<<"Error";
	}
	return 0;
}