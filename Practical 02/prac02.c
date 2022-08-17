#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(){
	struct stat stats;
    int fd,sz,lz;
    int sel = 1,a=1,k;
    char c1[30],c;
    
    char b[lz+1],*p,pat[] = "Kush";
    
    struct stat info;
    while(a){
         
        switch(sel){
            case 1:
            	printf("Create a file\n");
                fd = creat("f1.txt",0777);
                printf("fd = %d \n",fd);
                close(fd);
                break;
            case 2:
                fd = open("f1.txt", O_RDONLY | O_CREAT, 0777);
                printf("fd = %d \n",fd);
                close(fd);
                break;

            case 3:
                printf("Read contents of a file\n");
                printf("fd = %d \n",fd);
                close(fd);
                break;
            case 4:
                printf("Write to a file\n");            	
                fd = open("f1.txt", O_WRONLY | O_CREAT, 0777);
                write(fd,"Hello World!! Kush Here",strlen("Hello World!!\nKush Here"));
                printf("siz of file = %d \n",sz);
                close(fd);
                break;
            case 5:
                fd = open("f1.txt", O_RDONLY);
                sz = read(fd,c1,10);
                printf("siz of file = %d \n",sz);
                printf("fd = %d \n",fd);
                c1[sz] = '\0';
                printf("%s\n",c1);
                close(fd);
                break;
            case 6:
            	printf("Read contents of a file in a reverse order\n");
                fd = open("f1.txt", O_RDONLY);
                lz = lseek(fd,0,SEEK_END);
                printf("size is %d\n",lz);
                lseek(fd,-1,SEEK_CUR);
                printf("Printing in reverse order\n");
                while(lz!=0){
                	read(fd,&c,1);
                	printf("%c",c);
                	lseek(fd,-2,1);
                	lz--;
                }
                close(fd);
                break;
             case 7:
             	printf("Search the file to find the given pattern (Grep command)\n");
                fd = open("f1.txt", O_RDONLY);
                lz = lseek(fd,0,SEEK_END);
                lseek(fd,0,SEEK_SET);
                printf("size is %d\n",lz);
                read(fd,&b,lz);
                b[lz] = '\0';
                p = strstr(b,pat);
                if (p)
        		printf("String found\n");
    		 else
        		printf("String not found\n");
                close(fd);
                break;
             case 8:
             	printf("Delete a file\n");
             	 unlink("f1.txt");                
                break;
             case 9:
             	printf("To print file status using stat\n");    
		stat("a.c",&stats);
			    
		printf("\nFile access: ");
		if (stats.st_mode & R_OK)
			printf("read ");
		if (stats.st_mode & W_OK)
			printf("write ");
		if (stats.st_mode & X_OK)
			printf("execute");
				
		printf("\nFile size: %ld", stats.st_size);
		printf("\nBulk Size: %ld", stats.st_blksize);
		printf("\nBlocks: %ld", stats.st_blocks);
		printf("\nMode: %ld", stats.st_size);  

		    break;
             case  10: 
             	printf("To print file status using fstat\n");
             	fd = open("a.c", O_RDONLY);  
             	fstat(fd,&stats);
			    
		printf("\nFile access: ");
		if (stats.st_mode & R_OK)
			printf("read ");
		if (stats.st_mode & W_OK)
			printf("write ");
		if (stats.st_mode & X_OK)
			printf("execute");
				
		printf("\nFile size: %ld", stats.st_size);
		printf("\nBulk Size: %ld", stats.st_blksize);
		printf("\nBlocks: %ld", stats.st_blocks);
		printf("\nMode: %ld", stats.st_size);  

		    break;
	     case  11:
	     	printf("Exitting the code\n"); 
                exit(0);              
    
            }
            printf("\nPlease Enter your next choice\n");
    	    scanf("%d",&k);
            sel = k;
               
    }
    return 0;
}
