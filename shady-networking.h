/*
    This library is </> with <3 by @YasserCherfaoui.
*/

/*
    This function accepts a socket file descriptor and a pointer to the null terminated
    string to send. The function will make sure all the bytes of the 
    string are sent. Returns 1 on success and 0 on failure.
*/ 

int send_string(int sockfd, unsigned char *buffer){
    int sent_bytes, bytes_to_send;
    bytes_to_send = strlen(buffer);
    while (bytes_to_send > 0){
        sent_bytes = send(sockfd, buffer, bytes_to_send, 0);
        if (sent_bytes == -1)
            return 0; // you're in trouble x)
        bytes_to_send -= sent_bytes;
        buffer += sent_bytes;
    }
    return 1; // Congrats!
}

/*
    This funciton accepts a socket file descriptor and a pointer to a destionation
    buffer. It will receive from the scoket until the EOL byte sequence is seen.
    The EOL bytes are read from the socket, but the destination buffer is terminated before
    these bytes. It returns the size of the read line (without EOL bytes).
*/
int recv_line(int sockfd, unsigned char *dest_buffer) {
    #define EOL "\r\n" // End Of Line sequence
    #define EOL_SIZE 2
        unsigned char *ptr;
        int eol_matched = 0;

        ptr = dest_buffer;
        while(recv(sockfd, ptr, 1, 0) == 1){ // Read a single byte.
            if(*ptr == EOL[eol_matched]){ // is it a terminator ?
                eol_matched++;
                if(eol_matched == EOL_SIZE){ // is it a full terminator?
                    *(ptr+1-EOL_SIZE) = '\0'; // terminate the string.
                    return strlen(dest_buffer); // return bytes received
                }
            } else {
                eol_matched = 0;
            }
            ptr++; // point to the next byte of the buffer.
        }
        return 0; // There's no EOL characters.
}