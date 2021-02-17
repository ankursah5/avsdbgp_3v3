#include <iostream>
#include<fstream>
using namespace std;
class segmentation
{
	public:
		string segment_name;
		string address;
		string length;
		string filename;
};
void read()
{
    ifstream fin;
    string line;
    fin.open("hi.csv");
    int found;
    string pat;
    int count=0,i,j=0;
	int *index= new int;
	string *words = new string;
	string word;
	segmentation *r= new segmentation;
    
     while(!fin.eof())
	{
		fin>>line;
        cout<<line<<"\n";
        pat=",";
        found = line.find(pat); 
        index[0]=0;
        i=1;
        count=0;
        while (found != string::npos) 
		{ 
        	cout << "Pattern found at index " << found << endl; 
        	index[i]=found;
        	cout<<"Index["<<i<<"]="<<index[i]<<endl;
        	i=i+1;
        	found = line.find(pat, found + 1); 
        	count=count+1;
			
    	}
    	index[i]=line.length();
    	cout<<"Index["<<i<<"]="<<index[i]<<endl;
    	count=count+1;
    	//cout<<line.substr(index[i-1]+1,(index[i]-index[i-1]))<<endl;
    	//i=0;
    	//word=line.substr(index[i],(index[i+1]-index[i]));
		//cout<<"word="<<word<<endl;
		for(i=0;i<count;i++)
		{
			if(i==0)
				cout<<line.substr(index[i],(index[i+1]-index[i]))<<endl;
			else if(i>0 && i!=count-1)
				cout<<line.substr(index[i]+1,(index[i+1]-index[i]-1))<<endl;
			else
				cout<<line.substr(index[i]+1,(index[i+1]-index[i]))<<endl;
		
			//cout<<"words"<<i<<"="<<words[i];
			//cout<<"index"<<i<<"="<<index[i]<<"len="<<index[i+1]-index[i]<<endl;
			
		}
    	
	}
}
int main()
{
    read();
    return 0;
}

