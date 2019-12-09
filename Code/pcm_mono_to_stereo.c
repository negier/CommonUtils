#include <stdio.h>
void pcmMonoToStereo(const char*,const char*);
int main(){
	const char *pcmPath = "/home/duan/Desktop/mic_1575543513312.pcm";
	const char *newPcmPath = "/home/duan/Desktop/mic_new.pcm";
	pcmMonoToStereo(pcmPath,newPcmPath);
}
/*
 * 单声道的PCM转双声道
 */
void pcmMonoToStereo(const char* pcmPath,const char* newPcmPath){
	if(sizeof(char)!=1){
		printf("这只适用于char为8位的机器");
		return;
	}
	FILE* pcm;
	if((pcm =  fopen(pcmPath,"rb"))==NULL){
		printf("传入的pcm文件地址有误");
		return;
	}
	
	FILE* newPcm =  fopen(newPcmPath,"w");

        int p;
        int mark = 0;
	char left1,left2;
        while((p=fgetc(pcm))!=EOF){ // fgetc返回的是一个unsigned char，一个字节
		if(mark==2){
                 
		 	//复制值到另一个声道
			fwrite(&left1,sizeof(left1),1,newPcm);
 			fwrite(&left2,sizeof(left2),1,newPcm);

                        mark = 0;
                }
		if(mark==0){
			left1 = p;
		}else if(mark==1){
			left2 = p;
		}
		fwrite(&p,1,1,newPcm);
                mark++;
        }
	
	fclose(pcm);
	fclose(newPcm);
}
