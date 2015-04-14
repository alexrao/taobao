#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include "dprintf.h"
#include "config.h"

//-------------------------------------------------------------------------
// Function : main 
// Writer   : rxp 
// Time     : 2015-4-14 
// Feature  : main function 
// Input Key: 
// Return   : 
// Modify   : 
//-------------------------------------------------------------------------
void main(void)
{
	int i, j;
	unsigned int flag;
	int length, price_len;
	int price;
	FILE *fp_r, *fp_w;
	char path[256];
	char rbuf[1024];
	char wbuf[1024];
	char pri_buf[20];

	sprintf(path, "%s",CVS_FILE_PATH);

	fp_r = fopen(path, "rb");
	
	memset(path, 0, sizeof(path));
	sprintf(path, "new_%s",CVS_FILE_PATH);
	fp_w = fopen(path,"rw+");

	do
	{
		memset(rbuf, 0, sizeof(rbuf));
		memset(wbuf, 0, sizeof(wbuf));
		DPRINTF(1, " price=%d\n",length,price);

		fgets (rbuf, sizeof (path), fp_r);

		length = strlen (rbuf);
		DPRINTF(1, "len = %d price=%d\n",length,price);
		j = 0;
		flag = 0;
		for(i=0; i<length; i++)
		{
			if(rbuf[i] == ',' || rbuf[i] == ';')
			{
				if(rbuf[i] == ',')
				{
					memcpy(pri_buf,rbuf, i);
					price_len = i;
				}
				flag = i;
				wbuf[j++] = rbuf[i];
			}
			else if (rbuf[i] == ':')
			{
				flag = 0;
				if(flag != 0)
				{
					memcpy(wbuf+j,rbuf+flag+1, i-flag-1);
					j += i-flag-1;
					flag = 0;
				}
			}
			else if (rbuf[i] == '.')
			{
				if(flag != 0)
				{
					memcpy(wbuf+j,pri_buf, price_len);
					j += price_len;
					flag = 0;
				}
			}
			else if(rbuf[i] < '0' || rbuf[i] > '9')
			{
				if(flag != 0)
				{
					printf("flag len4 = %d\n",flag);

					//printf("i=%d, flag = %d", i, flag);
					memcpy(wbuf+j,rbuf+flag+1, i-flag-1);
					DPRINTF(1, "xxx j = %d\n", j);
					j += i-flag-1;
					flag = 0;
				}
			}
			
			if(flag == 0)
			{
				wbuf[j++] = rbuf[i];
			}

		}
		wbuf[j-2] = 0x0D;
		wbuf[j-1] = 0x0A;

		DPRINTF(1, "write len = %d\n",j);
		DPRINTF(3,"%s",wbuf);

		fwrite(wbuf, 1, j, fp_w);
		DPRINTF(3,"");
		DPRINTF(3,"");
	}while(length>0);

	fclose(fp_r);
	fclose(fp_w);

}
