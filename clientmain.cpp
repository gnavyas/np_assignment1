#include <unistd.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>
#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>




// Included to get the support library
// #include <calcLib.h>
using namespace std;

#define MAX 80 
#define PORT 8000
#define SA struct sockaddr 

#define ll           long long int
#define fast         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF          1e18
#define MOD          1000000007
#define Vi           vector<ll> 
#define Vs           vector<string>
#define VI           vector<vector<ll> >
#define PII          pair<ll,ll> 
#define PSI          pair<string,ll>
#define PB           push_back


int main(int argc, char *argv[])
{
 
	int buffLength = 1256;
	char recieve[buffLength], sendMsg[buffLength]; 
    struct sockaddr_in my_addr, my_addr1; 
    int client = socket(AF_INET, SOCK_STREAM, 0); 
    if (client < 0) 
    printf("Error in client creating\n"); 
    else
        printf("Client Created\n"); 
          
    my_addr.sin_family = AF_INET; 
    my_addr.sin_addr.s_addr = INADDR_ANY; 
    my_addr.sin_port = htons(PORT); 
    my_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    my_addr1.sin_family = AF_INET; 
    my_addr1.sin_addr.s_addr = INADDR_ANY; 
    my_addr1.sin_port = htons(PORT); 
    my_addr1.sin_addr.s_addr = inet_addr("127.0.0.1"); 
     
    if(bind(client, (struct sockaddr*) &my_addr1, sizeof(struct sockaddr_in)) == 0) 
    {
    	cout << "Bind Success\n";
    }
    else
    {
    	cout << "";
    }
      
    socklen_t addr_size = sizeof my_addr; 
    int con = connect(client, (struct sockaddr*) &my_addr, sizeof my_addr); 
    if (con == 0) 
    {
        printf("Connection Successful\n"); 
    }
    else
        printf("Error in Connection\n"); 

  
  	// start recieveing TCP version from the client
  	cout << "\nTCP Versions at Server\n";
    while(1)
    {
    	recv(client, recieve, buffLength, 0); 
    	printf("Server []: %s", recieve); 
    	if(recieve[0] == '\n')
    		break;
    }

    strcpy(sendMsg, "OK\n"); 
    send(client, sendMsg, buffLength, 0); 
    cout << "\n";
   	
	recv(client, recieve, buffLength, 0); 
	char showRecieve[100];
	for(int i=0;;i++)
	{
		if(recieve[i]=='\0')
		{
			showRecieve[i] = '\0';
			break;
		}
		else if(recieve[i]>='a' and recieve[i]<='z')
			showRecieve[i] = recieve[i]-32;
		else showRecieve[i] = recieve[i];
	}
	printf("Server Task [] : %s\n", showRecieve); 

	char str[1000];
	strcpy(str,recieve);

	vector<string> recievedOP;
	char* token = strtok(str, " "); 
    while (token != NULL) { 
        recievedOP.push_back(token);
        token = strtok(NULL, " "); 
    } 

    if( recievedOP[0][0] == 'f' )
    {
    	
    	float v1 = stof(recievedOP[1]);
    	float v2 = stof(recievedOP[2]);
    	float myAns;

    	if( recievedOP[0]=="fsub" )
    		myAns = v1-v2;

    	else if( recievedOP[0] == "fadd" )
    		myAns = v1+v2;
    	
    	else if( recievedOP[0]=="fdiv" )
    		myAns = v1/v2;

    	else myAns = v1*v2;

    	char myANSWER[100];
	    int j=0;
	    string ans = to_string(myAns);
	    for(int i=0;i<ans.length();i++)
	    	myANSWER[j++] = ans[i];
	    myANSWER[j] = '\0';
	    
	    strcpy(sendMsg, myANSWER); 
    	send(client, sendMsg, buffLength, 0); 
    }
    else{
    	
    	int v1 = stoi(recievedOP[1]);
    	int v2 = stoi(recievedOP[2]);
    	int myAns;

    	if( recievedOP[0]=="div" )
    		myAns = v1/v2;

    	else if( recievedOP[0] == "add" )
    		myAns = v1+v2;

    	else if( recievedOP[0]=="sub" )
    		myAns = v1-v2;
    	
    	else myAns = v1*v2;

    	char myANSWER[100];
	    int j=0;
	    string ans = to_string(myAns);
	    for(int i=0;i<ans.length();i++)
	    	myANSWER[j++] = ans[i];
	    myANSWER[j] = '\0';
	    
	    strcpy(sendMsg, myANSWER); 
    	send(client, sendMsg, buffLength, 0); 
    }

    recv(client, recieve, buffLength, 0); 
	printf("Server's RESPONSE []: %s\n", recieve); 
	    
	
    
    
    return 0; 
  

}
