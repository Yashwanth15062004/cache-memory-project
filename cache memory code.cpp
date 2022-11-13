#include <bits/stdc++.h>
using namespace std;
#define ll long long
string decimalToBinary(ll num,ll no_bits)
{
    string str="";
      while(no_bits--){
      if(num%2==0)
        str='0'+str;
      else
        str='1'+str;
      num=num/2;
    }   
      return str;
}

ll  bin_to_int(string y)
{
       ll x=0,count=0;
        ll n=y.length();
        
        for(ll i=n-1;i>=0;i--)
        {
            y[i]=y[i]-48;
                x=x+(y[i]*((ll)pow(2,count)));
                count++;
                
        }
        return x;
}
string hex_to_bin(string hexDecNum){
    string s="";
    int i=0;
 while(hexDecNum[i])
    {
        switch(hexDecNum[i])
        {
            case '0':
                s=s+"0000";
                break;
            case '1':
                s=s+"0001";
                break;
            case '2':
                s=s+"0010";
                break;
            case '3':
                s=s+"0011";
                break;
            case '4':
                s=s+"0100";
                break;
            case '5':
                s=s+"0101";
                break;
            case '6':
                s=s+"0110";
                break;
            case '7':
                s=s+"0111";
                break;
            case '8':
                s=s+"1000";
                break;
            case '9':
                s=s+"1001";
                break;
            case 'a':
                s=s+"1010";
                break;
            case 'b':
                s=s+"1011";
                break;
            case 'c':
                s=s+"1100";
                break;
            case 'd':
                s=s+"1101";
                break;
            case 'e':
                s=s+"1110";
                break;
            case 'f':
                s=s+"1111";
                break;
        }
        i++;
    }
    return s;
}

string final_bin(string s,int n){
    n-=s.length();
    while(n--){
   s="0"+s;
    }
    return s;
}


int main() {
    ll no_bits,cache_size,no_ways,block_size;
    cin>> no_bits>>cache_size>>no_ways>>block_size;
    int block_offset=log2(block_size);
    ll no_of_blocks=cache_size/block_size;
    ll no_of_sets=no_of_blocks/no_ways;
    int index_bits=log2(no_of_sets);
    vector<ll> a[no_of_sets];
    ll t;
    cin>>t;
    ll num;
    ll hitr=0;ll missr=0; 
    ll missw=0; ll hitw=0;
    while(t--){
      string s;
      cin>>s;
     string addr=hex_to_bin(s.substr(1,s.length()-1));
     addr=final_bin(addr,no_bits);
     ll index=bin_to_int(addr.substr(no_bits-index_bits-block_offset,index_bits));
      ll tag=bin_to_int(addr.substr(0,no_bits-index_bits-block_offset));
      ll dirty[(no_bits-block_offset+1)*(no_of_sets)*no_ways]={0};
       bool find_tag;
       vector<ll>::iterator it=a[index].begin();
       it=find(a[index].begin(),a[index].end(),tag);
       if(it!=a[index].end()){
        if(s[0]=='1') {hitr++;dirty[tag]=0;}
           else {
            hitw++;
            dirty[tag]=1;
            dirty[tag]=0;}
           find_tag=true;
           a[index].erase(it);
            a[index].push_back(tag);
       }
      else{
          if(s[0]=='1') {missr++;dirty[tag]=0;}
           else {
            missw++;
            dirty[tag]=1;

            dirty[tag]=0;}
          if(a[index].size()==no_ways){
              a[index].erase(a[index].begin());
              a[index].push_back(tag);
          }
          else{
              a[index].push_back(tag);
          }
      }
    }
    double ansr=(double)hitr/(hitr+missr);
double answ=(double)hitw/(hitw+missw);
double ans=(double)(hitw+hitr)/(hitw+hitr+missr+missw);
   cout<<"Read hit rate "<<ansr*100<<endl;
   cout<<"Write hit rate "<<answ*100<<endl;
   cout<<"total hit rate "<<ans*100<<endl;
}