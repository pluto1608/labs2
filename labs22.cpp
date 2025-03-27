#include <iostream>
using namespace std;
//queue raboti taka sto clenot koj sme go stavile prv go vadime prv
struct queue{
  int q[10],f,r;//f e indeks na prviot clen koj sme go stavile vo nizata a r e krajot na nizata
  void overflow(){
    cout<<"Overflow"<<endl;
    exit(-1);
  }
  void underflow(){
    cout<<"Underflow"<<endl;
    exit(-1);
  }
  void init(){
    f=r=-1;
  }
  void put(int n){
    if(r>9)overflow();
    else {
      if(f==-1)f=0;//uslov za koga prv pat koristime put, togas da bide f=r=0
      q[++r]=n;//prvo se zgolemuva r pa se dodava n
    }
  }
  int pull(){
    int n;
    if(f==-1)underflow();
    else{
      n=q[f];
      if(f==r)f=r=-1; //koga f=r toa znaci deka sme go izvadile posledniot clen na nizata i tuka taa se resetira
      else f++;//dokolku ne e posleden clen indeksot na brojot koj e na red se zgolemuva z.s. sme izvadile eden
    }
    return n;
  }
  int peek(){
    if(f==-1)underflow();
    return q[f]; //ako ima clen vo nizata go gleda bez da se pomesti f
  }
  int len(){
    return r-f+1;//+1 z.s. pr ima 3 clena f=0 r=2 r-f=2 a ima 3 clena
  }
};

void funk(queue q, queue q1) {
  int n,c=q.len();
  for (int i=0;i<c-1;i++) {
    n=q.pull();//se zema cifrata koja prva e stavena vo q
    if ( (n+q.peek())<=9 ) {//se proveruva dali zbirot na odredena cifra i slednata e pomal ili ednakov na 9
      q1.put(n+q.peek());//ako e se stava vo q1, se pravi so peek a ne pull z.s. sporeduvanjeto ne e dve po dve cifri
    }//tuku sekoja cifra se sporeduva so slednata pr. za 654721 6 so 5 se sporeduva pa 5 so 4 namesto 6 so 5 pa 4 so 7
    else {
      q1.put(n);//ako ne prvata cifra se stava vo q1
    }
  }
  for (int i=0;i<c-1;i++) {
    cout<<q1.pull(); //se pecati q1
  }
}

int main(){
  int n,n1,c=0,a[10];
  queue q,q1;
  q.init();
  q1.init();
  cout<<"daj broj gng(ne poishe od 10 cifri mame ti ebam sho ke ti se tolku cifri):"<<endl;
  cin>>n;
  for (int i=0;n>0;i++) {//vo niza se stavaat cifrite z.s. se naopaku a so redovi ne e mozno da se prevrti brojot
    n1=n%10;
    n=n/10;
    a[i]=n1;
    c++;
  }
  for (int i=0;i<c;i++) {//se prevrtuva brojot i se stava vo red
    q.put(a[c-1-i]);
  }
  funk(q,q1);
}