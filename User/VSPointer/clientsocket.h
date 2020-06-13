#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <iostream>
#include "./VSPtr.h"
#include <sstream>
#include "../json.hpp"

using namespace std;

char buffer[200];
char ids[200];
char ptrs[200];
char values[200];

/**
 * @brief envia un error en dicho caso de que ocurra un problema con el cliente
 * 
 * @param msg mensaje de aviso de error para el usuario
 */
void error(const char *msg)
{
    perror(msg);
    exit(0);
}


/**
 * @brief lee el archivo .json que contiene los datos del servidor ingresados por el usuario
 * 
 * @return json que contiene la informacion del servidor ingresada por el usuario
 */
json readJson(){
    ifstream ifs("/home/stphn/Proyecto-I-Datos-II/Proyecto-I-Datos-II/User/UserData.json");
    json userData;
    ifs >> userData;
    return userData;
}

bool ifServer(){
    json userData = readJson();
    bool ifServer = userData["ifServer"];
    return ifServer;
}


/**
 * @brief obtiene el puerto ingresado por el usuario
 * 
 * @return int, numero del puerto por verificar
 */
int getPort(){
    json userData = readJson();         
    int port = userData["port"];
    return port; 
}

/**
 * @brief obtiene el nombre del servidor ingresado por el usuario
 * 
 * @return char*, nombre del servidor por verificar
 */
string getSName(){
    json userData = readJson();          
    string sName = userData["name"];  //Obtener ddel .json
    return sName;
}

/**
 * @brief obtiene la clave del servidor ingresada por el usuario
 * 
 * @return string, clave del servidor por verificar
 */
string getPassword(){
    json userData = readJson();         
    string pass = userData["password"];
    return pass;
}

/**
 * @brief guarda las identificaciones de los objetos VSPtr
 * 
 */
void sendIDs(){
    GarbageCollector *g = GarbageCollector::getInstance();

    for(int i = 0; i < VSPtrCount; i++ ){

        char a[200];
        a[sizeof(g->IDs[i])];
        std::copy(g->IDs[i].begin(), g->IDs[i].end(), a);
        strcat(ids, ",");

        if(i==0){
            strcpy(ids,a);
        }else{
            strcat(ids, a);
        }

    }
    cout << "IDS: [" << ids << "]" << endl;
}

/**
 * @brief guarda las direcciones en la memoria de los VSPtr
 * 
 */
void sendPtrs(){
    GarbageCollector *g = GarbageCollector::getInstance();

    for(int i = 0; i < VSPtrCount; i++ ){

        char a[200];
        a[sizeof(g->addess[i])];

        const void * address = static_cast<const void*>(g->addess[i]);
        std::stringstream ss;
        ss << address;  
        std::string ptr = ss.str(); 

        std::copy(ptr.begin(), ptr.end(), a);
        strcat(ptrs, ",");

        if(i==0){
            strcpy(ptrs,a);
        }else{
            strcat(ptrs, a);
        }

    }
    cout << "PTRs: [" << ptrs << "]" << endl;
}

/**
 * @brief guarda los valores de los VSPtr 
 * 
 */
void sendValues(){
    GarbageCollector *g = GarbageCollector::getInstance();

    for(int i = 0; i < VSPtrCount; i++ ){

        char a[100];
        string s = to_string(g->values[i]);

        std::copy(s.begin(), s.end(), a);   

        cout << a << endl;
        strcat(values, ",");

        if(i==0){
            strcpy(values,a);
        }else{
            strcat(values, a);
        }

    }

    cout << "VALUES: [" << values << "]" << endl;
}

/**
 * @brief inicializa el cliente y envia los datos de los objetos de tipo VSPtr creados por el usuario al servidor
 * 
 * @return int, estado del cliente
 */
int init_client()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr{};
    struct hostent *server;


    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(getPort() == 2000){                  //Verifica el puerto
        portno = 2000;
    }else{
        cout << "ERROR: PUERTO INVALIDO";
        close(sockfd);
        return 0;
    }

    if (sockfd < 0)
        error("ERROR opening socket");

    string sName = getSName();

    if(sName == "VSPtrServer"){                  //Verifica el nombre del host
        server = gethostbyname("1");
    }else {
        cout << "ERROR: NOMBRE INVALIDO";
        close(sockfd);
        return 0;
    }

    if(getPassword() == "pass"){
        cout << "*** datos verificados *** " << endl;
    }else{
        cout << "ERROR: CONSTRASEÑA INVALIDA";
        close(sockfd);
        return 0;
    }
    
    if (server == nullptr) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
        
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0){ 
        error("ERROR connecting");
    }

        sendIDs();
        n = write(sockfd, ids, sizeof(ids));

        if (n < 0)
            error("ERROR writing to socket");
        bzero(buffer, 256);

        sendPtrs();
        n = write(sockfd, ptrs, sizeof(ptrs));

        if (n < 0)
            error("ERROR writing to socket");
        bzero(buffer, 256);

        sendValues();
        n = write(sockfd, values, sizeof(values));

        if (n < 0)
            error("ERROR writing to socket");
        bzero(buffer, 256);

        n = read(sockfd, buffer, 255);
        if (n < 0)
            error("ERROR reading from socket");

        

}
void exec_client(){
    if(ifServer() == true){
            init_client();
    }
}

void end(){
        GarbageCollector *g = GarbageCollector::getInstance();
        g->sendData();
        exec_client();
    }