#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>
#include<bits/stdc++.h>
#include<time.h>


// Included to get the support library
// #include <calcLib.h>



using namespace std;

#define MAX 80 
#define PORT 8000
#define SA struct sockaddr
#define RANDMAX 1000

#define ll           long long int
#define fast         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF          1e18
#define MOD          1000000007
#define Vi           vector<ll> 
#define Vs           vector<string>
#define VI           vector<vector<ll> >
#define PII          pair<ll,ll> 
#define PSI          pair<string,ll>#define PB           push_back


int main(int argc, char *argv[])
{

	int buffLength = 1256;
	char sendMsg[buffLength], recieve[buffLength]; 
    int server = socket(AF_INET, SOCK_STREAM, 0); 


    if (server < 0) 
    {
        printf("Error in server creating\n"); 
    }
    else
    {
        cout << "Server Created Successfully\n";
    }
          
    struct sockaddr_in my_addr, peer_addr; 
    my_addr.sin_family = AF_INET; 
    my_addr.sin_addr.s_addr = INADDR_ANY; 
    my_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
      
    my_addr.sin_port = htons(PORT); 
  
    if (bind(server, (struct sockaddr*) &my_addr, sizeof(my_addr)) == 0) 
    {
        cout << "Bind Success\n";
    }
    else
    {
        printf("Unable to bind\n"); 
    }
          
    if (listen(server, 3) == 0) 
    {
        printf("Listening for connections...\n"); 
    }
    else
    {
        printf("Unable to listen\n"); 
    }
      
    socklen_t addr_size; 
    addr_size = sizeof(struct sockaddr_in); 
    
    char *ip; 

    while (1) 
    { 
    	printf("Waiting for Clients  .....\n");
        int acc = accept(server, (struct sockaddr*) &peer_addr, &addr_size); 
        printf("Connection Established Successfully\n"); 

        char ip[INET_ADDRSTRLEN]; 
        inet_ntop(AF_INET, &(peer_addr.sin_addr), ip, INET_ADDRSTRLEN); 
      
       
        printf("CONNECTION INFO -> IP : %s :: PORT : %d\n",  ip, ntohs(peer_addr.sin_port)); 
  
  		char tcpVersions[4][50] = {"TEXT TCP 1.0\n", "TEXT TCP 1.1\n", "TEXT TCP 1.2\n","\n"}; 
  		for( int i=0;i<4;i++ )
  		{
  			strcpy(sendMsg, tcpVersions[i]); 
        	send(acc, sendMsg, buffLength, 0); 
  		}
  		recv(acc, recieve, buffLength, 0); 
        printf("Client : %s", recieve); 
        cout << "\n";


        vector<string> availableOps;
        availableOps.push_back("add");
        availableOps.push_back("fadd");
        availableOps.push_back("sub");
        availableOps.push_back("fsub");
        availableOps.push_back("div");
        availableOps.push_back("fdiv");
        availableOps.push_back("mul");
        availableOps.push_back("fmul");

        srand(time(0));
  			
        
        
    }  
    return 0; 


}

