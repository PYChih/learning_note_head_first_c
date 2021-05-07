# ch11_socket
###### tags: `HFC`
[TOC]
## overview
- [x] socket: bind, listen, accept, begin
- [x] recv and send
- [x] fork
- [x] client connect getaddrinfo()
## concept
- server and client
- telnet
    - address and port
        - port:
    - 127.0.0.1
    - `telnet 127.0.0.1 3000`
- protocol
    - IP internet protocol
    - HTTP
- socket
    - 新類型的資料串流
    ```
    #include <sys/socket.h>
    int listener_d = socket(PF_INET, SOCK_STREAM, 0);
    ```
## server client 
- BLAB: Bind, Listen, Accept, Begin
### Bind
- binding the port
```
#include <arpa/inet.h>
struct sockaddr_in name;
name.sin_family = PF_INET;
name.sin_port = (in_port_t)htons(3000);
name.sin_addr.s_addr = htonl(INADDR_ANY);
int c = bind(listener_d, (struct sockaddr *) &name, sizeof(name));
```
### Listen
```
if (listen(listener_d, 10) == -1) {
    error("Can't listen");
}
```
### Accept
```
struct sockaddr_storage client_addr;
unsigned int address_size = sizeof(client_addr);
int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
if (connect_d == -1) {
    error("Can't open secondary socket");
}

```
### Begin
- socket是雙向的
    - send
    - recv
## fork listen
## client side
- telnet to wiki
- getaddrinfo