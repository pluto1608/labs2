#include <iostream>
using namespace std;
//stack raboti taka sto posledniot clen koj sme go stavile prv go vadime 
struct stack{
  int s[10],top;

  void init(){ //se kreira stack top e -1 z.s. koga se koristi push top se zgolemuva za 1 i stanuva 0 so prviot clen
    top=-1;
  }
  void overflow(){ //za koga ke se iskoristi push no nema veke mesto vo stackot
    cout<<"Overflow"<<endl;
    exit(-1);//ja prekinuva programata tuka i vraka -1
  }
  void underflow(){ //za koga ke se iskoristi pop no stackot e prazen
    cout<<"Underflow"<<endl;
    exit(-1);
  }
  void push(int n){ //se dodava clen vo stackot
    if(top>=9)overflow(); //se proveruva dali ima mesto vo stackot
    s[++top]=n;//se dodava clenot vo stackot, ++top z.s. top treba da se zgolemi prvo pa potoa da se izvrsi linijata
               //a so top++ prvo se izvrsuva pa se zgolemuva
  }
  int pop(){//se trgna posledniot clen od stackot
    if(top<0)underflow();//se proveruva dali e prazen stackot uslovot isto moze da bide (top==-1)
    return s[top--];//se vraka clenot pa potoa se namaluva top
  }
  int peek() {//go gleda posledniot clen bez da se namali top
    if(top<0)underflow();
    return s[top];
  }
  bool iEmp() {
    return top==-1;
  }//proveruva dali e prazen stackot
  bool iFul() {
    return top==9;
  }//proveruva dali e poln stackot, funkcijava ne ja koristam ama spomnata e vo zadacata :)
};

void funk(stack og) {
  stack pom1,pom2;
  int n;
  pom1.init();
  pom2.init();
  while (!og.iEmp()) { //iEmp vrara false se dodeka ne se isprazni nizata
    n=og.pop();//se zema clen od og se stava vo n i n se stava vo pom1 i pom2
    pom1.push(n);
    pom2.push(n);
  }
  while (!pom2.iEmp()) {
    og.push(pom2.pop()); //z.s. so promenliva gi stavivme clenovite vo pom1 i pom2 clenovite imaat ist redosled
    // a ni treba vo edna da se naopaku, od pom2 se zemaat i stavaat vo og
  }
  //taka se bara vo zadacata istovremeno da se stavat vo dvete pomosni inace ima polesen nacin :)
  while (!pom1.iEmp()) { //se proveruva samo za eden stack z.s. imaat ist broj clenovi
    if ( (pom1.peek()+og.peek()) >=9 ) { //se proveruva dali zbirot e pogolem ili ednakov na 9 ako e se pecati samo 9 i
    //se trgaat clenovite od stackot
      cout<<9;
      pom1.pop();
      og.pop();
    }
    else { //se pecati zbirot na clenovite so pop za da se trgnat
      cout<<pom1.pop()+og.pop();
    }
  }
}

int main(){
  stack og;
  int n,n1;
  og.init(); //se inicijalizija og
  cout<<"daj broj gng(ne poishe od 10 cifri mame ti ebam sho ke ti se tolku cifri):"<<endl;
  cin>>n;
  while (n>0) { //gi zema broevite od kraj na brojot i gi stava vo og t.e. vo og se prevrteni broevite pr.
    //ako n e 123 vo og se 321
    n1=n%10;
    n=n/10;
    og.push(n1);
  }
  funk(og);
}