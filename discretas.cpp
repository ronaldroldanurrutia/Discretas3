#include<iostream>

using namespace std;


class cesarcode{
    private:
        string codigo;
        int filas;
    public:
        cesarcode(string _codigo,int _filas=0){
            codigo = _codigo;
            this->filas = _filas;
        }
        void encriptar(void){
            int n = codigo.size();
            string parte1="";
            int n2=codigo.size()/(2*this->filas-2);
            int n3=n2*(2*this->filas-2),n4=2*(this->filas-1);
            int n5 = codigo.size()%n4;
            if(codigo.size() < n4 ){
                parte1+=codigo[0];
                for(int i=1;i<n5;i++){
                    parte1+=codigo[i];
                    if(n5 >= this->filas+i){
                        parte1+=codigo[this->filas-1+i];
                    }
                }
                codigo = parte1;
                return ;
            }
            for(int i=0;i<n3;i+=n4){
                parte1+=codigo[i];
            }
            if(n5>0){
                parte1+=codigo[codigo.size()-n5];
            }
            for(int i=1;i<this->filas-1;i++){
                int j=i;
                for(int k=0;k<n2;k++){
                    parte1+=codigo[j];
                    j+=2*(this->filas-1-i);
                    parte1+=codigo[j];
                    j+=(2*i);
                }
                if(n5>=2*this->filas-i-1){
                    parte1+=codigo[n4+i];
                    parte1+=codigo[n3+n4-i];
                }
                else{
                    if(n5>=i+1){
                        parte1+=codigo[n4+i];
                    }
                }
            }
            for(int i=2*this->filas-2;i<n3;i+=n4){
                parte1+=codigo[i];
            }
            if(n5>=((2*this->filas-2)/2+1)){
                parte1+=codigo[n4+this->filas-1];
            }
            codigo = parte1;
            return ;
        }
        void desencriptar(void){
            string elemento="";
            int arr[this->filas];
            int n1 = codigo.size()/(2*this->filas-2);
            int n2 = codigo.size()%(2*this->filas-2);
            arr[0]=0;
            if(n2 > 0){
                arr[1] = n1+1;
            }
            else{
                arr[1]=n1;
            }
            for(int i=1 ; i< this->filas-1;i++){
                if(n2 >= this->filas+i+1){
                    arr[i+1]= n1*2+arr[i]+2;
                }
                else{
                    if(n2 >= i+1){
                        arr[i+1]=n1*2+arr[i]+1;
                    }
                    else{
                        arr[i+1] = n1*2+arr[i];
                    }
                }
            }
            for(int i=0;i<n1;i++){
                for(int j=0;j<this->filas;j++){
                    elemento+=codigo[arr[j]];
                    arr[j]++;
                }
                for(int j=this->filas-2;j>0;j--){
                    elemento+=codigo[arr[j]];
                    arr[j]++;
                }
            }
            if(n2>((2*this->filas -2)/2 +1)){
               elemento+=codigo[arr[0]];
                for(int i=1;i<this->filas-1;i++){
                    elemento+=codigo[arr[i]];
                    arr[i]++;
                }
                elemento+=codigo[codigo.size()-1];
                for(int i=this->filas-2;i>0;i++){
                    elemento+=codigo[arr[i]];
                }
            }
            else{
                for(int i=0;i<n2;i++){
                    elemento+=codigo[arr[i]];
                }
            }


            codigo = elemento;


            return ;
        }
        string devolvercodigo(void){
            return codigo;
        }

};

int main(){
    /*string elemento4;
    cin>>elemento4;*/
    class cesarcode elemento("holamundocomoestas",5);
    elemento.encriptar();
    cout << elemento.devolvercodigo() << endl;
    elemento.desencriptar();
    cout << elemento.devolvercodigo() << endl;
    return 0;
}
