 # TFTP Client Implementation in C 
Auteurs: Nassim ANEMICHE, Kalai BALAKUMAR  

This project is a simple implementation of a **TFTP (Trivial File Transfer Protocol)** client in C. It demonstrates how to send a **Read Request (RRQ)** to a TFTP server to retrieve a file using sockets and the UDP protocol.

---
 ## 📋 **Project Structure** 
-  `quest1.c` : Enables to get the server's address and the name of the file
-  `quest2.c` : Enables to get the address IP
-  `quest3.c` Use a socket to communicate with the server.
- quest4:
- `gettftp.h`: Header file defining the `gettftp` function.
- `gettftp.c`: Contains the implementation of the `gettftp` function, which constructs and sends a TFTP RRQ.
- `main.c`: The main program that initializes the socket, resolves the server address, and calls the `gettftp` function.

---

 ##  **How It Works**

** 1. The program accepts two command-line arguments: ** 
   - The address or hostname of the TFTP server.
   - The name of the file to retrieve.

2. **Steps:**
   - Resolves the server's IP address using `getaddrinfo`.
   - Creates a UDP socket using `socket()`.
   - Constructs a TFTP RRQ packet in `gettftp.c` with:
     - Opcode for RRQ.
     - Filename to request.
     - Mode of transfer (`octet` for binary).
   - Sends the RRQ packet to the server using `sendto()`.

3. **Outputs the server information (hostname, file name, IP address) to the console.**

---

## **How to Compile and Run**

### **1. Compilation**

Use `gcc` to compile the program:
```bash
gcc main.c gettftp.c -o main

A

