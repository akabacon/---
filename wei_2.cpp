#include <iostream>
#include <cctype>   // for isdigit()
using namespace std;
#define max 10000
class BigInt {
    friend ostream& operator<<(ostream& , const BigInt&);
    private:              // encaptulation
      short num[max];  
      int len;
    public:
      bool compare(BigInt &b)
    {
    if(len<b.len)
        return  false;
    else if(len>b.len)
        return true;
    else
        return 2;
   }
      BigInt(long value=0) {   // default constructor but also constructor with long int paarameter
          for(int i=0; i<max; i++)
             num[i]=0;
          for(int i=max-1; i>=0 && value!=0; i--){
              num[i]= value % 10;
              value = value / 10;
          }
      }
      BigInt(string str) {    // constructor with a pointer to string parameter
          for(int i=0; i<max; i++)
             num[i]=0;
             this->len = str.length();
          for(int j=max-len, k=0; j<max; j++,k++){
              if (isdigit(str[k])) num[j]=str[k] - '0'; //str[k]=0~9
          }
      }
      BigInt operator+(const BigInt &op2) const {   // b1=b2+b3;  b3 is parameter object 
            BigInt temp;
            int carry=0;
            for(int i=(max-1); i>=0; i--)  {             // b2 is host object
                 int tnum = num[i] + op2.num[i] + carry;
                 if (tnum>9) {
                     temp.num[i]=tnum % 10;
                     carry=1;
                 }
                 else {
                     temp.num[i]= tnum;
                     carry=0;
                 }
            }
            return temp;
      }   
      BigInt operator-(BigInt&b){
         //substract Algorithm
    char sign='+';//正負號
    //讓a>b 如果a<b 那麼結果就是—(b-a) 
    //可以先將a和b交換
    BigInt temp;
    BigInt gap;
    
    if(!compare(b))
    {
        sign='-';
        cout<<sign;
        for(int i=max-1;i>=0;i--){
            int temp=num[i];
            num[i]=b.num[i];
            b.num[i]=temp;
        }
    }
    int a=len-1;
    int c=b.len-1;
    
    if(len==b.len){
    for(int i=0;i<=max-1;i++){
       if(num[i]<b.num[i]){
           sign='-';
           cout<<sign;
           for(int i=max-1;i>=0;i--){
            int temp=num[i];
            num[i]=b.num[i];
            b.num[i]=temp;
        }
           break;
    }
    else if(num[i]==b.num[i])continue;
    else break;
    }
    }
    int len1=len-1;
    int len2=b.len-1;
    
    int borrow=0;//借位
    for(int i=max-1;i>=0&&(len1>=0||len2>=0);i--&&(len1--)&&(len2--))
    {
        int tnum=num[i]-b.num[i]-borrow;
        borrow=0;
        if(tnum<0)//需要向前借位
        {
            borrow=1;
            temp.num[i]=tnum+10;
        }
        else{temp.num[i]=tnum;}
    }
    
    return temp;
};
};

ostream& operator<<(ostream& out, const BigInt &n){  // cout << b1;
    int i;                                  
    for(i=0; (n.num[i]==0) && (i<=(max-1)); i++); 
    
    if (i==max) out << 0;//一直都找不到不等於0的char
    else  {
        for(; i<max; i++)
            out << n.num[i];//ostream out is the same type 
    } //out can save various data type
    return out;
}


int main(){
    int i;
    char c;
    string a,b;
    BigInt b3(23);
    while(cin>>c){
    if(c=='#')break;
    cin>>a>>b;
    if(c=='+'){
        if(a.length()<b.length()){
            if(b.length()-a.length()==1){a+="0";}
            else{
            for(i=0;i<b.length()-a.length();i++){
                a+='0';
            }
            a+='\0';
            }
        }
     BigInt b1(a), b2(b);
     
     b3=b1+b2;
     //cout<<"a="<<b1<<endl;
     //cout<<"len of b1:"<<b1.len<<endl;
     cout<<b1+b2;
    }
    if(c=='-'){
        BigInt b3(a),b4(b);
        cout<<b3-b4;
    }
    }   
}