#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define mod 4294967297

int main() {
	
	long long int q, si, a, b;
	cin>>q>>si>>a>>b;
    
    unsigned int k = 1e8;

    bool t[k];
    cout<<k<<endl;
    cout<<sizeof(k)/sizeof(int)<<endl;
    
    // vector<bool> t(mod, 0);
    long long int sum = 0;	
    while( q-- ){
        
        if ( si % 2){
            
            int i = si>>1;
            
            if ( t[i] == 0){
                
                t[i] = 1;
                sum += i;
                
            }
            
        }
        
        else{
            
            int i = si/2;
            
            if ( t[i] == 1 ){
                
                t[i] = 0;
                sum -= i;
                
            }
            
        }
        
        si = (a*si+b) % (mod-1);
        
    }
    
    cout<<sum<<endl;
	
	return 0;
}
