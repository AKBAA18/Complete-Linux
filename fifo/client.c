/***************************************************************************
 *                                                                         *
 *      Author          : Ganesh Naik                                      *
 *      Organisation    : Levana Technologies, Mumbai, India.              *
 *      Website		: www.levanatech.com                               *
 *                                                                         *
 *  Conducting Workshops on - Embedded Linux & Device Drivers Training.    *
 *  -------------------------------------------------------------------    *
 *  Tel : 91-9869260324, Email : info@levanatech.com                       *
 *                                                                         *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation. No warranty is attached; we cannot take *
 *   responsibility for errors or fitness for use.                         *
 ***************************************************************************/

# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

# define  	FIFO_FILE	"myfifo"

int main(int argc, char  *argv[])
{
	FILE	*fp;
	char	buff[1024];

	if(argc!=2){
		printf("usage fifo_client <string>\n");
		exit(0);
	}
	if((fp = fopen(FIFO_FILE,"w")) == NULL){
		printf("client: file open error\n");
		exit(1);
	}
	fputs(argv[1],fp);
	fclose(fp);
}

