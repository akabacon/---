#include <iostream>
#include<math.h>
using namespace std;
class retangle {
   protected:  
     int length;
     int width;

   public:
      retangle():length(0),width(0){};  ///retangle;
      retangle(int tlength,int twidth):length(tlength),width(twidth){};//retangle 
      retangle(retangle &re){
          length=re.length;
          width=re.width; //this
      }
      int getLength(){return length;};
      int getwidth(){return length;};
      void setLength(int tlength){
        length=tlength;
      }
      void setWidth(int twidth){
        width=twidth;
      }
      int Area(int len,int wid){
        return len*wid;
      }
      int Volume(int len,int wid){
        return len*wid; 
      }
      void print(){
          cout<<"len="<<length<<" and wid= "<<width<<endl;
      }
};
class cuboid: protected retangle{
   private:
      int height;
   public:
      cuboid():retangle(),height(0){};//cuboid s1;
      cuboid(int tlength,int twidth,int theight):retangle(tlength,twidth),height(theight){}
      cuboid(cuboid &s):retangle(s.length,s.width),height(s.height){}
      void setH(double tH){
          height=tH;
      }
      int getH(){return height;}
      int Area(int tlength,int twidth,int theight){
        return 2*(tlength*twidth+twidth*theight+theight*tlength);
      }
      int Volume(int tlength,int twidth,int theight){
          return (tlength*twidth*theight);
      }
      void print(){//volume area
          int v=Volume(length,width,height);
          int a=Area(length,width,height);
          //cout<<"len="<<length<<" ,wid="<<width<<" ,Hei="<<height<<endl;
          cout<<"Volume:="<<v<<"\nSuirface="<<a<<endl;

      }

};
int main(){
    int T,len,wid,hei;
    cin>>T;
    for(int i=1;i<=T;i++){
    cin>>len>>wid>>hei;
    cuboid c1(len,wid,hei);
    cout<<"#"<<i<<endl;
    c1.print();
    }
}